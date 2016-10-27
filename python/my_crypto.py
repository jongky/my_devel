import os
import json
import struct, random, hashlib, array, types
import base64
from ctypes import Structure, c_long, c_int, create_string_buffer, CDLL, byref
from Crypto.Cipher import AES

BLOCK_SIZE = 32
PADDING='#'


def _pad(data, pad_with=PADDING):
    """
    Data to be encrypted should be on 16, 24 or 32 byte boundaries.
    So if you have 'hi', it needs to be padded with 30 more characters 
    to make it 32 bytes long. Similary if something is 33 bytes long, 
    31 more bytes are to be added to make it 64 bytes long which falls 
    on 32 boundaries.
    - BLOCK_SIZE is the boundary to which we round our data to.
    - PADDING is the character that we use to padd the data.
    """
    return data + (BLOCK_SIZE - len(data) % BLOCK_SIZE) * PADDING

def encrypt(secret_key, data):
    """
    Encrypts the given data with given secret key. 
    """
    cipher = AES.new(_pad(secret_key, '@')[:32])
    return base64.b64encode(cipher.encrypt(_pad(data)))

def decrypt(secret_key, encrypted_data):
    """
    Decryptes the given data with given key.
    """
    cipher = AES.new(_pad(secret_key, '@')[:32])
    return cipher.decrypt(base64.b64decode(encrypted_data)).rstrip(PADDING)

# ########################################################################################
# 1. Hashing Algorithm :
# ========================================================================================
print "[## JK-01]  my_hash :  Begin ---->"
password = 'AAbbCCdd'
print "[## JK-011]  my_hash : password= %s" %(password)
encrypted_passwd = hashlib.sha256(password).hexdigest()
print "[## JK-012]  my_hash : encrypted_passwd= %s" %(encrypted_passwd)

# ########################################################################################
# 2. Encryption/Decryption Algorithms :
# ========================================================================================
# KEY='your-key-super-duper-secret-key-here-only-first-32-characters-are-used'
KEY='$2a$07$R.gJb2U2N.FmZ4hPp1y2CN$12'
encrypted =  encrypt(KEY, password)
print "[## JK-021]  my_encryption : encrypted= %s" %(encrypted)

decrypted_password = decrypt(KEY, encrypted)
print "[## JK-021]  my_encryption : decrypted_password= %s" %(decrypted_password)

encrypted_js = 'DJO7p6nr2sxRTmRIKAqGq0wthQEWEs79cyzq9LYiaR4='
decrypted_js = decrypt(KEY, encrypted_js)
print "[## JK-022]  my_encryption : decrypted_js= %s" %(decrypted_js)
