let component = ReasonReact.statelessComponent "Elm";

let se = ReasonReact.stringToElement;

type exer2Data = {
  shortName: string,
  longName: string
};

let exercise2Data: exer2Data = {shortName: "Oleg .L", longName: "Ivanov Ivan Ivanovich"};

let make _children => {
  ...component,
  render: fun _self =>
    <ul>
      ("1: " |> se)
      <Exercise1 />
      <hr />
      ("2: " |> se)
      <Exercise2 name=exercise2Data.shortName />
      <Exercise2 name=exercise2Data.longName />
      <hr />
      ("3: " |> se)
      <Exercise3 />
      <Exercise4 />
      <Login />
      <AuthApp />
    </ul>
};