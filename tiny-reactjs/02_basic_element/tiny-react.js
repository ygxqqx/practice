// component类，用来表示文本在渲染，更新，删除时应该做些什么事情
function ReactDOMTextComponent(text) {
	this._currentElement = '' + text; // 存下当前的字符串
	this._rootNodeID = null; // 用来标识当前component
};
// component渲染时生成的dom结构
ReactDOMTextComponent.prototype.mountComponent = function(rootID) {
	this._rootNodeID = rootID;
	return '<span data-reactid="' + rootID + '">' + this._currentElement + '</span>';
};

function ReactDOMComponent(element) {
	this._currentElement = element;
	this._rootNodeID = null;
}

ReactDOMComponent.prototype.mountComponent = function(rootID) {
	this._rootNodeID = rootID;
	var props = this._currentElement.props;
	
};

// component工厂  用来返回一个component实例
function instantiateReactComponent(node) {
	if (typeof node === 'string' || typeof node === 'number') {
		return new ReactDOMTextComponent(node);
	}
	if (typeof node === 'object' && typeof node.type === 'string') {
		return new ReactDOMComponent(node);
	}
}

function ReactElement(type, key, props) {
	this.type = type;
	this.key = key;
	this.props = props;
}

React = {
	nextReactRootIndex: 0,
	createElement: function(type, config, children) {
		var props = {};
		config = config || {};
		// 看有没有key，用来标识element的类型，方便以后高效的更新，这里可以先不管
		var key = config.key || null;
		for (var propName in config) {
			if (config.hasOwnProperty(propName) && propName !== 'key') {
				props[propName] = config[propName];
			}
		}
		// 处理children,全部挂载到props的children属性上
		// 支持两种写法，如果只有一个参数，直接赋值给children，否则做合并处理
		var childrenLength = arguments.length - 2;
		if (childrenLength === 1) {
			props.children = Array.isArray(children) ? children : [children];
		} else if (childrenLength > 1) {
			var childArray = Array(childrenLength);
			for (var i = 0; i < childrenLength; ++i) {
				childArray[i] = arguments[i + 2];
			}
			props.children = childArray;
		}
		return new ReactElement(type, key, props);
	},
	render: function(element, container) {
		var componentInstance = instantiateReactComponent(element);
		var markup = componentInstance.mountComponent(React.nextReactRootIndex++);
		$(container).html(markup);
		// 触发完成mount的事件
		$(document).trigger('mountReady');
	}
}



