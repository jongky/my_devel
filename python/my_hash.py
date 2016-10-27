import os
import json
import struct, random, hashlib, array, types
import base64
from ctypes import Structure, c_long, c_int, create_string_buffer, CDLL, byref
# from M2Crypto import Random
# from M2Crypto.Cipher import AES
# import crypto
from Crypto.Cipher import AES
crypto = None

def load_crypto():
    global crypto
    #crypto = CDLL(find_library('crypto'))
    crypto = CDLL('libcrypto.so')

def encrypt_aes256_cbc():
	global crypto
	print "[## JK-021]  my_hash : encrypt_aes256_cbc --> Loading libcrypto.so" 
	if crypto is None:
		print "[## JK-021.1]  my_hash : encrypt_aes256_cbc --> Loading libcrypto.so" 
		load_crypto()
		print "[## JK-021.1]  my_hash : encrypt_aes256_cbc --> Loading completed ----" 

def decrypt_node(hex_data, key='0'*32, iv='0'*16):
    data = ''.join(map(chr, bytearray.fromhex(hex_data)))
    aes = AES.new(key, AES.MODE_CBC, iv)
    return unpad(aes.decrypt(data))

def aes256_key_from_password(password):
    md = hashlib.sha256()
    md.update(password)
    ret = md.digest()
    return ret

print "[## JK-01]  my_hash :  Begin ---->"
password = 'AAbbCCDD'
print "[## JK-011]  my_hash : password= %s" %(password)
encrypted_passwd = hashlib.sha256(password).hexdigest()
print "[## JK-012]  my_hash : encrypted_passwd= %s" %(encrypted_passwd)

encrypted_passwd = aes256_key_from_password(password)
print "[## JK-014]  my_hash : aes256_key_from_password= %s" %(encrypted_passwd)


encrypt_aes256_cbc()

# decrypted_passwd = decrypt(encrypted_passwd)
# print "[## JK-015] encrypt_aes256_cbc my_hash : encrypted_passwd= %s" %(decrypted_passwd)

"""
BS = 16
def pad(data):
    padding = BS - len(data) % BS
    return data + padding * chr(padding)

def unpad(data):
    return data[0:-ord(data[-1])]

def decrypt_node(hex_data, key='0'*32, iv='0'*16):
    data = ''.join(map(chr, bytearray.fromhex(hex_data)))
    aes = AES.new(key, AES.MODE_CBC, iv)
    return unpad(aes.decrypt(data))

def encrypt_node(data, key='0'*32, iv='0'*16):
    aes = AES.new(key, AES.MODE_CBC, iv)
    return aes.encrypt(pad(data)).encode('hex')

encrypted_node = encrypt_node(password)
print "[## JK-021]  my_hash : decrypt_node= %s" %(encrypted_node)

decrypted_passwd = encrypt_node(encrypted_node)
print "[## JK-022]  my_hash : decrypted_passwd= %s" %(decrypted_passwd)
"""
print "[## JK-099]  my_hash :  End <----"


"""
def AESencrypt(password, plaintext, base64=False):
    import hashlib, os
    from Crypto.Cipher import AES
    SALT_LENGTH = 32
    DERIVATION_ROUNDS=1337
    BLOCK_SIZE = 16
    KEY_SIZE = 32
    MODE = AES.MODE_CBC
     
    salt = os.urandom(SALT_LENGTH)
    iv = os.urandom(BLOCK_SIZE)
     
    paddingLength = 16 - (len(plaintext) % 16)
    paddedPlaintext = plaintext+chr(paddingLength)*paddingLength
    derivedKey = password
    for i in range(0,DERIVATION_ROUNDS):
        derivedKey = hashlib.sha256(derivedKey+salt).digest()
    derivedKey = derivedKey[:KEY_SIZE]
    cipherSpec = AES.new(derivedKey, MODE, iv)
    ciphertext = cipherSpec.encrypt(paddedPlaintext)
    ciphertext = ciphertext + iv + salt
    if base64:
        import base64
        return base64.b64encode(ciphertext)
    else:
        return ciphertext.encode("hex")
 
def AESdecrypt(password, ciphertext, base64=False):
    import hashlib
    from Crypto.Cipher import AES
    SALT_LENGTH = 32
    DERIVATION_ROUNDS=1337
    BLOCK_SIZE = 16
    KEY_SIZE = 32
    MODE = AES.MODE_CBC
     
    if base64:
        import base64
        decodedCiphertext = base64.b64decode(ciphertext)
    else:
        decodedCiphertext = ciphertext.decode("hex")
    startIv = len(decodedCiphertext)-BLOCK_SIZE-SALT_LENGTH
    startSalt = len(decodedCiphertext)-SALT_LENGTH
    data, iv, salt = decodedCiphertext[:startIv], decodedCiphertext[startIv:startSalt], decodedCiphertext[startSalt:]
    derivedKey = password
    for i in range(0, DERIVATION_ROUNDS):
        derivedKey = hashlib.sha256(derivedKey+salt).digest()
    derivedKey = derivedKey[:KEY_SIZE]
    cipherSpec = AES.new(derivedKey, MODE, iv)
    plaintextWithPadding = cipherSpec.decrypt(data)
    paddingLength = ord(plaintextWithPadding[-1])
    plaintext = plaintextWithPadding[:-paddingLength]
    return plaintext
     
a = AESencrypt("password", "ABC")
print AESdecrypt("password", a)
"""