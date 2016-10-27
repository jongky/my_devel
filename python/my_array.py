from datetime import datetime, timedelta
import time
# from tzlocal import get_localzone

print("[## JK-01] Test for Datetime....")
# child = pexpect.spawn('ping 157.235.91.230')

alarm_buf = {};
alarm_buf['lts']   = datetime.utcnow()
lts   = datetime.utcnow()
print "[## JK-01.01] alarm_buf = %s" % (alarm_buf['lts'])

time.sleep(15)
cur_time   = datetime.utcnow()
tm = datetime.utcnow() - timedelta(seconds=10)

print "[## JK-01.02] tm = %s" % (tm)
print "[## JK-01.03] cur_time = %s" % (cur_time)
print "[## JK-01.04] lts = %s" % (lts)

if tm > lts:
	print "[## JK-01.05] tm is bigger than lts = %s" % (lts)
else:
	print "[## JK-01.06] lts is bigger than tm = %s" % (lts)

"""
a = datetime.now()
print "[## JK-01.01] Time = %s:%s.%s" % (a.minute, a.second, str(a.microsecond)[:2])


t = datetime.now()
print("[## JK-01.2] t= %s" %t)

minutes = 1
tm = datetime.now() + timedelta(minutes=minutes)
print("[## JK-01.3] tm= %s" %tm)

seconds = 60
tm = datetime.now() - timedelta(seconds=seconds)
print("[## JK-01.4] tm= %s" %tm)
"""
print("[## JK-02] This is Output of my CAT Test Python....")
