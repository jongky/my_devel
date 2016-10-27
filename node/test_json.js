/*****************************************************************
 * Filename : test_json.js
 * Component: Node Test Module
 * Subsystem: 
 *
 *    Copyright Zebra Technology 2015, All Rights Reserved
 *
 * File Overview
 * ------------
 *    This will do the basic API testing for MartServer
 *
 * ************************************************************/

console.log("[Test-JK-01] test_json : Begin -------------->")

var total_length = 1;
var single_alarm = {"grp":"security","name":"DOS Attack detected","state":"active","src":"RFD","sev":"critical","sname":"Quinton-1001","ip":"19.233.0.1","mac":"11-12-03-E9-00-01","fdn":[{"rfd":"1001","apid":"ap-10011","apip":"19.233.0.1","vlan":1,"muid":"AA-BB-FA-50-16-01"}],"desc":"DOS Attack detected 10 times within 1 minute"};
var alarms = [
	{"grp":"security","name":"DOS Attack detected","state":"active","src":"RFD","sev":"critical","sname":"Quinton-1001","ip":"19.233.0.1","mac":"11-12-03-E9-00-01","fdn":[{"rfd":"1001","apid":"ap-10011","apip":"19.233.0.1","vlan":1,"muid":"AA-BB-FA-50-16-01"}],"desc":"DOS Attack detected 10 times within 1 minute"},
	{"grp":"network","name":"Captive Portal Auth Failure","state":"active","src":"RFD","sev":"critical","sname":"Quinton-1001","ip":"19.233.0.3","mac":"11-12-03-E9-00-03","fdn":[{"rfd":"1001","apid":"ap-10013","apip":"19.233.0.3","vlan":1,"muid":"AA-BB-FA-50-32-01"}],"desc":"Captive Portal Authentication to 172.28.11.23 failed 6 times within 1 minute"}];

    console.log("[Test-JK-1.1] : single_alarm -"+ JSON.stringify(single_alarm));

	if (Array.isArray(single_alarm) ) {
	    total_length = single_alarm.length;
	    console.log("[Test-JK-1.2] : alarm is Array : Total Length = " + total_length);
	}
	else
	    console.log("[Test-JK-1.2] : alarm is not Array : Total Length = " + total_length);

    for(idx = 0; idx < total_length; idx += 1) 
    {
    	if (Array.isArray(single_alarm))
    	{
    		alarm = single_alarm[idx];
    	}
    	else 
    		alarm = single_alarm;


	    console.log("[Test-JK-1.3] : alarm.fdn.rfd -"+ alarm.fdn[0].rfd);
	    console.log("[Test-JK-1.4] : alarm -"+ JSON.stringify(alarm));
	    
    	var group = alarm['grp'];
	    console.log("[Test-JK-1.5] : alarm group = "+ JSON.stringify(group));
    }





console.log("[Test-JK-99] test_json : End <--------------")