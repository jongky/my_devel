import os
import json
from socket import *
from datetime import datetime

print "[## JK-01]  my_test :  Begin ---->"

a_dict = {
	'dog': {
		'red': 5,
		'blue': 6,
	},
	'cat': {
		'green': 7,
	},
}

def my_callback(k, v):
	print (k, v)

def process_dict(d, depth, callback, path=()):
	for k, v in d.iteritems():
		if depth == 1:
			callback(path + (k,), v)
		else:
			process_dict(v, depth - 1, callback, path + (k,))

if isinstance('dog', a_dict):
	process_dict(a_dict, 1, my_callback)
	process_dict(a_dict, 2, my_callback)

if isinstance('cat', a_dict):
	print "[## JK-021]  my_test : 'cat' is instance ..."
else:
	print "[## JK-022]  my_test : 'cat' is not instance ..."

print "[## JK-099]  my_test :  End <----"
