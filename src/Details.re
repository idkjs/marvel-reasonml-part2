let component = ReasonReact.statelessComponent("Details");

let str = ReasonReact.string;

let make = (_children) => {...component, render: (_self) => <div> (str("Details")) </div>};