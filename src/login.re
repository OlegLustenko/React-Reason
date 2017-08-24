type state = {counter: int};

let component = ReasonReact.statefulComponent "Login";

let se = ReasonReact.stringToElement;

let click _event {ReasonReact.state: {counter}} => ReasonReact.Update {counter: counter + 1};

let make _children => {
  ...component,
  initialState: fun () => {counter: 0},
  render: fun {update, state} => {
    let greeting =
      "Hello " ^ ". You've clicked the button " ^ string_of_int state.counter ^ " time(s)!";
    <button onClick=(update click)> (ReasonReact.stringToElement greeting) </button>
  }
};