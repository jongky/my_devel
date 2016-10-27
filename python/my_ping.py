#!/usr/bin/python
import pexpect
import os
import subprocess
from socket import *

print("[## JK-01] This os my Ping Test Python....")
# child = pexpect.spawn('ping 157.235.91.230')

#while 1:
#        line = child.readline()
#        if not line: break
#        print line,
'''
response = os.system("ping -c 5 157.235.91.230 > aa.txt")
print 
print("[## JK-02] This os my Ping Test Python....")

while 1:
        line = response.readline()
        if not line: break
        print line,
'''
out = "Test"
print("[## JK-02] This is my CAT Test Python....")
proc = subprocess.Popen(["ping", "-c 4", "157.235.91.230"], stdout=subprocess.PIPE)
#(out, err) = proc.communicate()

for line in iter(proc.stdout.readline,''):
	print "Test =11 "
	print "Line= ", line
	print line.rstrip()

#stddata = proc.communicate()

#output = proc.stdout.readline()

print("[## JK-03] This is Output of my CAT Test Python....")
print "program output:", out