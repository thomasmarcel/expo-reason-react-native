open ReactNative;

/*
 Here is StyleSheet that is using Style module to define styles for your components
 The main different with JavaScript components you may encounter in React Native
 is the fact that they **must** be defined before being referenced
 (so before actual component definitions)
 More at https://reasonml-community.github.io/reason-react-native/en/docs/apis/Style/
 */
let styles =
  Style.(
    StyleSheet.create({
      "container":
        style(
          ~flex=1.,
          ~justifyContent=`center,
          ~alignItems=`center,
          ~backgroundColor="#F5FCFF",
          (),
        ),
      "welcome":
        style(~fontSize=20., ~textAlign=`center, ~margin=10.->dp, ()),
      "instructions":
        style(~textAlign=`center, ~color="#333333", ~marginBottom=5.->dp, ()),
    })
  );

let appId = "ec327cfd-3616-4c18-9901-e92ff087713b";

[@react.component]
let app = () => {
  let auth = OneGraphAuth.make({"appId": appId}, ());
  Js.log(auth);
  let isLoggedIn = ref(false);
  let loggedIn = auth->OneGraphAuth.Auth.isLoggedIn("spotify", ())
    |> Js.Promise.then_(value => {
      Js.log(value);
      isLoggedIn := value;
      switch (value) {
        | true => Js.log("logged in!")
        | false => {
            auth->OneGraphAuth.Auth.login("spotify", ())
              |> Js.Promise.then_(loginValue => {
                  Js.log(loginValue);
                  Js.Promise.resolve(loginValue);
                })
            Js.log("Logging in");
          }
      }
      Js.Promise.resolve(value);
    });
  Js.log(isLoggedIn^);

  <ReasonApollo.Provider client=Client.instance>
    <View style=styles##container>
      <Text style=styles##welcome>
        "Welcome to (Reason) React Native!"->React.string
      </Text>
      <Text style=styles##instructions>
        "To get started, edit src/App.re"->React.string
      </Text>
      <Text style=styles##instructions>
        {switch (Platform.os) {
         /*
          Instructions depends on the platform this code will run on
          More at https://reasonml-community.github.io/reason-react-native/en/docs/apis/Platform/
          */
         | os when os == Platform.ios =>
           "Press Cmd+R to reload,\n" ++ "Cmd+D or shake for dev menu"
         | os when os == Platform.android =>
           "Double tap R on your keyboard to reload,\n"
           ++ "Shake or press menu button for dev menu"
         | os when os == Platform.web => "Press Cmd+R to reload."
         | _ => ""
         }}
        ->React.string
      </Text>
    </View>
    <GetTestQuery></GetTestQuery>
  </ReasonApollo.Provider>;
};
