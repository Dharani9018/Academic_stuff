// Middleware = a function that runs in the middle of a request and a response.
var express = require("express")

var app = express()

app.use((req,res,next)=>{
    console.log("First middleware")
    console.log("first method: " + req.method)
    console.log("First path: ",req.path)
    next()
})

app.use("/hello",(req,res,next)=>{
    console.log("Second middleware")
    console.log("Second method: " + req.method)
    console.log("Second path: ",req.path)
    next()
})





app.listen(3000,()=>{console.log("Server is running")})