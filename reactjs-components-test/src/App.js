import React, { Component } from 'react';
import './App.css';
import SelectList from "./components/SelectList";
import Button from "./components/Button";
import Tab from "./components/Tab";

class App extends Component {

    constructor(props) {
        super(props);
        this.state = {
            selectMap: []
        };
        this.updateDate = this.updateDate.bind(this);
    }

    render() {

        return (
            <div className="App">
                <div>
                    <Button updateDate={this.updateDate}>Click Me</Button>
                    <SelectList selectMap={this.state.selectMap}/>
                </div>
                <div>
                    <Tab />
                </div>
            </div>
        );
    }
    updateDate(val) {

        const selectMap = [
            {uiValue: "AAAA", value: "8987"},
            {uiValue: "DFSDF", value: "3323"},
            {uiValue: "FGFG", value: "6767"},
            {uiValue: "VBVBF", value: "4533"}
        ];
        if (val) {
            this.setState({
                selectMap: selectMap
            });
        }
    }
}

export default App;
