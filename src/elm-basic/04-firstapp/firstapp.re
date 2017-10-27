[%bs.raw {|require('./firstapp.scss')|}];

/* Main */
type calorieState = {
  counter: int,
  inputValue: int,
  error: string
};

type appState =
  | AddCalorie
  | UpdateInput(string)
  | UpdateCalorieInput
  | Clear;

let initialState = () => {counter: 0, inputValue: 0, error: ""};

/* Events */
let reducer = (action, state) =>
  switch action {
  | AddCalorie => ReasonReact.Update({...state, counter: state.counter + 1})
  | UpdateInput(inputChar) =>
    switch (int_of_string(inputChar)) {
    | exception (Failure(_)) => ReasonReact.Update({...state, error: "err ! please enter numbers"})
    | _ => ReasonReact.Update({...state, inputValue: int_of_string(inputChar)})
    }
  | UpdateCalorieInput =>
    ReasonReact.Update({...state, counter: state.counter + state.inputValue, inputValue: 0})
  | Clear => ReasonReact.Update({...state, counter: 0})
  };

let updateInput = (event) => {
  let target = event |> ReactEventRe.Form.target |> ReactDOMRe.domElementToObj;
  UpdateInput(target##value)
};

let updateCaloriesInput = (_) => UpdateCalorieInput;

let component = ReasonReact.reducerComponent("Firstapp");

let styles = ReactDOMRe.Style.make(~fontSize="2rem", ());

let make = (_children) => {
  ...component,
  initialState,
  reducer,
  render: ({state, reduce}) => {
    let totalCalorie =
      ReasonReact.stringToElement("Total Calorie: " ++ string_of_int(state.counter));
    <div style=styles>
      <h1> (ReasonReact.stringToElement("Calorie App")) </h1>
      <h3> totalCalorie </h3>
      <input _type="text" onChange=(reduce(updateInput)) value=(string_of_int(state.inputValue)) />
      <h4> (ReasonReact.stringToElement(state.error)) </h4>
      <button onClick=(reduce(updateCaloriesInput))>
        (ReasonReact.stringToElement("Add calories from input"))
      </button>
      <div>
        <button onClick=(reduce((_) => AddCalorie))>
          (ReasonReact.stringToElement("Add calorie + 1"))
        </button>
        <button onClick=(reduce((_) => Clear))> (ReasonReact.stringToElement("clear")) </button>
      </div>
    </div>
  }
};
