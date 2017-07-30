include Html;

let component = ReasonReact.statelessComponent "Exercise1";

  let myName: string = "Oleg";
 
let handleClick _event _self => Js.log "clicked!";

let make _children => {
    ...component,
  render: fun self => 
    <section>
      <div>(Html.text myName)</div>
    </section> 
};