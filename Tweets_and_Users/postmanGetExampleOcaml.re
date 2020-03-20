open Lwt;

open Cohttp;

open Cohttp_lwt_unix;

let reqBody = {
  let uri =
    Uri.of_string("https://api.twitter.com/1.1/statuses/user_timeline.json?screen_name=snap");
  let headers =
    Header.init()
    |> (
      (h) =>
        Header.add(
          h,
          "Authorization",
          "OAuth oauth_consumer_key=\"wJSLu6b0hW8i0OtneuKi1oND0\",oauth_token=\"22362043-sV5rRyoZYcOXfFuaOQKdnvjVlXRwn67CQ95mJ6Bi0\",oauth_signature_method=\"HMAC-SHA1\",oauth_timestamp=\"1580923193\",oauth_nonce=\"zfJNyD5ApMJ\",oauth_version=\"1.0\",oauth_signature=\"TKV6XFTpFvyTWB4L13blSaslzzk%3D\""
        )
    );
  Client.call(~headers, `GET, uri)
  >>= (((resp, body)) => body |> Cohttp_lwt.Body.to_string >|= ((body) => body));
};

let () = {
  let respBody = Lwt_main.run(reqBody);
  print_endline(respBody);
};
