type tabs =
  | Elm
  /* | Homeworks */
  | Experiments
  | Auth;

type state = {activeTab: ReasonReact.reactElement};

let initialState () => {activeTab: <Elm />};

let styles = ReactDOMRe.Style.make fontSize::"2rem" listStyle::"none" border::"2px solid #000" ();

let reducer action _state =>
  switch action {
  | Elm => ReasonReact.Update {activeTab: <Elm />}
  /* | Homeworks => ReasonReact.Update {...state, activeTab: <Homework1 />} */
  | Experiments => ReasonReact.Update {activeTab: ReasonReact.nullElement}
  | Auth => ReasonReact.Update {activeTab: <Login />}
  };

let component = ReasonReact.reducerComponent "Tabs";

let se = ReasonReact.stringToElement;

let make _children => {
  ...component,
  initialState,
  reducer,
  render: fun {state, reduce} =>
    <main>
      <nav>
        <ul style=styles>
          <li> <a onClick=(reduce (fun _ => Elm))> (se "Elm") </a> </li>
          <li> <a onClick=(reduce (fun _ => Experiments))> (se "Experiments") </a> </li>
          <li> <a onClick=(reduce (fun _ => Auth))> (se "Auth") </a> </li>
        </ul>
      </nav>
      state.activeTab
    </main>
};