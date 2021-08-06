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

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (_state, action) =>
        switch (action) {
        | HeroesFetched(heroes) => {heroes: Some(heroes)}
        },
      {heroes: None},
    );
  React.useEffect0(() => {
    /* define () to use api to get heroes */
    let handleLoadedHeroes = heroes => dispatch(HeroesFetched(heroes));
    Api.fetchHeroes()
    |> Js.Promise.then_(heroes => {
         handleLoadedHeroes(heroes);
         Js.Promise.resolve();
       })
    /* last |> ignore is just to silence the linter. */
    |> ignore;
    None;
  });

  let heroesComponent =
    switch (state.heroes) {
    | Some(heroes) =>
      React.array(
        Array.map(
          (hero: HeroCard.hero) =>
            <HeroCard key={string_of_int(hero.id)} hero />,
          heroes,
        ),
      )
    | None => React.string("Loading")
    };
  <div> heroesComponent </div>;
};
