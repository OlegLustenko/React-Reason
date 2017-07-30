open Html;
open Utils; 

type t = string;
let (*=) firstString secondString => firstString.[0] == secondString.[0];
let (>>) = fun f g x => g(f x);
let component = ReasonReact.statelessComponent "Exercise3";


Js.log(Utils.split_by keep_empty::false (fun x => x == ' ') "S W X A");

/* type wordWrap: string =>  */
let wordWrap = Utils.split_by (fun x => x == ' ') >> List.length;


Js.log(String.blit "OK");

let sentenceToWrap = 
  "Learning ReasonML, make me feel better";

let make _children => {
  ...component,
  render: fun self => {
    <div>
      <h4>(Html.text ("DA" *= "DSSS" ? "OK" : "FALSE"))</h4>
      <h4>(Html.text ("Word-counter: " ^ string_of_int (wordWrap sentenceToWrap)))</h4>
    </div>
  }
};

