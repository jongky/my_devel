import os
from socket import *

print "[## JK-01]  my_EventFile :  Begin ---->"
EVENT_LIST_FILE = 'event_list.txt'

"""
EventID = []
with open('event_list.txt','r') as f:
    for line in f:
        word = line[:max(line.find(' '), 0) or None]
        if word:
            print word

"""
file = open(EVENT_LIST_FILE, 'r')
for line in file:
    line = line.replace("\"", "")
    # print line
    index = 0
    for word in line.split(','):
        if index == 2:
            print word
            break
        index += 1


print "[## JK-099]  my_test :  End <----"
