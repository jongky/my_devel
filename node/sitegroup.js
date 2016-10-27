/*****************************************************************
 * Filename : sitegroup.js
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

console.log("[Test-JK-01] sitegroup : Begin -------------->")

var sitegroup = "/System/US/SantaClara/SanJose/CA/noc";
console.log("[Test-JK-1.1] : sitegroup [string]= " + sitegroup);

sitegroup = sitegroup.replace(/.*\//g, "");
console.log("[Test-JK-1.2] : sitegroup [string]= " + sitegroup);


console.log("[Test-JK-99] test_json : End <--------------")