open Types;

open Bs_fetch;
type state = {counter: int};

let component = ReasonReact.statefulComponent "Login";

let se = ReasonReact.stringToElement;

let click _event {ReasonReact.state: {counter}} => ReasonReact.Update {counter: counter + 1};

let url = "http://api.jyotish.gift/api/v1/auth/login";

type options = {
  method: string,
  mode: string,
  body: Js.Json.t
};

let body = {user: "sa", password: "admin"};

/* let fetchOptions = {method: "POST", mode: "cors", body: Js.Json.stringify body}; */
Js.Promise.(fetch url |> then_ Response.json |> then_ (fun json => Js.log json |> resolve));

let make _children => {
  ...component,
  initialState: fun () => {counter: 0},
  render: fun {update, state} => {
    let greeting =
      "Hello " ^ ". You've clicked the button2  " ^ string_of_int state.counter ^ " time(s)!";
    <button onClick=(update click)> (ReasonReact.stringToElement greeting) </button>
  }
};