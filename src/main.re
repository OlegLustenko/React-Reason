type accept;    

type hot = { accept: accept };  
/* type hot; */
type windowModule = { hot: hot };   

external moduleHot: windowModule = "module" [@@bs.val];

let create_Component = fun reactElement => ReactDOMRe.renderToElementWithClassName reactElement "root";

ReactDOMRe.renderToElementWithClassName <App message="Exercies:"/> "root";

Js.log(moduleHot); 


/* let acceptCallback() => {
  create_Component <App message="Exercies:"/>
}; */


/* moduleHot.hot.accept("./app.re", acceptCallback)   */


