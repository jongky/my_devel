import os
import json
from socket import *
from datetime import datetime
nsight_stats_period_min = 1

print "[## JK-01]  my_test :  Begin ---->"

dev_list = [
{ "_id" : [ "1112041B0001", "1112041B0002", "1112041B0003", "1112041B0004", "1112041B0005" ], "cc" : 0 },
{ "_id" : [ "1112040A0001", "1112040A0002", "1112040A0003", "1112040A0004", "1112040A0005" ], "cc" : 0 },
{ "_id" : [ "1112044C0001", "1112044C0002", "1112044C0003", "1112044C0004", "1112044C0005" ], "cc" : 0 },
{ "_id" : [ "1112043C0001", "1112043C0002", "1112043C0003", "1112043C0004", "1112043C0005" ], "cc" : 0 }
]
print "[## JK-01-01] my_test : length of dev_list= %s" %(str(len(dev_list)))

def get_nsight_stats_period():
    global nsight_stats_period_min
    try:
        ap_stats = {}
        ap_stats['i'] = 300
        nsight_stats_period = ap_stats['i']
        print "[### JK-DBG-2-01] nsight_stats_period = %d" %(nsight_stats_period)
        nsight_stats_period_min = nsight_stats_period/60
        print "[### JK-DBG-2-02] nsight_stats_period_min = %d" %(nsight_stats_period_min)
    except Exception as e:
        print "get_nsight_stats_period Exception %r" %(e)


def get_min_sampling_count(time_window):
    try:
        if time_window <= 19:
            print "[## JK-03-01] my_test : nsight_stats_period_min = %d" %(nsight_stats_period_min)
            min_sampling_count = time_window/float(2)/nsight_stats_period_min
            print "[## JK-03-02] my_test : min_sampling_count= %d" %(min_sampling_count)
            min_sampling_count = round(min_sampling_count)
            print "[## JK-03-03] my_test : min_sampling_count= %d" %(min_sampling_count)
        else:
            min_sampling_count = time_window/10/float(2)
            print "[## JK-03-04] my_test : min_sampling_count= %d" %(min_sampling_count)
            min_sampling_count = round(min_sampling_count)
            print "[## JK-03-05] my_test : min_sampling_count= %d" %(min_sampling_count)

    except Exception as e:
        print "get_sampling_count Exception %r" %(e)

    return min_sampling_count


def get_client_sampling_count(time_window):
    nsight_mu_stats_period_min = 5
    min_sampling_count = time_window/nsight_mu_stats_period_min         
    return min_sampling_count

time_window = 50
print "[## JK-01-02] my_test : get_nsight_stats_period"
get_nsight_stats_period()


print "[## JK-01-03] my_test : time_window= %d" %(time_window)
min_sampling_count = get_min_sampling_count(time_window)

print "[## JK-01-04] my_test : min_sampling_count= %d" %(min_sampling_count)

client_sampling_count = get_client_sampling_count(15)
print "[## JK-01-05] my_test : client_sampling_count= %d" %(client_sampling_count)


print "[## JK-099]  my_test :  End <----"
