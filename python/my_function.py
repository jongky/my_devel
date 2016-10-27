
def function1(count):
    print "### :::: called function 1"

def function2(count):
    print "#### :::: called function 2 : count = %s" %(count)

def function3(count):
    print "#### :::: called function 3"


tokenDict = {"cat":function1, "dog":function2, "bear":function3}
print "############# >> process_alarm_mining= " 

functionToCall = tokenDict['dog']
print "############# >> process_alarm_mining= functionToCall = %s" %(functionToCall) 
count = 111
# and call it
functionToCall(count)
