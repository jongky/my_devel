import socket
import smtplib
import subprocess

print "[## JK-01] send_sms :  Begin ---->"
def auth ():
    """
    Authenticate against the Clickatell API server
    """
    url = 'http://api.clickatell.com/http/auth?user=%s&password=%s&api_id=%s' % ('natarajann', 'zebra123', '3487622')
    post = [
        ('user', 'natarajann'),
        ('password', 'zebra123'),
        ('api_id', '3487622'),
    ]
    print 'MS dbg: Call curl() function to send auth request to Clickatell server'
    result = curl_send('auth')
    if result[0] == 'OK':
        print "[## JK-11.02] auth :  result= %s" %(result[0])
        assert (32 == len(result[1]))
        session_id = result[1]
        has_authed = True
        return True
    else:
        return False

def curl_send(command, msg_to = None, message=None):
    if command == 'auth':
        url = 'http://api.clickatell.com/http/%s?user=%s&password=%s&api_id=%s' % (command, 'natarajann', 'zebra123', '3487622')
    elif command == 'sendmsg':
        url = 'http://api.clickatell.com/http/%s?user=%s&password=%s&api_id=%s&to=%s&text=%s&mo=1&from=17752374455' % (command, 'natarajann', 'zebra123', '3487622', msg_to, message)

    curl_cmd = '/usr/bin/curl "%s"' % url
    print 'MS dbg: curl_cmd: %s' % curl_cmd
    p = subprocess.Popen(curl_cmd,  stdout = subprocess.PIPE, stderr=subprocess.STDOUT, close_fds = True, shell = True)
    output, errors = p.communicate()
    print 'MS dbg: output: %s' % output
    ret = output.split("\n")
    ret_val = ret[3].split(": ")
    print 'CP dbg: curl_cmd, ret_val[0]: %s, ret_val[1]: %s ' % (ret_val[0], ret_val[1])
    return ret_val


def send_sms():
    url = ''
    sms_config = { "username" : "natarajann", 
                    "password" : "zebra123", 
                    "api_id" : "3487622", 
                    "user_agent" : "", 
                    "source_number" : "14083151235", 
                    "sendto_phone" : 
                        [ "14083151235"] 
                }

    send_cmd_str = ''
    sms_username = sms_config['username']
    sms_password = sms_config['password']
    sms_api_id   = sms_config['api_id']
    user_agent   = sms_config['user_agent']
    sms_source_number = sms_config['source_number']
    sms_source_number = 0
    sendto_phone = sms_config['sendto_phone']

    subject = 'Alarm Information from WingSystem'
    msg = "JK-Test"

    print "[## JK-10.01] send_sms :  sms_message= %s" %(msg)
    print "[## JK-10.02] send_sms :  sendto_phone= %s" %(msg)

    for sms_to in sendto_phone:
        result = curl_send('sendmsg', sms_to, msg)
        print "[## JK-10.03] send_sms :  Sent message[%s] to [%s]" %(msg, sms_to)

"""
    for sms_to in sendto_phone:
        if sms_source_number:
            url = 'http://api.clickatell.com/http/%s?user=%s&password=%s&api_id=%s&to=%s&text=%s&mo=1&from=%s' % (send_cmd_str, sms_username, sms_password, sms_api_id, sms_to, sms_message, sms_source_number)
        else:
            url = 'http://api.clickatell.com/http/%s?user=%s&password=%s&api_id=%s&to=%s&text=%s' % (send_cmd_str, sms_username, sms_password, sms_api_id, sms_to, sms_message)

        # url = 'https://api.clickatell.com/http/sendmsg?user=jongkylee&password=LaAFFUfOXGbPQA&api_id=3552440&to=14083151235&text=TestFromLinux'
        # url = 'https://api.clickatell.com/http/sendmsg?user=jongkylee&password=LaAFFUfOXGbPQA&api_id=3552440&to=14083151235&text=%s' %message
        final_cmd = '/usr/bin/curl "%s"' % url
        print "[## JK-10.03] send_sms :  final_cmd= %s" %(final_cmd)

        try:
            p = subprocess.Popen(final_cmd,  stdout = subprocess.PIPE, stderr=subprocess.STDOUT, close_fds = True, shell = True)
            output, errors = p.communicate()
            ret = output.split("\n")
            ret_val = ret[3].split(": ")

            # dlog_guest_management('GN: send_sms(), ret_val[0] %s, ret_val[1] %s ', ret_val[0], ret_val[1])
            ctell_gw_reachable = 'Yes' 
            if send_cmd_str == 'getbalance':
                if ret_val[0] == 'Credit':
                    ctell_gw_avail_credit = ret_val[1]
                else:
                    ctell_gw_avail_credit = ret_val[0]+ret_val[1]
                print "[## JK-10.04] send_sms :  ctell_gw_avail_credit= %s" %(ctell_gw_avail_credit)

        except: 
            # dlog_guest_management('GN: send_sms(), unable to reach sms gateway server')
            ret_val = False
            ctell_gw_reachable = 'No' 
"""

auth()
send_sms()
print "[## JK-99] send_sms :  End ---->"



