open Html;

let (*=) firstString secondString => firstString.[0] == secondString.[0];
let component = ReasonReact.statelessComponent "Exercise3";

let wordCount word => List.length 

let make _children => {
  ...component,
  render: fun self => {
    <h4>(Html.text ("DA" *= "DSSS" ? "OK" : "FALSE"))</h4>
  }
};

