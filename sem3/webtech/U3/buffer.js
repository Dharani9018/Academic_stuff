//create a buffer
var buf1 = Buffer.alloc(5);
console.log(buf1);
buf1 = Buffer.from([10,20,30,40,50])
console.log(buf1);
var buf2 = Buffer.from(buf1)
console.log(buf2);

//buffer string 
var buf3 = Buffer.alloc(30);
buf3 = Buffer.from("Good morning class");
console.log(buf3.toString());

//write / read from buffer
 len = buf3.write("Buffer class")
console.log(buf3.toString())
console.log(len)
console.log(buf3.length)
console.log(buf3.toString("utf-8",2,10));

//write bytes at a specific position 
buf3[6] = 44;//ascii for ","
buf3[6]= 32 //ascii for space
console.log(buf3.toString());

//copy from on buffer
var buf4 = Buffer.from("tothe")
var buf5 = Buffer.from("Welcomeat Buffer");
buf4.copy(buf5,7,2);

//compare 2 buffers


buf6 = Buffer.alloc(10,"hi, welcome")
buf7 = Buffer.alloc(10,"Hi, welcome")
res = buf6.compare(buf7)
if(res<0){console.log(buf6+ "comes before " +buf7)}
else
    if(res===0){console.log(buf6+ "equals "+buf7)}
else
{console.log(buf6+ "comes after " +buf7)}
