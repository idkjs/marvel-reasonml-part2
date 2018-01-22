let parseHeroJson = (json: Js.Json.t) : HeroCard.hero =>
  Json.Decode.{
    id: json |> field("id", int),
    name: json |> field("name", string),
    true_name: json |> field("true_name", string),
    place_of_birth: json |> field("place_of_birth", string),
    description: json |> optional(field("description", string)),
    image: json |> field("image", string),
    citizenship: json |> field("image", string),
    comics: json |> field("comics", list(int)),
    powers: json |> field("powers", list(string))
  };

/* parse all heroes by call Json.Decode.array with to parse all
entries in the returned json which will look like parseHeroJson */

let parseHeroesJson = (json) => Json.Decode.array(parseHeroJson, json);
/* create function to get the data here in API since this is
where we are processing the data.
The response type is Js.t, so we access its property ( data)using ##.
*/

let fetchHeroes = () =>
  Js.Promise.(
    Axios.get("http://localhost:8001/api/v1/heroes")
    |> then_((response) => resolve(parseHeroesJson(response##data)))
);