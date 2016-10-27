import json

events = []
class EventQueue(object):

    def __init__(self):
        print "****Cloud Event Queue Initialized****"
        self.events = []

    def add_event_data(self, event):

        print "[## JK-DBG-11] add_event_data] event= %s" %(event)
        json_event = json.dumps(event)
        print "[## JK-DBG-12] add_event_data] json_event= %s" %(json_event)
        events.append(event)
        print "[## JK-DBG-13] add_event_data] events= %s" %(str(events))

        #agg_events = agg_events.append(alarm2)
        #print "[## JK-DBG-14] add_event_data] events= %s" %(str(agg_events))

    def get_event_data(self):
        return events

    def reset_event_data(self):
        del events

print("[## JK-01] Test for Alarm Aggregation....===>")
alarm1 = {'grp':'network', 'sev':'majr', 'name':'DHCP fail'}
alarm2 = {'grp':'network', 'sev':'majr', 'name':'DNS fail'}

print "[## JK-01.1] alarm1 = %s" %(alarm1)

str_alarm1 = json.dumps(alarm1)
str_alarm2 = json.dumps(alarm2)
print "[## JK-02.1] alarm1 = %s" %(str_alarm1)
print "[## JK-02.2] alarm2 = %s" %(json.dumps(alarm2))

test = EventQueue()
test.add_event_data(alarm1)
test.add_event_data(alarm2)

print("[## JK-099] This is End Test Python...<====.")
