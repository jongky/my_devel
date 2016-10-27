
import stackless
import sleep

def sender(chan, value):
    print "[## JK-DBG-1] sender: Starting --->"
    for x in range(0, 10):
    	print "[## JK-DBG-1.1] sender: Sending Data : %s" %format(x) 
    	chan.send(x)
    	sleep(3)


def receiver(chan):
    print "[## JK-DBG-2] receiver: Receiving on chan= %s" %format(chan) 
    value = chan.receive()
    print "[## JK-DBG-2] receiver: Receiving value= %s" %format(value) 

chan = stackless.channel()
print "[## JK-DBG-1] channel: channel= %s" %format(chan) 

stackless.tasklet(receiver)(chan)
stackless.run()
stackless.tasklet(sender)(chan)
stackless.run()



