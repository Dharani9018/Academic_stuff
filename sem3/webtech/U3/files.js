const fs1 = require("fs")
/*fs1.stat("sample.txt",(err,stats)=>
{
    if(err)throw err;
    console.log("Statistics of file is: ",JSON.stringify(stats))
})

//Reading a file:asynchronous:
fs1.readFile("sample.txt","utf-8",(err,data) =>
{
    if(err)throw err;
    console.log("File contents: ",data)
})

//Reading a file - synchronous:

const data = fs1.readFileSync("sample.txt","utf-8")
console.log("Contents of the file ",data)

//writing to a file
fs1.writeFile("sample1.txt","I'm the written data!!",(err)=>
{
    if(err)throw err
    console.log("File write is done!!")
})
//append a file
fs1.appendFile("sample.txt","I'm the appended data",(err)=> //Appends to the end of the file
{
    if(err)throw err;
    console.log("Append done!")
})*/

//opening a fileeeee:file modes
//read
/*
fs1.open("sample.txt","r",(err,file)=>
{
    if(err)throw err;
    console.log("File opened (readmode)")
    console.log("Contents: ",file)
})
*/
//write mode:
/*
fs1.open("sample.txt","w",(err)=>
{
    if(err)throw err;
    console.log("File opened (writemode)")
})
*/    

//truncate a file
/*
fs1.open("sample.txt","r+",(err,fd)=>
{
    if(err) throw err;
    var buffer = Buffer.alloc(1024)
    console.log("Lets truncate the file ")
    fs1.truncate(fd,9,(err)=>
    {
        if(err) throw err;
        console.log("Truncating successful: ")
    })
    fs1.read(fd,buffer,0,buffer.length,0,(err,bytes)=>{
        if(err) throw err;
        if(bytes>0)
        {
            console.log(buffer.slice(0,bytes.toString()))
        }
        fs1.close(fd,(err)=>
        {
            if(err) throw err
        })
    })
})
    */
fs1.unlink("sample1.txt",(err)=>{
    if(err) throw err
    console.log("File deleted")
})