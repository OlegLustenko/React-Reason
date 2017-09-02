/* open Homework1; */
type accept;
type update;
external moduleHot : Js.t {..} = "module" [@@bs.val];
/* Js.log2 ">>>>>" Homework1.oleg; */
/* Js.log2 ">>>>>" Homework1.jsOleg; */
let create_Component reactElement => ReactDOMRe.renderToElementWithClassName reactElement "root";

let acceptCallback () => create_Component <App message="Exercies:" />;
acceptCallback();

if (Js.to_bool moduleHot##hot){
    Js.log2 "%c updating..." "color: green; font-weight: bold;";   
    moduleHot##hot##accept();
  };
