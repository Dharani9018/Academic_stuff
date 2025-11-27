//http module: to create a server, allows node.js to transfer data over the HTTP.
//node.js works asynchronously.

//url module: splits up a web address into readable parts(converting it into objects)

const http = require("http") //importing

//creating a server.

/*
http.createServer(function(req,res){
    res.writeHead(200,{"content-type":"text/html"})
    res.write("hello,welcome to http module")
    res.end();
}).listen(3001);
console.log("Server is running");
*/

//url module
var url = require("url")

http.createServer(function(req,res)
{
    res.writeHead(200,{"content-type":"text/html"})
    var q = url.parse(req.url,true).query//converts query string to object.
    var txt = q.year+" "+q.month;
    res.end(txt)
}).listen(3001);
console.log("Server is running") 
