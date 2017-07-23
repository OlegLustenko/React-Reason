include Html;
let component = ReasonReact.statelessComponent "App";

let handleClick _event _self => Js.log "clicked!";
let rrStrToElem = ReasonReact.stringToElement;

let exerciesOut = [|
  <Exercise1 />,
  <Exercise2 />
|];

type exer2Data = {
  shortName: string,
  longName: string
};

let exercise2Data: exer2Data = {
  shortName: "Oleg .L",
  longName: "Ivanov Ivan Ivanovich"
};

/* let exercies = Array.map (fun exercise => <li>exercise<hr /></li>) exerciesOut; */
    

let make ::message _children => {
  ...component,
  render: fun self => 
    
    <div onClick=(self.handle handleClick)> (ReasonReact.stringToElement message) 
      <ul>          
          ("1: " |> Html.text) <Exercise1 />
          <hr />
          <Exercise2 name=exercise2Data.shortName />
          <Exercise2 name=exercise2Data.longName />
          <hr />
      </ul>  
    </div>
  
};