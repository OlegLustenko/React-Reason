type se = string => ReasonReact.reactElement;
type oneCart = {
  name: string,
  qty: int,
  freeQty: int
};
let component = ReasonReact.statelessComponent "Exercise4";
let se = ReasonReact.stringToElement;

let (>>) f g x => g (f x);


/* type cartList = list oneCart; */
let cart = [
  {name: "Lemon", qty: 1, freeQty: 0},
  {name: "Apple", qty: 5, freeQty: 0},
  {name: "Pear", qty: 10, freeQty: 0}
];

let calculateFreeQty oneCart :oneCart =>
  switch oneCart.qty {
  | _ when oneCart.qty <= 5 => {...oneCart, freeQty: 1}
  | _ when oneCart.qty >=10 => {...oneCart, freeQty: 5}
  | _ => oneCart
  };

let make _children => {
  ...component,
  render: fun _self =>
    <div>
      <h1> (se "Hi from exercise 4") </h1>
      <ul>
        (
          cart |>
          List.mapi (
            fun _ cartItem => {
              let cartItem = calculateFreeQty cartItem;
              <li key=cartItem.name>
                <div> (se ("NAME " ^ cartItem.name)) </div>
                <div> (se "QTY: ") (cartItem.qty |> string_of_int |> se) </div>
                <div> (se "freeQty: ") (cartItem.freeQty |> string_of_int |> se) </div>
              </li>
            }
          ) |> Array.of_list |> ReasonReact.arrayToElement
        )
      </ul>
    </div>
};