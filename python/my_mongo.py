#########################################################################
#  Filename : my_mongo.py
#  Purpose  : Insert & Query mongodb
#  Date     : 02/24/2016
#  Editor   : Jongky Lee
#########################################################################

import pymongo
from pymongo import MongoClient
import time
from datetime import datetime, timedelta
from datetime import datetime as dt


print("[## JK-01] my_mongo : Begin..===>")

#########################################################################
# Function : create_alarm_notif
#########################################################################
def create_alarm_notif():
	alarm_notif = {
		"idx" : 1,
		"purge" : {
			"threshold_limit" : "50000",
			"aging_out" : "365"
		},
		"syslog" : {
			"server" : [
				"192.168.0.100"
			]
		},
		"sms" : {
			"username" : "natarajann",
			"password" : "zebra123",
			"api_id" : "3487622",
			"user_agent" : "aa",
			"source_number" : "17144185711",
			"sendto_phone" : [
				"14083151235"
			]
		},
		"smtp" : {
			"smtp_server" : "smtp.gmail.com",
			"security" : "ssl",
			"username" : "jongkylee",
			"password" : "jkLEExxxx",
			"sender" : "Jongky Lee",
			"recipent_email" : "jongkylee@gmail.com",
			"sendto_email" : [
				"fnwd64@zebra.com"
			]
		},
		"created_ts" : "2016-02-24T00:28:40.412Z"
	}

	print "[## JK-02.1] create_alarm_notif: Begin" 
	client = MongoClient()
	client = MongoClient("localhost", 27017)
	db = client.mart
	col = db.alarm_not
	id = col.insert(alarm_notif)
	print "[## JK-02.2] create_alarm_notif: id = %s" %(id)

#########################################################################
# Function : create_alarm_notif
#########################################################################
def query_alarm_notif():
	print "[## JK-03.1] query_alarm_notif: Begin" 
	client = MongoClient()
	client = MongoClient("localhost", 27017)
	db = client.mart
	col = db.alarm_not
	alarm_not = col.find_one()
	print "[## JK-03.2] query_alarm_notif: alarm_not = %s" %format(alarm_not)

#########################################################################
# Function : create_alarm_notif
#########################################################################
def create_alarm_log():
	alarm_log = {
        "grp"       : "network",
        "name"      : "DHCP Failure",
        "state"     : "active",
        "src"       : "RFD",
        "sev"       : "major",
        "sname"     : "SanJose-107",
        "tenant_id" : 1001,
        "fdn"       : {
                "rfd"   : "JK-Home", 
                "mac"   : "84-24-8d-18-85-f9", 
                "ip"    : "157.215.91.177", 
                "vlan"  : "1", 
                "muid"  : "11-22-33-44-55-66",
        }, 
        "desc"      : "DHCP fail detected 5 times within 1 minute"
    }

	my_input = input("Enter the Number to insert for AlarmLog : ")

	print "[## JK-04.1] create_alarm_notif: Begin" 
	client = MongoClient()
	client = MongoClient("localhost", 27017)
	db = client.mart
	col = db.alarm_log
	i = 0 
	while i < my_input:
		alarm_log["rts"] = datetime.utcnow()
		alarm_log["_id"] = datetime.utcnow()
		id = col.insert(alarm_log)
		time.sleep(2)
		i = i + 1
		print "[## JK-04.2] create_alarm_log: [%s] alarm_log = %s" %(i, format(alarm_log))
	
	print "[## JK-04.3] create_alarm_log: Inserted Total[%s] alarm_log " %(my_input) 



#########################################################################
# Function : create_alarm_notif
#########################################################################
def query_alarm_log_last_minute():
	print "[## JK-05.1] query_alarm_log_last_minute: Begin" 
	client = MongoClient()
	client = MongoClient("localhost", 27017)
	db = client.mart
	col = db.alarm_log

	match_time = {}
	cur_time = dt.utcnow()
	delta = cur_time - timedelta(seconds=120)
	match_time['rts'] = {"$gte" : delta}    

	print "[## JK-05.2] query_alarm_log_last_minute: match_time = %s" %format(match_time)
	records = col.find({"$and":[{"tenant_id": 1001}, match_time ]})
	print "[## JK-05.3] query_alarm_log_last_minute: count = %s" %(records.count())


"""

#********************************************************************************
# * Function    : main Entry point
# * Description : This funtion has multiple API to emulate/test Alarm handler APIs
# * Collection  : N/A
# * Input       : 
# *
# * Output      : 
# *
# * ******************************************************************************/
"""

print " My Mongo Test : This is main starting for MongoDB Simulator --> "
print "#################################################################"
print "#  [1]  Create AlarmNotif DB entry "
print "#  [2]  Query & Display AlarmNotif from DB"
print "#  [3]  Create Alarm log "
print "#  [4]  Query Last Minute Alarm log "
print "#----------------------------------------------------------------"
print "#  [0]  to Exit"
print "#----------------------------------------------------------------"
print "#################################################################"
my_input = input("Enter the Number to execute : ")

if my_input == 1:
	create_alarm_notif()
elif my_input == 2:
	query_alarm_notif()
elif my_input == 3:
	create_alarm_log()
elif my_input == 4:
	query_alarm_log_last_minute()
else:
	print "[## JK-099]  [Exit] This is End Test Python...<====."
	exit()

print "[## JK-099] This is End Test Python...<====."


