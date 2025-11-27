const express = require("express")

//default route
//create a root level application
var app = express();
app.get("/",(req,res)=>{
    res.send("I'm the response")
})

app.get("/hello",(req,res)=>{
    res.send("this is static routing")
})




//srn with pattern match
/*
app.get("/:name/:srn(\\d{3})",(req,res)=>{
    res.send("name and srn is: "+req.params.name +" "+req.params.srn)
})
app.listen(3000,()=>{
    console.log("Server is running")
})*/

//query string
app.get("/search",(req,res)=>{
    const query = req.query.a
    res.send("The value searched is " + query)
    console.log(req.originalUrl)
    console.log(req.url);
    console.log(req.path)
})
//const userURL = `/users/${userId}`
//dynamic routing:


app.get("/:msg",(req,res)=>{ //msg is variable inside a url path
    res.send("You sent: " + req.params.msg)
})



app.get("/:name/:srn",(req,res)=>{
    res.send("name and srn is: "+req.params.name +" "+req.params.srn)
})

app.listen(3000)
console.log("Server is running. ")
//http://localhost:3000
//http://127.0.0.1:3000
