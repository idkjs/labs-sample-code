var request = require('request');
var options = {
  'method': 'GET',
  'url': 'https://api.twitter.com/1.1/statuses/user_timeline.json?screen_name=snap',
  'headers': {
    'Authorization': 'OAuth oauth_consumer_key="wJSLu6b0hW8i0OtneuKi1oND0",oauth_token="22362043-sV5rRyoZYcOXfFuaOQKdnvjVlXRwn67CQ95mJ6Bi0",oauth_signature_method="HMAC-SHA1",oauth_timestamp="1580923193",oauth_nonce="zfJNyD5ApMJ",oauth_version="1.0",oauth_signature="TKV6XFTpFvyTWB4L13blSaslzzk%3D"'
  }
};
request(options, function (error, response) {
  if (error) throw new Error(error);
  console.log(response.body);
});
