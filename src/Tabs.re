[%bs.raw {|require('./Tabs.scss')|}];

type tabs =
  | Elm
  | Homeworks
  | Experiments
  | Auth
  | CalorieApp;

type state = {activeTab: ReasonReact.reactElement};

let initialState () => {activeTab: <Elm />};

let styles = ReactDOMRe.Style.make fontSize::"2rem" listStyle::"none" border::"2px solid #000" ();

let reducer action _state =>
  switch action {
  | Elm => ReasonReact.Update {activeTab: <Elm />}
  | Homeworks => ReasonReact.Update {activeTab: ReasonReact.nullElement}
  | Experiments => ReasonReact.Update {activeTab: <Experiments />}
  | Auth => ReasonReact.Update {activeTab: <Login />}
  | CalorieApp => ReasonReact.Update {activeTab: <Firstapp />}
  };

let component = ReasonReact.reducerComponent "Tabs";

let se = ReasonReact.stringToElement;

let make children => {
  ...component,
  initialState,
  reducer,
  render: fun {state, reduce} =>
    <main>
      <nav>
        <ul className="header">
          <li className="header-item"> <a onClick=(reduce (fun _ => Elm))> (se "Elm") </a> </li>
          <li className="header-item">
            <a onClick=(reduce (fun _ => Experiments))> (se "Experiments") </a>
          </li>
          <li className="header-item"> <a onClick=(reduce (fun _ => Auth))> (se "Auth") </a> </li>
          <li className="header-item"> <a onClick=(reduce (fun _ => CalorieApp))> (se "Calorie") </a> </li>
        </ul>
      </nav>
      (ReasonReact.arrayToElement children)
      state.activeTab
    </main>
};