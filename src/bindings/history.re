module History = {
  type history;
  [@bs.send] external goBack : history => unit = "goBack";
  [@bs.send] external goForward : history => unit = "goForward";
  [@bs.send] external go : (history, ~jumps: int) => unit = "go";
  [@bs.get] external length : history => int = "length";
  [@bs.get] external location : history => string = "location";
  module Location = {
    type location;
    [@bs.get] external pathname : location => string = "pathname";
    [@bs.get] external search : location => string = "search";
    [@bs.get] external hash : location => string = "hash";
  };
};
