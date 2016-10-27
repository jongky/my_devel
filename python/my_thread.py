import os
import json
from socket import *
from datetime import datetime
# import stackless
import threading

print "[## JK-01]  my_test :  Begin ---->"

alarm_buf = {};
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


print "[## JK-099]  my_test :  End <----"
