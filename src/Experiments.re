let component = ReasonReact.statelessComponent "Main";

let make _children => {
  ...component,
  render: fun _self => <h1> (ReasonReact.stringToElement "OK") </h1>
};

module Tasks = {
  type quota = list int;
  let fizzBuzz num =>
    switch num {
    | _ when num mod 3 == 0 && num mod 5 == 0 => "FizzBuzz"
    | _ when num mod 3 == 0 => "Fizz"
    | _ when num mod 5 == 0 => "Buzz"
    | _ => string_of_int num
    };
  let fizzBuzzLoop quota => List.iter (fun item => Js.log (fizzBuzz item)) quota;
};

type range = int => int;

let add a b => a + b;

let range x y => {
  let arr = [||];
  /* let arr_l = []; */
  for num in x to y {
    /* List.concat [num] arr_l; */
    Js.Array.push num arr
  };
  arr
};

/* let rangeL x y => {
  let arr = [];
  
  Js.Array.from(y) |>

}; */

Tasks.fizzBuzzLoop (Array.to_list (range 1 100));
/* List.; */
/* Tasks.fizzBuzzLoop ; */