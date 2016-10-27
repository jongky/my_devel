import socket
import smtplib

print "[## JK-01]  my_test :  Begin ---->"
def send_email():
    url = ''
    smtp_config = {"smtp_server" : "smtp.gmail.com", 
                   "security" : "ssl", 
                   "username" : "jongkylee", 
                   "password" : "Let'sDoitnow", 
                   "sender" : "ZEBRA Admin", 
                   "recipent_email" : "jongkylee@gmail.com", 
                   "sendto_email" : 
                        [ "fnwd64@zebra.com" ] }
    smtp_server   = smtp_config['smtp_server']
    smtp_security = smtp_config['security']
    smtp_username = smtp_config['username']
    smtp_password = smtp_config['password']
    smtp_sender   = smtp_config['sender']
    smtp_recipent_email = smtp_config['recipent_email']
    sendto_emails = smtp_config['sendto_email']

    subject = 'Alarm Information from WingSystem'
    msg = "JK-Test"
    smtp_message = 'Subject: %s\n\n%s' % (subject, msg)

    print "[## JK-10.01] my_test :  smtp_message= %s" %(smtp_message)
    print "[## JK-10.02] my_test :  sendto_emails= %s" %(sendto_emails)

    # Send the message via our own SMTP server, but don't include the
    # envelope header.
    try:
        s = smtplib.SMTP(smtp_server)
        s.starttls()
        s.login(smtp_recipent_email, smtp_password)
        for sendto_email in sendto_emails:
            # dlog("send_email : sendto_email is %s" %sendto_email)
            s.sendmail(smtp_recipent_email, [sendto_email], smtp_message)
            print "Sent Mail Successfully."         
    except Exception,e:
        print "Failed to Send mail."
        print str(e)
    else:
        s.quit()

send_email()
print "[## JK-99]  my_test :  End ---->"



