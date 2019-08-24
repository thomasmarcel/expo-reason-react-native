module Test = [%graphql
  {|
    query getUserName($state: String!, $city: String) {
      immigrationGraph {
        allEmployers(condition: { addressState: $state, addressCity:
          $city }) {
          nodes {
            name
            addressCity
            addressCountry
            addressState
            trade
          }
        }
      }
    }
|}
];

module TestQuery = ReasonApollo.CreateQuery(Test);
