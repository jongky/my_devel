
console.log("[## JK-01]  my_test :  Begin ---->")
var doc=[{"_id":2,"count":12},{"_id":7,"count":2},{"_id":6,"count":1},{"_id":5,"count":8},{"_id":4,"count":18},{"_id":3,"count":54}]
console.log("[## JK-02.1] doc: " + JSON.stringify(doc));
console.log("[## JK-02.1] doc[0]: " + JSON.stringify(doc[0]));

var dayOfWeek = ['Monday','Tuesday','Wednesday','Thursday','Friday','Saturday','Sunday'];
        for (var i = 1; i <= 7; i++) {
        	if (doc[i-1])
            	doc[i-1]["_id"] = dayOfWeek[i];
        }
console.log("[## JK-DBG-011] get_alarm_summary_by_timeline: doc= ", JSON.stringify(doc));


var alarm_from_dpd = {"_id":"2016-01-29T01:51:11.000Z@jk-test","grp":"network","name":"DHCP failure","rts":"1927-11-03T14:45:31.000Z","state":"raise","src":"AP7532","sname":"AP-JKLab1","sev":"major","desc":"DHCP failed 3 times in 10 mins","fdn":{"rfd":"jk-test","mac":"84-24-8D-82-B8-CC","ip":"0.0.0.0","vlan":984,"mu_mac":"DC-37-14-EA-7D-22"}}
var alarm_from_cfg = {"alarm":"{\"src\": \"device\", \"state\": \"happen\", \"sname\": \"AP-JKLab1\", \"fdn\": [{\"apid\": \"84-24-8D-82-B8-CC\", \"vlan\": 0, \"apip\": \"0.0.0.0\", \"muid\": 0, \"rfd\": \"jk-test\"}], \"grp\": \"security\", \"sev\": \"major\", \"ip\": \"0.0.0.0\", \"rts\": \"2016-01-29T01:52:01.055659\", \"_id\": \"2016-01-29T01:52:01.055508@jk-test\", \"mac\": \"84-24-8D-82-B8-CC\", \"desc\": \"Client 'DC-37-14-EA-7D-22' disassociated from wlan 'JK-Alarm' radio 'AP-JKLab1:R2': client initiated (reason code:8) \"}"}


//var dpd =  JSON.parse(alarm_from_dpd); 
var group = alarm_from_dpd["grp"];
console.log("[## JK-03.1] dpd: " + JSON.stringify(alarm_from_dpd));
console.log("[## JK-03.2] dpd: group = " + group);

// alarm_from_cfg = alarm_from_cfg.replace("\\", "");
 
var alarm = alarm_from_cfg["alarm"];
var cfg =  JSON.parse(alarm); 
cfg_group = cfg["grp"];
console.log("[## JK-04.1] cfg: " + JSON.stringify(alarm_from_cfg));
console.log("[## JK-05.2] cfg: group = " + cfg_group);
