const express = require("express");
const fileUpload = require("express-fileupload");


const app = express();

app.use(fileUpload());//use the middlware function

app.get("/",(req,res)=>{
    res.sendFile(__dirname + "/index.html")
})

app.post("/upload",(req,res)=>{
if(!req.files||!req.files.myFile){
    return res.send("No file uploaded")
}

let file = req.files.myFile;
//moving the uploaded file from memory  to the specified directory

file.mv(__dirname +"/uploads/"+file.name,(err)=>{
    if(err) return res.status(500).send(err);
    res.send("file uploaded successfully"+file.name)
})
})
app.listen(5000)
console.log("server is listening ..")