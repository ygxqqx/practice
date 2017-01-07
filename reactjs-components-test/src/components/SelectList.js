import React, { Component } from 'react';
// import $ from "jquery";


class SelectList extends Component {

	constructor(props) {
		super(props);
		// const selectMap = [
		// 	{uiValue: "aaaa", value: "1232"},
		// 	{uiValue: "bbbb", value: "1111"},
		// 	{uiValue: "cccc", value: "3333"},
		// 	{uiValue: "dddd", value: "7777"},
		// 	{uiValue: "eeee", value: "9999"}
		// ];
		this.state = {
			selectMap: this.props.selectMap
		};
		this.handleSelectchange = this.handleSelectchange.bind(this);
	}

	componentWillReceiveProps(nextProps) {
		this.setState({
			selectMap: nextProps.selectMap
		});
	}

	render() {

		return (
			<div>
				<select onChange={this.handleSelectchange}>
					<option style={{display: "none"}}>请选择...</option>
					{
						this.state.selectMap.map((optionItem, index) => {
							return (
								<option key={optionItem.uiValue}>{optionItem.uiValue}</option>
							);
						})
					}
				</select>
			</div>
		);
	}

	handleSelectchange(e) {
		// let selectTarget = $(e.currentTarget);
		e.preventDefault();
		console.log(e.target.value);
		// console.log(e.target.getAttribute("")); // 
	}
}

export default SelectList;
