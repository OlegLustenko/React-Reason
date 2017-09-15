let component = ReasonReact.statelessComponent "App";

let handleClick _event _self => Js.log "clicked2333! 2";

let make ::message _children => {
  ...component,
  render: fun self => {
    let something = " _ ) " ^ message;
    <div onClick=(self.handle handleClick)>
      (ReasonReact.stringToElement something)
      <Elm />
      (ReasonReact.stringToElement "Counter:") <Counter />
    </div>
  }
};