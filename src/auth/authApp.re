type state = {counter: int};

let component = ReasonReact.statefulComponent("AuthApp");

let se = ReasonReact.stringToElement;

let make = (_children) => {
  ...component,
  initialState: () => {counter: 0},
  render: (self) => <h1> (se("Auth App" ++ string_of_int(self.state.counter))) </h1>
};
