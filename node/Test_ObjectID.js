
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