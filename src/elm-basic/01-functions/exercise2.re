include Html;

let component = ReasonReact.statelessComponent "Exercies2";

let defPropShortName:string = "Oleg L.";
let capitalize name maxLength => 
  if (String.length name > maxLength) {
    String.uppercase name
  } else 
    name;

let make ::name=defPropShortName _children => {
  ...component,
  render: fun self => {
    <div>
      <p>(
        capitalize name 10
        ^ " -name length: " 
        ^ string_of_int (String.length name)
        |> Html.text      
      )</p>
    </div>
  }
}