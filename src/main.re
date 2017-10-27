/* open Homework1; */
type accept;

type update;

[@bs.val] external moduleHot : Js.t({..}) = "module";

/* Js.log2 ">>>>>" Homework1.oleg; */
/* Js.log2 ">>>>>" Homework1.jsOleg; */
let create_Component = (reactElement) =>
  ReactDOMRe.renderToElementWithClassName(reactElement, "root");

let acceptCallback = () => create_Component(<App message="Exercies:" />);

acceptCallback();

if (moduleHot##hot |> Js.to_bool) {
  Js.log2("%c updating...", "color: green; font-weight: bold;")
};