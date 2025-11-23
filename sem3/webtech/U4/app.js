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

//dynamic routing:

/*
app.get("/:msg",(req,res)=>{
    res.send("This is dynamic routing...")
})
*/

/*
app.get("/:name/:srn",(req,res)=>{
    res.send("name and srn is: "+req.params.name +" "+req.params.srn)
})
*/

//srn with pattern match
app.get("/:name/:srn(\\d{3})",(req,res)=>{
    res.send("name and srn is: "+req.params.name +" "+req.params.srn)
})
app.listen(3000,()=>{
    console.log("Server is running")
})

//query string - req.query
app.get("/search",(req,res)=>{
    const query = req.query.q
    res.send("The value searched is: "+query)
})