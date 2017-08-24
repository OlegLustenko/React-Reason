type state = {counter: int};
let component = ReasonReact.statefulComponent "Login";

let se = ReasonReact.stringToElement;

let click _event {ReasonReact.state: state} =>
  ReasonReact.Update {counter: state.counter + 1};


let make _children => {
  ...component,
  initialState: fun () => {counter: 0},
  render: fun self => {
    let greeting =
      "Hello " ^ ". You've clicked the button " ^ string_of_int self.state.counter ^ " time(s)!";
    <button onClick=(self.update click)> (ReasonReact.stringToElement greeting) </button>
  }
};