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
var dev_list = [
{ "_id" : [ "1112041B0001", "1112041B0002", "1112041B0003", "1112041B0004", "1112041B0005" ], "cc" : null },
{ "_id" : [ "1112040A0001", "1112040A0002", "1112040A0003", "1112040A0004", "1112040A0005" ], "cc" : null },
{ "_id" : [ "1112044C0001", "1112044C0002", "1112044C0003", "1112044C0004", "1112044C0005" ], "cc" : null },
{ "_id" : [ "1112043C0001", "1112043C0002", "1112043C0003", "1112043C0004", "1112043C0005" ], "cc" : null }
]

console.log("[Test-JK-1.1] : single_alarm -"+ JSON.stringify(dev_list));







console.log("[Test-JK-99] test_json : End <--------------")