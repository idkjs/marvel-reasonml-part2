type hero = {
  id: int,
  name: string,
  true_name: string,
  powers: list(string),
  place_of_birth: string,
  citizenship: string,
  image: string,
  description: option(string),
  comics: list(int)
};


[@react.component]
let make = (~hero: hero) => {
 <div> (React.string("Hero name " ++ hero.name)) </div>
};
