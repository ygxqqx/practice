// 后续可以分模块编写(每个功能一个模块，每个模块分为一个文件) 用 webpack 打包生成一个文件即可

// component类，用来表示文本在渲染，更新，删除时应该做些什么事情
function ReactDOMTextComponent(text) {
    // 存下当前的字符串
    this._currentElement = '' + text;
    // 用来标识当前component
    this._rootNodeID = null;
}

// component渲染时生成的dom结构
ReactDOMTextComponent.prototype.mountComponent = function(rootID) {
    this._rootNodeID = rootID;
    return '<span data-reactid="' + rootID + '">' + this._currentElement + '</span>';
};

// component类，用来表示文本在渲染，更新，删除时应该做些什么事情
function ReactDOMComponent(element) {
    // 存下当前的element对象引用
    this._currentElement = element;
    this._rootNodeID = null;
}

// component渲染时生成的dom结构
ReactDOMComponent.prototype.mountComponent(rootID) {
    // 赋值标识
    this._rootNodeID = rootID;
    let props = this._currentElement.props;
    let tagOpen = '<' + this._currentElement.type;
    let tagClose = '</' + this._currentElement.type + '>';
    // 加上reactid标识
    tagOpen += ' data-reactid=' + this._rootNodeID;
    // 拼凑出属性
    for (let propKey in props) {
        // 这里要做一下事件的监听，就是从属性props里面解析拿出on开头的事件属性的对应事件监听
        if (/^on[A-Za-z]/.test(propKey)) {
            let eventType = propKey.replace('on', '');
            // 针对当前的节点添加事件代理,以_rootNodeID为命名空间
            $(document).delegate('[data-reactid="' + this._rootNodeID + '"]', eventType + '.' + this._rootNodeID, props[propKey]);
        }
        // 对于children属性以及事件监听的属性不需要进行字符串拼接
        // 事件会代理到全局。这边不能拼到dom上不然会产生原生的事件监听
        if (props[propKey] && propKey != 'children' && !/^on[A-Za-z]/.test(propKey)) {
            tagOpen += ' ' + propKey + '=' + props[propKey];
        }
    }
    // 获取子节点渲染出的内容
    let content = '';
    let children = props.children || [];
    let childrenInstances = []; // 用于保存所有的子节点的componet实例，以后会用到
    let that = this;
    for (let key in children) {
        if (children.hasOwnProperty(key)) {
            let child = children[key];
            // 这里再次调用了instantiateReactComponent实例化子节点component类，拼接好返回
            let childComponentInstance = instantiateReactComponent(child);
            childComponentInstance._mountIndex = key;

            childrenInstances.push(childComponentInstance);
            // 子节点的rootId是父节点的rootId加上新的key也就是顺序的值拼成的新值
            let curRootId = that._rootNodeID + '.' + key;
            // 得到子节点的渲染内容
            let childMarkup = childComponentInstance.mountComponent(curRootId);
            // 拼接在一起
            content += ' ' + childMarkup;
        }
    }

    // 留给以后更新时用的这边先不用管
    this._renderedChildren = childrenInstances;

    // 拼出整个html内容
    return tagOpen + '>' + content + tagClose;
}


// component工厂  用来返回一个component实例
function instantiateReactComponent(node) {
    // 文本节点的情况
    if (typeof node == 'string' || typeof node == 'number') {
        return new ReactDOMTextComponent(node);
    }
    // 浏览器默认节点的情况
    if (typeof node == 'object' && typeof node.type == 'string') {
        // 注意这里，使用了一种新的component
        return new ReactDOMComponent(node);
    }
}

// ReactElement就是虚拟dom的概念，具有一个type属性代表当前的节点类型，还有节点的属性props
// 比如对于div这样的节点type就是div，props就是那些attributes
// 另外这里的key,可以用来标识这个element，用于优化以后的更新，这里可以先不管，知道有这么个东西就好了
function ReactElement(type, key, props) {
    this.type = type;
    this.key = key;
    this.props = props;
}

React = {
    nextReactRootIndex: 0,
    createElement: function(type, config, children) {
        let props = {};
        config = config || {};
        // 看有没有key，用来标识element的类型，方便以后高效的更新
        let key = config.key || null;
        // 复制config里的内容到props
        for (let propName in config) {
            if (config.hasOwnProperty(propName) && propName != 'key') {
                props[propName] = config[propName];
            }
        }
        // 处理children, 全部挂载到props的children属性上
        // 支持两种写法，如果只有一个参数，直接赋值给children，否则做合并处理
        let childrenLength = arguments.length - 2;
        if (childrenLength == 1) {
            props.children = $.isArray(children) ? children : [children];
        } else if (childrenLength > 1) {
            let childArray = Array(childrenLength); // 创建长度为 childrenLength 的空数组
            for (let i = 0; i < childrenLength; ++i) {
                childArray[i] = arguments[childArray + 2];
            }
            props.children = childArray;
        }
        return new ReactElement(type, key, props);
    },
    render: function(element, container) {
        let componentInstance = instantiateReactComponent(element);
        let markup = componentInstance.mountComponent(React.nextReactRootIndex++);
        $(container).html(markup);
        // 触发完成mount的事件
        $(document).trigger('mountReady');
    }
};
