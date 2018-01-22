let component = ReasonReact.statelessComponent("Home");

let str = ReasonReact.stringToElement;

let make = (_children) => {
  ...component,
  didMount: (_) => {
    Js.Promise.(
      Axios.get("http://localhost:8001/api/v1/heroes")
      |> then_((response) => resolve(Js.log(response##data)))
      |> catch((error) => resolve(Js.log(error)))
      |> ignore
    );
    ReasonReact.NoUpdate
  },
  render: (_self) => <div> (str("Home")) </div>
};