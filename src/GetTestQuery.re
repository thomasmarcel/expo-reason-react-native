open Queries;
open ReactNative;

[@react.component]
let make = () => {
  let getTestQuery = Test.make(~state="TX", ~city="SAN ANTONIO", ());
  <TestQuery variables=getTestQuery##variables>
    ...{({result}) =>
      {switch (result) {
        | Error(e) =>
          Js.log(e);
          <Text>e##message->React.string</Text>
        | Loading =>
          Js.log("Loading");
          <Text>"Loading"->React.string</Text>
        | Data(data) =>
          Js.log(data);
          <Text>"data"->React.string</Text>
   }}}
  </TestQuery>
};
