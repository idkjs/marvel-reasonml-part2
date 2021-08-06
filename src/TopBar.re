[@bs.module] external logo : string = "./assets/Marvel-Logo.png";



let style =
  Css.(
    {
      "header":
        style([
          backgroundColor(rgba(238, 35, 45, `num(1.0))),
          display(`flex),
          justifyContent(`spaceBetween),
          alignItems(`center)
        ]),
      "title": style([color(white), fontSize(px(36)), fontWeight(`bold)]),
      "logo": style([width(px(200)), height(px(80)), marginLeft(px(32)) ]),
      "search_input_wrapper":style([marginRight(px(32))]),
      "search_input": style([marginRight(px(8))])
    }
  );
[@react.component]
let make = () => {

    <header className=style##header>
      <a href="#">
        <img className=style##logo src={logo} />
      </a>
      <span className=style##title> (React.string("Super Marvel Heroes")) </span>
      <div className=style##search_input_wrapper>
        <input className=style##search_input placeholder="search" />
        <button> (React.string("Search")) </button>
      </div>
    </header>
};
