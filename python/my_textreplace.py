import os
text = "RUN_MONGODB=1"   # if any line contains this text, I want to modify the whole line.
new_text = "RUN_MONGODB=XXXX"
FILE_WINGCLOUD_CONF_NEW="wingcloud.new"
FILE_WINGCLOUD_CONF="wingcloud.conf"

TEXT_TO_REPLACE = {
	"RUN_MONGODB=0"             : "RUN_MONGODB=1",
	"INITIALIZE_MONGODB=0" 		: "INITIALIZE_MONGODB=1",
	"MONGODB_USE_SSL=0" 		: "MONGODB_USE_SSL=1",
	"RUN_MARTSERVER=0" 			: "RUN_MARTSERVER=1",
	"RUN_REPORTS=0" 			: "RUN_REPORTS=1",
	"ENABLE_CONFIG_CONNECTION=0": "ENABLE_CONFIG_CONNECTION=1",
	"RUN_CONN_MGR=0" 			: "RUN_CONN_MGR=1",
	"RUN_MGMT_SRV=0" 			: "RUN_MGMT_SRV=1",
	"RUN_DASHBOARD=0" 			: "RUN_DASHBOARD=1",
	"INITIALIZE_RABBITMQ=0"	 	: "INITIALIZE_RABBITMQ=1",
	"RUN_HAPROXY=0" 			: "RUN_HAPROXY=1",
}
TEXT_TO_SEARCH = [
	"RUN_MONGODB=0"       ,
	"INITIALIZE_MONGODB=0" ,
	"MONGODB_USE_SSL=0",
	"RUN_MARTSERVER=0",
	"RUN_REPORTS=0",
	"ENABLE_CONFIG_CONNECTION=0",
	"RUN_CONN_MGR=0",
	"RUN_MGMT_SRV=0",
	"RUN_DASHBOARD=0",
	"INITIALIZE_RABBITMQ=0",
	"RUN_HAPROXY=0",
	"RABBITMQ_SERVER="
]
TEXT_TO_REPLACE = [
	"RUN_MONGODB=1"       ,
	"INITIALIZE_MONGODB=1" ,
	"MONGODB_USE_SSL=1",
	"RUN_MARTSERVER=1",
	"RUN_REPORTS=1",
	"ENABLE_CONFIG_CONNECTION=1",
	"RUN_CONN_MGR=1",
	"RUN_MGMT_SRV=1",
	"RUN_DASHBOARD=1",
	"INITIALIZE_RABBITMQ=1",
	"RUN_HAPROXY=1",
	"RABBITMQ_SERVER=localhost"
]
TEXT_TO_SEARCH_FOR_SERVER_IP = [
	"MART_SERVER=",
	"CONN_MGR_ADDR=",
	"DASHBOARD_SERVER=",
	"AP_CONNECTION_MANAGER="
]
print "[## JK-01]  my_file :  Length = %s" %(len(TEXT_TO_SEARCH))
for idx in range(len(TEXT_TO_SEARCH)):
	text = TEXT_TO_REPLACE[idx]
	print "[## JK-01.1]  my_file :  text = %s" %(text)

new=open(FILE_WINGCLOUD_CONF_NEW,'w')
with open(FILE_WINGCLOUD_CONF, 'r') as f:
    for line in f.readlines():
		for idx in range(len(TEXT_TO_SEARCH)):
			text_search  = TEXT_TO_SEARCH[idx]
			text_replace = TEXT_TO_REPLACE[idx]
		        if text_search in line:
		            line = line.replace(text_search, text_replace)
		            print line
		new.write(line)
new.close()

local_ip="172.167.11.11"
new=open(FILE_WINGCLOUD_CONF_NEW,'w')
with open(FILE_WINGCLOUD_CONF, 'r') as f:
    for line in f.readlines():
		for idx in range(len(TEXT_TO_SEARCH_FOR_SERVER_IP)):
			text_search  = TEXT_TO_SEARCH_FOR_SERVER_IP[idx]
			text_replace = TEXT_TO_SEARCH_FOR_SERVER_IP[idx] + local_ip + '\n'
		        if text_search in line:
		            line = line.replace(text_search, text_replace)
		            print line
		new.write(line)
new.close()
