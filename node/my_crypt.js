var crypto = require('crypto');
// var CryptoJS = require("crypto-js");

var salt1 = '$2a$07$R.gJb2U2N.FmZ4hPp1y2CN$';
var salt = '1234567890';
var password = 'AAbbCCdd';
var key = '$2a$07$R.gJb2U2N.FmZ4hPp1y2CN$12';

var algo1 = 'aes-128-cbc'
var algo2 = 'aes-256-ctr'
var algo3 = 'aes256'
var algorithm = algo3;

/*
console.log("[## JK-Test: my_crypt-01] Calling crypto with password= " + password);
const key1 = crypto.pbkdf2Sync(password, salt, 100000, 256, 'sha256');
console.log("[## JK-Test: my_crypt-02] Calling crypto with key1= " + key1.toString('hex'));

const key2 = crypto.pbkdf2Sync(password, salt, 100000, 512, 'sha512');
console.log("[## JK-Test: my_crypt-03] Calling crypto with key2= " + key2.toString('hex'));
*/

function encrypt(password){
  	var cipher = crypto.createCipher(algorithm, key);
  	var crypted = cipher.update(password,'utf8','hex');
	console.log("[## JK-Test: my_crypt-11] Calling crypto with crypted= " + crypted);
  	crypted += cipher.final('hex');
  	return crypted;
}
 
function decrypt(text){
	var decipher = crypto.createDecipher(algorithm, key);
  	var dec = decipher.update(text,'hex','utf8');
	console.log("[## JK-Test: my_crypt-21] Calling crypto with dec= " + dec);
  	dec += decipher.final('utf8');
  	return dec;
}
 
function encrypt_aes(password){
  	var cipher_text = crypto.AES.encrypt(password, key);
	console.log("[## JK-Test: my_crypt-31] Calling crypto with cipher_text= " + cipher_text);
  	return cipher_text;
}

var encrpt_password = encrypt(password);
console.log("[## JK-Test: my_crypt-12] Calling crypto with encrpt_password= " + encrpt_password);
// outputs hello world

var encrpt_aes = encrypt_aes(password);
console.log("[## JK-Test: my_crypt-13] Calling crypto with encrpt_aes= " + encrpt_aes);

var decrpt_password = decrypt(encrpt_password)

console.log("[## JK-Test: my_crypt-22] Calling crypto with decrpt_password= " + decrpt_password);


