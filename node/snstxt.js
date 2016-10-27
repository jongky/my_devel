// var twilio = require('twilio');
var accountSid = 'AC310612019b169e1569948f4879f215a1';
var authToken = '[AuthToken]'; 
// var client = new twilio.RestClient(accountSid, authToken);
var client = require('twilio')(accountSid, authToken);

console.log("[1] Tring to Text -->");
 
//client.messages.create({
client.sendMessage({
    body: "Test : Alarm Message",
    to: "14083151235",
    from: "+14083151235",
    mediaUrl: "http://www.example.com/hearts.png"
}, function(error, message) {
    console.log("[2] Sent a message");
    if (!error) {
        console.log('Success! The SID for this SMS message is:');
        // console.log(message.sid);
        console.log('Message sent on:');
        console.log(message.dateCreated);
    } else {
        console.log('Oops! There was an error because:' +error.message);
    }
});
/* 
client.messages.create({
    to:'+14083151235',
    from:'TWILIO_NUMBER',
    body:'Hello World'
}, function(error, message) {
    if (error) {
        console.log(error.message);
    }
});
*/