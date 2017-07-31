let component = ReasonReact.statelessComponent "Exercise4";

let se = ReasonReact.stringToElement;

type oneCart = {
  name:string,
  qty:int,
  freeQty:int
};

let cart = [
  { name: "Lemon", qty:1, freeQty:0 }
  , { name : "Apple", qty : 5, freeQty : 0 }
  , { name : "Pear", qty : 10, freeQty : 0 }
];

let make _children => {
  ...component,
  render: fun self => {
    <div>
    <h1>(se "Hi from exercise 4")</h1>
    <ul>
    (
      ReasonReact.arrayToElement (
      Array.of_list (
        List.mapi (fun index cartItem => {
          <li>
            <div>(se cartItem.name)</div>
            <div>(cartItem.qty |> string_of_int |> se)</div>
            <div>(cartItem.freeQty |> string_of_int |> se)</div>
          </li>
        }) cart)
      )
    )
    </ul>
    </div>
  }
}