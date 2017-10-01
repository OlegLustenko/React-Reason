type actions =
  | Dialog bool
  | INCREMENT
  | DECREMENT;

type state = {
  counter: int,
  dialog: bool
};

let inc _ => INCREMENT;

let dec _ => DECREMENT;

let reducer action state =>
  switch action {
  | INCREMENT => ReasonReact.Update {...state, counter: state.counter + 1}
  | DECREMENT => ReasonReact.Update {...state, counter: state.counter - 1}
  | Dialog show => ReasonReact.Update {...state, dialog: show}
  };

let component = ReasonReact.reducerComponent "Counter";

let initialState () => {counter: 0, dialog: false};

let se = ReasonReact.stringToElement;

let make _children => {
  ...component,
  initialState,
  reducer,
  render: fun {state, reduce} =>
    <div>
      <span> (se (string_of_int state.counter)) </span>
      <button onClick=(reduce inc)> (se "INCREMENT") </button>
      <button onClick=(reduce dec)> (se "DECREMENT") </button>
    </div>
};