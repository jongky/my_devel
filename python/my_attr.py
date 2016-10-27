import os
import sys


print "[## JK-01]  my_test :  Begin ---->"


class Session:
    def __init__(self, desc, username, address):
        # information used for cpu control on sessions
        self.pending_requests = {}
        self.stop_time = 0 
        self.start_time = 0 
        self.used_time = 0
        self.desc = desc
        self.user = username
        self.address = address
        self.cookie = 'test'

    def println(self):
        print "[## JK-03]  printIn: [Type= %s, User= %s: From=%s]" % (self.desc, self.user, self.address)

if __name__ == '__main__':

    print "[## JK-02]  my_test : Calling API --->"
    sess1 = Session("cli", "jlee", '192.168.0.1')
    sess2 = Session("web-ui", "fnwd64", '192.168.0.11')
    sess1.println()
    sess2.println()

    print "[## JK-04]  my_test : session.user= %s" %(sess1.user)

    if hasattr(sess1, 'cookie'):
        print "[## JK-05]  my_test : sess1 cookie exist with = %s" %(sess1.cookie)

    if hasattr(sess2, 'desc') and sess2.desc == "web-ui":
        print "[## JK-06]  my_test : sess2 desc exist and with = %s" %(sess2.desc)

    print "[## JK-099] my_test :  End <----"
