/* Working with lists

   1. Write a function last : 'a list -> 'a option that returns the last element of a list. (easy) */
/* # last [ "a" ; "b" ; "c" ; "d" ];;
   - : string option = Some "d"
   # last [];;
   - : 'a option = None */
module First = {
  let last arr =>
    switch (List.length arr) {
    | 0 => None
    | 1 => Some (List.hd arr)
    | _ => Some (arr |> List.rev |> List.hd)
    };
  let solution () => {
    Js.log (last ["a", "b", "c", "d"]);
    Js.log (last ["a", "b", "c", "z"]);
    Js.log (last [])
  };
  solution ();
};

/* 2. Find the last but one (last and penultimate) elements of a list. (easy)

   Solution

   # last_two [ "a" ; "b" ; "c" ; "d" ];;
   - : (string * string) option = Some ("c", "d")
   # last_two [ "a" ];;
   - : (string * string) option = None */
module Second = {
  let last_two arr =>
    switch arr {
    | [hd, nd, ...tail] => Some (hd, nd)
    | [_]
    | [] => None
    };
  let solution () => {
    Js.log (last_two ["a", "b", "c", "d"]);
    Js.log (last_two ["a"])
  };
};

/* 3. Find the k'th element of a list. (easy)

   Solution

   # at 3 [ "a" ; "b"; "c"; "d"; "e" ];;
   - : string option = Some "c"
   # at 3 [ "a" ];;
   - : string option = None */
module Third = {
  let rec at num arr =>
    switch arr {
    | [] => None
    | [hd, ...tail] => num === 1 ? Some hd : at (num - 1) tail
    };
  let solution () => {
    Js.log2 "THREE" (at 3 ["a", "b", "c", "d", "e"]);
    Js.log2 "THREE" (at 3 ["a"])
  };
};

/* 4. Find the number of elements of a list. (easy)

   OCaml standard library has List.length but we ask that you reimplement it.
   Bonus for a tail recursive solution.

   Solution

   # length [ "a" ; "b" ; "c"];;
   - : int = 3
   # length [];;
   - : int = 0 */
module Four = {
  let length arr => {
    let counter = 0;
    let rec len arrInner =>
      switch arrInner {
      | [] => 0
      | [hd] => hd
      | [hd, ...tail] => hd + len tail
      };
      
  };
};