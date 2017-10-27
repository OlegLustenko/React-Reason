let component = ReasonReact.statelessComponent("Test");

let make = (_children) => {
  ...component,
  render: (_self) => <h1> (ReasonReact.stringToElement("Hello Test")) </h1>
};
