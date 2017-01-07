import React, { Component } from 'react';
import { Tab, Tabs, TabList, TabPanel } from 'react-tabs';


class TabDemo extends Component {

	constructor(props) {
		super(props);
		this.state = {

		};
	}

	render() {

		return (
			<div>
				<Tabs>
					<TabList>
						<Tab>Foo</Tab>
						<Tab>Bar</Tab>
						<Tab>Baz</Tab>
					</TabList>
					<TabPanel>
						<h2>Hello from Foo</h2>
					</TabPanel>
					<TabPanel>
						<h2>ssssss from Foo</h2>
					</TabPanel>
					<TabPanel>
						<h2>fffff from Foo</h2>
					</TabPanel>
				</Tabs>
			</div>
		)
	}
}

export default TabDemo;
