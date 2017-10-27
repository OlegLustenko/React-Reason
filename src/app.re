let component = ReasonReact.statelessComponent("App");

let handleClick = (_event, _self) => Js.log("clicked2333! 2");

let make = (~message, _children) => {
  ...component,
  render: (self) => {
    let something = " _ ) " ++ message;
    <main onClick=(self.handle(handleClick))> <Tabs> <Counter /> </Tabs> </main>
  }
};