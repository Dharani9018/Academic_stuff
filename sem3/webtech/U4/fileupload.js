const express = require("express")
const fileUpload = require("express-fileupload") //third party middleware functions

const app = express();

app.use(fileUpload()); //use the middleware function

app.get("/",(req,res) => {
    res.sendFile(__dirname + "/index.html")
})

app.post("/uploads", (req,res) => {
    if(!req.files || !req.files.myFile)
    {
        return res.send("No file Uploaded")
    }
})

let file = req.files.myFile;
// moving the uploaded file to the specific directory.
file.mv(__firname + "/uploads" + file.name,(err) => {
    if(err)
    {
        return res.status(500).send(err);
    }
    res.send("file uploaded successfully " + file.name)
})