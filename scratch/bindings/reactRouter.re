open History;

type renderFunc =
  {. "match": Js.Dict.t(string), "history": History.h, "location": History.Location.l} =>
  ReasonReact.reactElement;

module BrowserRouter = {
  [@bs.module "react-router-dom"] external browserRouter : ReasonReact.reactClass =
    "BrowserRouter";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=browserRouter, ~props=Js.Obj.empty(), children);
};

module Switch = {
  [@bs.module "react-router-dom"] external _switch : ReasonReact.reactClass = "Switch";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=_switch, ~props=Js.Obj.empty(), children);
};

module Route = {
  [@bs.module "react-router-dom"] external route : ReasonReact.reactClass = "Route";
  let make =
      (
        ~component: option(('a => ReasonReact.reactElement))=?,
        ~exact: bool=false,
        ~path: option(string)=?,
        ~render: option(renderFunc)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=route,
      ~props={
        "exact": Js.Boolean.to_js_boolean(exact),
        "path": Js.Nullable.fromOption(path),
        "component": Js.Nullable.fromOption(component),
        "render": Js.Nullable.fromOption(render)
      },
      children
    );
};