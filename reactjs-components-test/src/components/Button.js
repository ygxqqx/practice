import React, { Component } from 'react';


class Button extends Component {

	constructor(props) {
		super(props);
		this.state = {

		};
		this.handerClick = this.handerClick.bind(this);
	}

	render() {

		return (
			<input type="button" value={this.props.children} onClick={this.handerClick} />
		)
	}
	handerClick(e) {
		// e.preventDefault();
		let val = e.target.value;
		this.props.updateDate(val);
	}
}

export default Button;
