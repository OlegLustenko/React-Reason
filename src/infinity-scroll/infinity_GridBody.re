/* let component = ReasonReact.reducerComponent "GridBody"; */
type state = {
  shouldUpdate: bool,
  total: int,
  displayStart: int,
  displayEnd: int
};

type actions =
  | NewPosition(int, int)
  | ShouldUpdateFalse;

let reducer = (action, state) =>
  switch action {
  | NewPosition(displayStart, displayEnd) =>
    ReasonReact.Update({...state, displayStart, displayEnd})
  | ShouldUpdateFalse => ReasonReact.Update({...state, shouldUpdate: false})
  };

let initialState = () => {shouldUpdate: false, total: 0, displayStart: 0, displayEnd: 0};

let retainedProps = {};

let willReceiveProps = (nextProps) => "OK";

let generateRow = [];

let make = (~visibleStart, ~visibleEnd, ~total, ~recordHeight, _children) => {
  ...ReasonReact.reducerComponent("Infinity_GridBody"),
  initialState,
  reducer,
  render: ({state}) => {
    let rows = [];
    <div> (ReasonReact.stringToElement("OK")) </div>
  }
};
