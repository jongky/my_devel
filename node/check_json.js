/*****************************************************************
 * Filename : check_json.js
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
var alarms = "{'grp':'security','name':'DOS Attack detected'}";
// {"alarm":"{'src': 'RFD', 'state': 'happen', 'sname': 'Tuba City-1003', 'name': 'DOS Attack detected', 'grp': 'security', 'sev': 'major', 'ip': '19.235.0.1', 'desc': 'DOS Attack detected 10 times within 1 minute', 'mac': '11-12-03-EB-00-01', 'fdn': [{'apid': 'ap-10031', 'vlan': 1, 'apip': '19.235.0.1', 'muid': 'AA-BB-FA-D0-13-01', 'rfd': '1003'}]}"};
console.log("[Test-JK-1.1] : alarms [string]= " + alarms);
console.log("[Test-JK-1.2] : alarms = "+ JSON.stringify(alarms));

// var json_alarms= jsonParser.parse(alarms);
var json_alarms= alarms;
console.log("[Test-JK-1.3] : JSON Parsed alarms = "+ json_alarms);

var group = json_alarms['grp'];

console.log("[Test-JK-1.4] : alarm group = "+ JSON.stringify(group));


var str = '{"city": "Tampa", "state": "Florida"}, {"city": "Charlotte", "state": "North Carolina"}';
str = '[' + str + ']';
var jsonobj = $.parseJSON(str);

console.log("[Test-JK-99] test_json : End <--------------")