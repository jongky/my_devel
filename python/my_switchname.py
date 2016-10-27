from datetime import datetime, timedelta
import time

print("[## JK-01] Test for Take Switch Name....")


param = {}
switch = {}
switches = []
switch_port1 = "rfs4000-6F8CAE:ge4"
switch_port2 = "rfs4000-6F8CAE:ge3"
offline_by_switch = []
switch_info1 = {"id": 'rfs4000-6F9CAE', 'rfd':'noc', 'num_offline' : 5}
switch_info2 = {"id": 'rfs4000-6F9CAE', 'rfd':'noc', 'num_offline' : 5}

print"[## JK-02] switch= %s" %(switch)
switch_name = switch_port1.split(":")
switch['id'] = switch_name[0]
switch['rfd'] = 'noc'
print"[## JK-03] switch_name= %s" %(switch)
switches.append(switch)
print"[## JK-04] [1] switches= %s" %(switches)

switch = {}
switch_name = switch_port2.split(":")
switch['id'] = switch_name[0]
switch['rfd'] = 'default'
print"[## JK-05] switch_name= %s" %(switch)
switches.append(switch)
print"[## JK-06] [1] switches= %s" %(switches)

"""
if not hasattr(switches, switch):
	print"[## JK-04] Adding switch_name= %s" %(switch)
	switches[switch] = 'default'
	print"[## JK-05] Adding switch_names= %s" %(switches)
	offline_by_switch.append(switch_info1)
	print"[## JK-08.1] Adding switch_names= %s" %(switches)
	print"[## JK-08.2] Adding offline_by_switch= %s" %(offline_by_switch)

switch_port2 = "rfs4000-6F9CAE:ge3"
switch_name = switch_port2.split(":")
switch = switch_name[0]
print"[## JK-06] switch_name= %s" %(switch)
if not hasattr(switches, switch):
	print"[## JK-07] Adding switch_name= %s" %(switch)
	#switch_names[switch]['state'] = 1 
	switches[switch] = 'noc'
	offline_by_switch.append(switch_info2)
	print"[## JK-09.1] Adding switch_names= %s" %(switches)
	print"[## JK-09.2] Adding offline_by_switch= %s" %(offline_by_switch)

"""
op_data = {}
for entry in switches:
	print"[## JK-09] entry= %s" %(entry)

print"[## JK-11] op_data= %s" %(op_data)
