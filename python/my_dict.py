import os
import json
from socket import *
from datetime import datetime

print "[## JK-01]  my_test :  Begin ---->"

alarm_col = [ 'alarm_log', 'alarm_log_mu', 'alarm_log_site']
alarm_history_col = [ 'alarm_history', 'alarm_history_mu', 'alarm_history_site']

for count in range(2):
	print "[## JK-02.1]  my_test :  count = %d" %(count)

for count in [0, 1, 2]:
	print "[## JK-02]  my_test :  count = %d" %(count)


for db_col in alarm_col:
	print "[## JK-02]  my_test :  db_col = %s" %(db_col)
	print "[## JK-02]  my_test :  size of db_col = %d" %(len(db_col))

for db_col in alarm_history_col:
	print "[## JK-02]  my_test :  db_col = %s" %(db_col)


a_dict = {
	'dog': {
		'color': 'gray',
		'age'  : 6,
	},
	'cat': {
		'color': 'red',
		'age'  : 3,
	},
}

b_dict = {
	"syslog" :  {  
		"server"  :  [
		]
	},
	"sms" :  {

	},

}
def isEmpty(dictionary):
	for element in dictionary:
		print "[## JK-031]  isEmpty : element = %s" %(element) 
	 	if element:
			return False
		return True

def my_callback(k, v):
	print (k, v)

def process_dict(d, depth, callback, path=()):
	for k, v in d.iteritems():
		if depth == 1:
			callback(path + (k,), v)
		else:
			process_dict(v, depth - 1, callback, path + (k,))

if 'dog' in a_dict:
	process_dict(a_dict, 1, my_callback)
	process_dict(a_dict, 2, my_callback)

if 'bear' in a_dict:
	print "[## JK-021]  my_test : 'bear' is instance ..."
else:
	print "[## JK-022]  my_test : 'bear' is not instance ..."

dog_color = a_dict['dog']['color']
print "[## JK-023]  my_test : dog_color= [%s]" %(dog_color)


if isEmpty(b_dict["syslog"]):
	print "[## JK-024]  my_test : syslog is Empty" 
if isEmpty(b_dict["sms"]):
	print "[## JK-025]  my_test : sms is Empty"

sms_config = b_dict.get('sms', {})
print "[## JK-026]  my_test : sms_config is %s" %sms_config
print "[## JK-026]  my_test : Length of sms_config is %s" %len(sms_config)

if sms_config is None:
	print "[## JK-026]  my_test : sms_config %s" %(sms_config)

syslog_config = b_dict.get('syslog', {})
print "[## JK-028]  my_test : syslog_config is %s" %syslog_config
print "[## JK-029]  my_test : Length of syslog_config is %s" %len(syslog_config)

print "[## JK-099]  my_test :  End <----"
