import os
import json
from socket import *
from datetime import datetime
import sys

val = 70
new_val = 70/100


option= {"hosts":"84-24-8D-15-E9-20","capture_opts":{"count":20},"bridge":{}}

print "[## JK-01]  my_test :  Begin ---->: option= %s" %(json.dumps(option))
if "hosts" in option:
    hostnames_or_domain = option["hosts"]
hostnames_or_domain1 = {"84-24-8D-15-E9-20"}
print "[## JK-02.1]  my_test :  Begin ---->: capture_source= %s" %(hostnames_or_domain1)
print "[## JK-02.2]  my_test :  Begin ---->: capture_source= %s" %(hostnames_or_domain)

if type(hostnames_or_domain) == type([]):
	print "[## JK-03.1]  my_test :  Begin ---->: hostnames_or_domain= %s" %(hostnames_or_domain)
elif type(hostnames_or_domain) == type({}):
	print "[## JK-03.2]  my_test :  Begin ---->: hostnames_or_domain= %s" %(hostnames_or_domain)
elif type(hostnames_or_domain) == type("" ):
	print "[## JK-03.3]  my_test :  Begin ---->: hostnames_or_domain= %s" %(hostnames_or_domain)
else : # rfdomain
	print "[## JK-03.4]  my_test :  Begin ---->: hostnames_or_domain= %s" %(hostnames_or_domain)

pkt_args = "['-i ge1 -c 10 icmp', {'locations': [['-i', 'ge1']]"
print "[## JK-01]  my_test :  Begin ---->: pkt_args= %s" %(json.dumps(pkt_args))
pkt_args = pkt_args.split(" ")
print "[## JK-02]  my_test :  Begin ---->: pkt_args= %s" %(json.dumps(pkt_args))

print "[## JK-01]  my_test :  Begin ---->: new_val= %x" %(new_val)
print "[## JK-01]  my_test :  Begin ---->"
def init_fdn_info():
	fdn['rfd']  = 0
	fdn['ip']   = 0
	fdn['mac']  = 0
	fdn['vlan'] = 0
	fdn['radio']= 0
	fdn['wlan'] = 0
	return fdn

fdn = {}
fdn = init_fdn_info()
fdn['rfd'] = 'default'
print "[## JK-01]  my_test :  fdn= %s" %format(fdn) 


alarm_buf = {};
runtime = datetime.utcnow()

new_exp_time = "12:00:00"
new_exp_date = str(runtime).split(' ')[0]
new_date_time = str(new_exp_date) + ' ' + str(new_exp_time)
isotime = datetime.utcnow().isoformat()

print "[## JK-02.1]  my_json : runtime= %s" %(runtime)
print "[## JK-02.2]  my_json : new_exp_date= %s" %(new_exp_date)
print "[## JK-02.3]  my_json : new_exp_time= %s" %(new_exp_time)
print "[## JK-02.4]  my_json : isotime= %s" %(isotime)
print "[## JK-02.5]  my_json : JSON isotime= %s" %(json.dumps(isotime.isoformat()))
# db_idx = isotime + "@" + "jk-test"
# print "[## JK-02.3]  my_json : db_idx= %s" %(db_idx)


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


print "[## JK-099]  my_test :  End <----"
