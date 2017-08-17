type accept;


/* type hot; */
type update:unit;

type windowModule = Js.t {. hot: {update}};

external moduleHot : windowModule = "module" [@@bs.val];

let create_Component reactElement => ReactDOMRe.renderToElementWithClassName reactElement "root";

ReactDOMRe.renderToElementWithClassName <App message="Exercies:" /> "root";

if (moduleHot##hot) {
  Js.log moduleHot
};
/* let acceptCallback() => {
     create_Component <App message="Exercies:"/>
   }; */
/* moduleHot.hot.accept("./app.re", acceptCallback)   */