/* Create an InMemoryCache */
let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

let appId = "ec327cfd-3616-4c18-9901-e92ff087713b";

/* Create an HTTP Link */
let httpLink =
  ApolloLinks.createHttpLink(~uri="https://serve.onegraph.com/dynamic?app_id="
                             ++ appId, ());

let instance =
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());
