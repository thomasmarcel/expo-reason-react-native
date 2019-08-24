type t;

module Auth {
  type t;

  type params = {
    .
    "appId": string,
  };

  [@bs.send] external isLoggedIn : (t, string, unit) => Js.Promise.t(bool) = "";
  [@bs.send] external login : (t, string, unit) => Js.Promise.t(bool) = "";
}

[@bs.module "onegraph-auth"] [@bs.new]
external make : (Auth.params, unit) => Auth.t = "OneGraphAuth";

/* [@bs.val] [@bs.module "onegraph-auth"] */
/* external isLoggedIn: (Auth.t, string, unit) => Js.Promise.t(string) = "isLoggedIn"; */
