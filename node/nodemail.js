var nodemailer = require("nodemailer");

/*
nodemailer.SMTP = {
    host: 'gmail.com', 
    port:465,
    use_authentication: true, 
    user: 'jongkylee@gmail.com', 
    pass: 'Pado!004'
};

var message = {
    sender: 'jongkylee@gmail.com',
    to:'fnwd64@zebra.com',
    subject:'Attachment!',
    body:'',
    attachments : [{'filename': 'helloworld.txt','contents':'Alarm'}]
};

nodemailer.sendMail(message, function(err) {   
    if (!err) { 
        console.log('Email send ...');
    } 
    else console.log(sys.inspect(err));       
});
*/

var smtpTransport = nodemailer.createTransport("SMTP",{
   service: "Gmail",
   auth: {
       user: "jongkylee@gmail.com",
       pass: "Pado!004"
   }
});

// setup e-mail data with unicode symbols
var mailOptions = {
    from: "Jongky Lee ✔ <jongkylee@gmail.com>", // sender address
    to: "jongkylee@gmail.com", // list of receivers
    subject: "Hello ✔", // Subject line
    text: "Hello world ✔", // plaintext body
    html: "<b>Hello world ✔</b>" // html body
}

smtpTransport.sendMail(mailOptions, function(error, response){
   if(error){
       console.log(error);
   }else{
       console.log("Message sent: " + response.message);
   }
});
