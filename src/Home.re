/* define state type for reducer component */
type state = {heroes: option(array(HeroCard.hero))};

/* define action that will get current state */
type action =
  | HeroesFetched(array(HeroCard.hero))
  | SomeAction;

let fakeHero: HeroCard.hero = {
  id: 0,
  name: "Mephisto",
  true_name: "Nick Scratch",
  powers: [
    "force blast",
    "astral projection",
    "interdimiensional portals",
    "illusions",
    "shape shifting",
    "soul capturing"
  ],
  place_of_birth: "Unknown",
  citizenship: "Hell",
  image: "mephisto.jpg",
  description: "Mephisto is an extra-dimensional demon whose origin is unknown. He rules a fiery pocket dimension that he calls \"Hell\" or \"Hades\" although it is neither the hell of the Christian religion nor the Hades ruled by Pluto, the Olympian god of the dead. Mephisto calls his extra-dimensional realm \"hell\" in order to exploit Earth human beings' belief in a single being of absolute evil, who is often referred to as Satan, who rules such a realm.",
  comics: [5, 9, 20, 26]
};

/* change to react reducer component */
let component = ReasonReact.reducerComponent("Home");

let str = ReasonReact.stringToElement;

/* call make passing in hero type def and _children */
let make = (_children) => {
  ...component,
  initialState: () => {heroes: None},
  reducer: (action, state) =>
    switch action {
    | HeroesFetched(heroes) => ReasonReact.Update({heroes: Some(heroes)})
    },
  didMount: (_) => {
    Js.Promise.(
      Axios.get("http://localhost:8001/api/v1/heroes")
      |> then_((response) => resolve(Js.log(response##data)))
      |> catch((error) => resolve(Js.log(error)))
      |> ignore
    );
    ReasonReact.NoUpdate
  },
  render: (self) => <div> <HeroCard hero=fakeHero /> </div>
};