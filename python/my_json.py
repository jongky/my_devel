import os
import json
from socket import *
from datetime import datetime

print "[## JK-01]  my_test :  Begin ---->"

option = {'hosts': ['JK-Cloud-AP1 84-24-8D-86-20-D4 15063522200943']}
print "[## JK-1.01]  my_json : option= %s" %(json.dumps(option))
hosts = option['hosts']
print "[## JK-1.02]  my_json : hosts = %s" %(json.dumps(hosts))
print "[## JK-1.03]  my_json : Length of hosts = %d" %(len(hosts))
host = hosts[0]
print "[## JK-1.04]  my_json : host = %s" %(host)
hostname = host.split(' ', 1)

print "[## JK-1.05]  my_json : hostname = %s" %(hostname[0])

alarm_buf = None
if not alarm_buf or alarm_buf is None:
	print "[## JK-013.1]  my_json : alarm_buf is None or Empty" 
else:
	print "[## JK-013.2]  my_json : alarm_buf= %s" %(alarm_buf)


alarm_buf = None
if alarm_buf is None:
	print "[## JK-011.1]  my_json : alarm_buf= None"
else:
	print "[## JK-011.2]  my_json : alarm_buf= %s" %(alarm_buf)

alarm_buf = {}
if not alarm_buf:
	print "[## JK-012.1]  my_json : alarm_buf= Empty"
else:
	print "[## JK-012.2]  my_json : alarm_buf= %s" %(alarm_buf)

runtime = datetime.utcnow()
isotime = datetime.utcnow().isoformat()
print "[## JK-02.1]  my_json : runtime= %s" %(runtime)
print "[## JK-02.2]  my_json : isotime= %s" %(isotime)
db_idx = isotime + "@" + "jk-test"
print "[## JK-02.3]  my_json : db_idx= %s" %(db_idx)


alarm_buf['grp']   = 'security'
alarm_buf['state'] = 'happen'
alarm_buf['src']   = 'device'
alarm_buf['sev']   = 'major'
print "[## JK-03]  my_json : alarm_buf= %s" %(json.dumps(alarm_buf))

total_fdn = []
fdn = {}
fdn['rfd']  = "1003"
fdn['apid'] = "AP-JKLab1"
fdn['apip'] = "192.168.0.133"
fdn['vlan'] = 1
total_fdn = [fdn]
print "[## JK-04]  my_json : fdn= %s" %(json.dumps(total_fdn))
alarm_buf['fdn'] = total_fdn
print "[## JK-05]  my_json : alarm_buf= %s" %(json.dumps(alarm_buf))


my_json = [1, 2]
if my_json is None:
	print "[## JK-06]  my_json : Length= %d"  %len(my_json)
else:
	print "[## JK-07]  my_json : Length= %d"  %len(my_json)

my_test = ['details', 'AA:BB:CC:DD']
print "[## JK-08]  my_test : my_test= %s" %(json.dumps(my_test))
print "[## JK-08.1]  my_test : my_test[0]= %s" %(json.dumps(my_test[0]))

my_test1[0] = 'details'
print "[## JK-09]  my_test : my_test1= %s" %(json.dumps(my_test1))

print "[## JK-099]  my_test :  End <----"
