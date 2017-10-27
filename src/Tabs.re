[%bs.raw {|require('./Tabs.scss')|}];

type tabs =
  | Elm
  | Homeworks
  | Experiments
  | Auth
  | InfinityApp
  | CalorieApp;

type state = {activeTab: ReasonReact.reactElement};

let initialState = () => {activeTab: <Infinity_App />};

let styles =
  ReactDOMRe.Style.make(~fontSize="2rem", ~listStyle="none", ~border="2px solid #000", ());

let reducer = (action, _state) =>
  switch action {
  | Elm => ReasonReact.Update({activeTab: <Elm />})
  | InfinityApp => ReasonReact.Update({activeTab: <Infinity_App />})
  | Homeworks => ReasonReact.Update({activeTab: ReasonReact.nullElement})
  | Experiments => ReasonReact.Update({activeTab: <Experiments />})
  | Auth => ReasonReact.Update({activeTab: <Login />})
  | CalorieApp => ReasonReact.Update({activeTab: <Firstapp />})
  };

let component = ReasonReact.reducerComponent("Tabs");

let se = ReasonReact.stringToElement;

let make = (children) => {
  ...component,
  initialState,
  reducer,
  render: ({state, reduce}) =>
    <main>
      <nav>
        <ul className="header">
          <li className="header-item"> <a onClick=(reduce((_) => Elm))> (se("Elm")) </a> </li>
          <li className="header-item">
            <a onClick=(reduce((_) => Experiments))> (se("Experiments")) </a>
          </li>
          <li className="header-item"> <a onClick=(reduce((_) => Auth))> (se("Auth")) </a> </li>
          <li className="header-item">
            <a onClick=(reduce((_) => CalorieApp))> (se("Calorie")) </a>
          </li>
        </ul>
      </nav>
      (ReasonReact.arrayToElement(children))
      state.activeTab
    </main>
};