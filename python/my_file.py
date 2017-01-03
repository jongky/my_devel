import os
import json
import socket
from datetime import datetime
import re

FILE_WINGCLOUD_CONF="wingcloud.conf"
FILE_WINGCLOUD_CONF_NEW="wingcloud.conf.new"

TEXT_TO_REPLACE = {
	"RUN_MONGODB=0" : "RUN_MONGODB=1",
	"INITIALIZE_MONGODB=0" : "INITIALIZE_MONGODB=1",
	"MONGODB_USE_SSL=0" : "MONGODB_USE_SSL=1",
	"RUN_REPORTS=0" : "RUN_REPORTS=1",
	"ENABLE_CONFIG_CONNECTION=0" : "ENABLE_CONFIG_CONNECTION=1",
	"RUN_CONN_MGR=0" : "RUN_CONN_MGR=1",
	"RUN_MGMT_SRV=0" : "RUN_MGMT_SRV=1",
	"RUN_DASHBOARD=0" : "RUN_DASHBOARD=1",
	"INITIALIZE_RABBITMQ=0" : "INITIALIZE_RABBITMQ=1",
	"RUN_HAPROXY=0" : "RUN_HAPROXY=1",
	"RABBITMQ_SERVER=" : "RABBITMQ_SERVER=localhost"
}

TEXT_TO_ADD_SERVERIP = {
	"MART_SERVER=" : "MART_SERVER=",
	"CONN_MGR_ADDR=" : "CONN_MGR_ADDR=",
	"DASHBOARD_SERVER=" : "DASHBOARD_SERVER=",
	"AP_CONNECTION_MANAGER=" : "AP_CONNECTION_MANAGER=",
	"CONN_MGR_ADDR=" : "CONN_MGR_ADDR="
}

def get_my_local_ip():
	s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	s.connect(('8.8.8.8', 0))  # connecting to a UDP address doesn't send packets
	local_ip_address = s.getsockname()[0]
	return local_ip_address

def replace_words(text, word_dic):
	"""
	take a text and replace words that match a key in a dictionary with
	the associated value, return the changed text
	"""
	rc = re.compile('|'.join(map(re.escape, word_dic)))    
	print "[## JK-11]  replace_words : re.escape: %s" %(re.escape)
	print "[## JK-12]  replace_words : word_dic: %s" %(word_dic)

	def translate(match):
		return word_dic[match.group(0)]
	return rc.sub(translate, text)

def build_words_with_ip():
	"""
	take a text and replace words that match a key in a dictionary with
	the associated value, return the changed text
	"""
	my_public_ip = get_my_local_ip()
	for textToSearch in TEXT_TO_ADD_SERVERIP:
		print "[## JK-21]  replace_words : textToSearch= %s" %(textToSearch)
		textToReplace=textToSearch+my_public_ip
		print "[## JK-22]  replace_words : textToReplace= %s" %(textToReplace)
		TEXT_TO_ADD_SERVERIP[textToSearch] = textToReplace
		print "[## JK-23]  replace_words : TEXT_TO_ADD_SERVERIP= %s" %(TEXT_TO_ADD_SERVERIP)


print "[## JK-01]  my_file :  Begin ---->"
f = open(FILE_WINGCLOUD_CONF,'r')
filedata = f.read()
f.close()

updated_conf = replace_words(filedata, TEXT_TO_REPLACE)
build_words_with_ip()
updated_conf = replace_words(filedata, TEXT_TO_ADD_SERVERIP)
# updated_conf = replace_words_wtih_ip(filedata, TEXT_TO_ADD_SERVERIP)
fout = open(FILE_WINGCLOUD_CONF_NEW, "w")
fout.write(updated_conf)
fout.close()

print "[## JK-099]  my_file :  End <----"
