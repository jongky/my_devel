import os
import json
from socket import *
from datetime import datetime
import string

print "[## JK-01]  my_test :  Begin ---->"
version = "alarm_2.2"
print "[## JK-01.1]  my_test :  version= %s" %(version);
old_alarm_version = version.split("_")
print "[## JK-01.2]  my_test :  old_alarm_version= %s" %(old_alarm_version[1]);
old_version_val = float(old_alarm_version[1])
print "[## JK-01.3]  my_test :  old_version_val= %f" %(old_version_val);

new_version = "alarm_2.3"
print "[## JK-02.1]  my_test :  new_version= %s" %(new_version);
new_alarm_version = new_version.split("_")
print "[## JK-02.2]  my_test :  new_alarm_version= %s" %(new_alarm_version[1]);
new_version_val = float(new_alarm_version[1])
print "[## JK-02.3]  my_test :  new_version_val= %f" %(new_version_val);

if new_version == 'alarm_2.3' and new_version_val > old_version_val:
	print "[## JK-04.1]  my_test :  Need to initialize all Alarm Log Tables"
else:
	print "[## JK-04.2]  my_test :  No Need to initialize all Alarm Log Tables"


print "[## JK-099]  my_test :  End <----"
