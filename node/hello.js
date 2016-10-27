var arrs = ["test", "jklee", "zebra"];
//var empty_arrs = [];
var empty_arrs = null;
var count = arrs.length;
var empty_count = empty_arrs.length;
console.log("[### JK-DBG-01] Length: count= "+ count);
console.log("[### JK-DBG-02] Length: empty_arrs= "+ count);

arrs.forEach(function(arr) {
	 console.log("[### JK-DBG-02] loop_through: arr= " + arr);
});

empty_arrs.forEach(function(arr) {
	 console.log("[### JK-DBG-02] loop_through: arr= " + arr);
});