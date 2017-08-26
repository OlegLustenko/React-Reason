type accept;

type hot = Js.t {. accept : (string, unit)};

type update;

type windowModule = Js.t {. hot : hot};

external moduleHot : windowModule = "module" [@@bs.val];

let create_Component reactElement => ReactDOMRe.renderToElementWithClassName reactElement "root";

let acceptCallback = create_Component <App message="Exercies:" />;

/* acceptCallback */
/* switch moduleHot##hot {
   | None => None
   | Some hot =>
     switch hot {
     | Some accept => accept ("./app.re", acceptCallback)
     }
   }; */
/* [%%bs.raw {|
  if(module.hot) {
    module.hot.accept()
    }
  |}]; */