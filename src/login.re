open Types;

open Bs_fetch;

type state = {counter: int};

type actions =
  | Increment
  | Decrement;

let se = ReasonReact.stringToElement;

let url = "http://api.jyotish.gift/api/v1/auth/login";

let component = ReasonReact.reducerComponent("Login");

let click = (_event, {ReasonReact.state: {counter}}) => ReasonReact.Update({counter: counter + 1});

type options = {
  method: string,
  mode: string,
  body: Js.Json.t
};

let body = {user: "sa", password: "admin"};

/* let fetchOptions = {method: "POST", mode: "cors", body: Js.Json.stringify body}; */
Js.Promise.(fetch(url) |> then_(Response.json) |> then_((json) => Js.log(json) |> resolve));

let make = (_children) => {
  ...component,
  initialState: () => {counter: 0},
  reducer: (action, state) =>
    switch action {
    | Increment => ReasonReact.Update({counter: state.counter + 1})
    | Decrement => ReasonReact.Update({counter: state.counter - 10})
    },
  render: ({reduce, state}) => {
    let greeting =
      "Hello "
      ++ (". You've clicked the button2  " ++ (string_of_int(state.counter) ++ " time(s)!"));
    <button onClick=(reduce((_) => Decrement))> (ReasonReact.stringToElement(greeting)) </button>
  }
};