var fs = require('fs');
var file = 'userdata.txt';

var a = [];

fs.readFile(file,'utf8', function(err,data){
	if(err) return console.log(err);
	//console.log(data);
	var darr = data.split('\n');
	for(var i=0;i<darr.length;i++){
		var p = {};
		var arr = darr[i].split('|');
		p.name = arr[0];
		p.time = new Date(parseInt(arr[1]));
		p.lng = arr[2];
		p.lat = arr[3];
		a.push(p);
	//	console.log("date " + arr[1]);
	//	console.log("i " + i + " " + p.time);
	}

});