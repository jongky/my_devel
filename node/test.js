
var alarms = [
	{ "_id" : "1001", "impacted_devices" : 6 },
	{ "_id" : "1002", "impacted_devices" : 3 },
	{ "_id" : "1003", "impacted_devices" : 3 }
];

var alarms_new = [
	{ "_id" : "1001", "critical" : 11 },
	{ "_id" : "1002", "critical" : 22 },
	{ "_id" : "1003", "critical" : 33 }
];
console.log("[Test-JK-1.1] : alarm= " + JSON.stringify(alarms));
console.log("[Test-JK-1.1] : alarms_new= " + JSON.stringify(alarms_new));

var alarm = {};
for (var i = 0; i < alarms.length; i++) {
	alarm = alarms[i];
	
	alarm['critical'] = alarms_new[i].critical;
	console.log("[Test-JK-1.2] : alarm= " + JSON.stringify(alarm));
}



var severity = ['Critical', 'Major', 'Minor'];     
console.log("[Test-JK-11.1] : severity= " + JSON.stringify(severity));
var alarm_default_name = [
	{'name' : 'AAA'}, {'name' : 'BBB'}, {'name' : 'CCC'}];
var alarm_name =[];
var doc = {};
var length = alarm_default_name.length;
for (var i = 0; i < length; i++)
{
	var alarm_list = alarm_default_name[i];
	console.log("[Test-JK-11.2] : alarm_list= " + JSON.stringify(alarm_list));
	alarm_name.push(alarm_list['name']);
	console.log("[Test-JK-11.3] : alarm_name= " + JSON.stringify(alarm_name));       
}
doc['severity'] = severity;
doc['alarm_name'] = alarm_name;
console.log("[Test-JK-11.4] : doc= " + JSON.stringify(doc));       

