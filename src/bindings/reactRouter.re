open History;

type renderFunc =
  {
    .
    "match": Js.Dict.t(string),
    "history": History.history,
    "location": History.Location.location,
  } =>
  React.element;

module BrowserRouter = {
  [@bs.module "react-router-dom"] [@react.component]
  external make: (~children: React.element) => React.element = "BrowserRouter";
};

module Switch = {
  [@bs.module "react-router-dom"] [@react.component]
  external make: (~children: React.element) => React.element = "Switch";
};

module Route = {
  [@bs.module "react-router-dom"] [@react.component]
  external make:
    (
      ~component: option('a => React.element)=?,
      ~exact: bool=?,
      ~path: option(string)=?,
      ~render: option(renderFunc)=?,
      ~children: React.element=?
    ) =>
    React.element =
    "Route";
};
