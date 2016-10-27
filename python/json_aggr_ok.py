import json

print("[## JK-01] Test for Alarm Aggregation....===>")
alarm1 = {'grp':'network', 'sev':'majr', 'name':'DHCP fail'}
alarm2 = {'grp':'network', 'sev':'majr', 'name':'DNS fail'}

events = []

def add_event_data(event):

	events.append(event)
	print "[## JK-11.1] events = %s" %(events)
	length = len(events)
	print "[## JK-11.2] Lenght of events = %s" %(length)


str_alarm1 = json.dumps(alarm1)
str_alarm2 = json.dumps(alarm2)
print "[## JK-02.1] alarm1 = %s" %(str_alarm1)
print "[## JK-02.2] alarm2 = %s" %(json.dumps(alarm2))

merged_alarm = []
merged_alarm.append(alarm1)
merged_alarm.append(alarm2)
print "[## JK-02.3] merged_alarm = %s" %(merged_alarm)
length = len(merged_alarm)
print "[## JK-02.4] Lenght of merged_alarm = %s" %(length)

add_event_data(alarm1)
add_event_data(alarm2)

print("[## JK-099] This is End Test Python...<====.")

