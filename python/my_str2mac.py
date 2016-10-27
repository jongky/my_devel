from datetime import datetime, timedelta
import time

print("[## JK-01] Test for Str2Mac....")

def str2mac(s):
    try:
        # """ convert a text MAC address into a binary form (a 6-char string) """
        return ''.join([chr(int(x,16)) for x in s.split(s[2])])
    except:
        # allow for the possibility that the MAC address had no separators. (i.e., AABBCCDDEEFF)
        return ''.join([chr(int(x,16)) for x in [s[y:y+2] for y in range(0,12,2)]])

param = {}
param_str = {}
param["debug_client_mac"] = "00-21-6A-65-FC-01 00-21-6A-65-FC-02 "

# Handle Client MAC 
debug_client_mac_list_str = param["debug_client_mac"]
print "[## JK-01.01] debug_client_mac_list_str = %s" % (debug_client_mac_list_str)

debug_client_mac_list = debug_client_mac_list_str.split(" ")
print "[## JK-01.02] debug_client_mac_list = %s" % (debug_client_mac_list)

# param_str += struct.pack(">I", len(debug_client_mac_list))
client_num = len(debug_client_mac_list)
print "[## JK-01.03] client_num = %s" % (client_num)

for client_mac in debug_client_mac_list:
	print "[## JK-01.04] client_mac = %s" % (client_mac)
	if client_mac:
		client = str2mac(client_mac)
	# param_str += struct.pack("6s",str2mac(client_mac))
	print "[## JK-01.05] param_str = %s" % (param_str)

param_ff = {}
param_ff["debug_client_mac"] = ["FF:FF:FF:FF:FF:FF"]

# Handle Client MAC 
debug_client_mac_list_str = param_ff["debug_client_mac"]
print "[## JK-01.01] debug_client_mac_list_str = %s" % (debug_client_mac_list_str)

if type(debug_client_mac_list_str) == type([]):
	debug_client_mac_list = debug_client_mac_list_str[0].split()
	print "[## JK-01.02] debug_client_mac_list = %s" % (debug_client_mac_list)

# param_str += struct.pack(">I", len(debug_client_mac_list))
client_num = len(debug_client_mac_list)
print "[## JK-01.03] client_num = %s" % (client_num)

for client_mac in debug_client_mac_list:
	print "[## JK-01.04] client_mac = %s" % (client_mac)
	if client_mac:
		client = str2mac(client_mac)
	# param_str += struct.pack("6s",str2mac(client_mac))
	print "[## JK-01.05] param_str = %s" % (param_str)

print("[## JK-02] End of Test ==============>")
