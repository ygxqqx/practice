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

// component工厂  用来返回一个component实例
function instantiateReactComponent(node) {
    if (typeof node == 'string' || typeof node == 'number') {
        return new ReactDOMTextComponent(node);
    }
    if (typeof node == 'object' || typeof node.type == 'string') {

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
    },
    render: function(element, container) {
        let componentInstance = instantiateReactComponent(element);
        let markup = componentInstance.mountComponent(React.nextReactRootIndex++);
        $(container).html(markup);
        // 触发完成mount的事件
        $(document).trigger('mountReady');
    }
};
