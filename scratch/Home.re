/* define state type for reducer component */
type state = {heroes: option(array(HeroCard.hero))};

/* define action that will get current state */
type action =
  | HeroesFetched(array(HeroCard.hero));

/* let fakeHero: HeroCard.hero = {
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
   }; */
/* change to react reducer component */
let component = ReasonReact.reducerComponent("Home");

let str = ReasonReact.stringToElement;

/* call make passing in hero type def and _children */
let make = (_children) => {
  ...component,
  initialState: () => {heroes: None},
  reducer: (action, _state) =>
    switch action {
    | HeroesFetched(heroes) => ReasonReact.Update({heroes: Some(heroes)})
    },
  didMount: (self) => {
    /* define () to use api to get heroes */
    let handleLoadedHeroes = self.reduce((heroes) => HeroesFetched(heroes));
    Api.fetchHeroes()
    |> Js.Promise.then_(
         (heroes) => {
           handleLoadedHeroes(heroes);
           Js.Promise.resolve()
         }
       )
    /* last |> ignore is just to silence the linter. */
    |> ignore;
    ReasonReact.NoUpdate
  },
  render: (self) => {
    let heroesComponent =
      switch self.state.heroes {
      | Some(heroes) =>
        ReasonReact.arrayToElement(
          Array.map(
            (hero: HeroCard.hero) => <HeroCard key=(string_of_int(hero.id)) hero />,
            heroes
          )
        )
      | None => str("Loading")
      };
    <div> heroesComponent </div>
  }
};