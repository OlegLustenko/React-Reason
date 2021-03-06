[@bs.val] external random : unit => float = "Math.random";

[@bs.val] external floor : float => int = "Math.floor";

type user = {
  recid: int,
  personid: int,
  fname: string,
  lname: string,
  email: string,
  sdate: string
};

let generate = (count) => {
  let records = [];
  let fname = [
    "Oleg",
    "~Katsia",
    "John",
    "Viktor",
    "#Sue",
    "JavaScript",
    "<Thomas",
    ">Sergei",
    "Snehal",
    "Oleg",
    "Divi"
  ];
  let lname = [
    "Peterson",
    "Oleg",
    "Johnson-Petrov-Sannikov-Ivanov-Smirnov",
    "Cuban",
    "Twist",
    "Sidorov",
    "Vasiliev",
    "React",
    "Vaishna"
  ];
  /* type fillList = int => list; */
  let rec fillList = (l, len) => {
    let user = {
      recid: len + 1,
      personid: len + 1,
      fname: List.nth(fname, floor(random() *. float_of_int(List.length(fname)))),
      lname: List.nth(lname, floor(random() *. float_of_int(List.length(lname)))),
      email: "oleg.lustenko@gmail.com",
      sdate: "07.10.17"
    };
    switch len {
    | 0
    | 1 => l
    | _ => fillList(l @ [user], len - 1)
    }
  };
  fillList(records, count * 10)
};

Js.log(generate(35));
