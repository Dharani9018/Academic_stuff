const {MongoClient} = require("mongodb")
const url = "mongodb://127.0.0.1:27017"
const dbname = "university"

//Connecting to client: 
/*
MongoClient.connect(url)
.then((client) =>{
    console.log("Connected.. ")
    const db = client.db(dbname);
    console.log("Database Created..")
    client.close()
})
.catch((err)=>{console.log(err)})
*/

//Creating a collection:

/*
MongoClient.connect(url)

.then((client)=>{
    const db = client.db(dbname)
    return db.createCollection("student")
    .then(()=>
    {
        console.log("Collection created. ");
        return client.close();
    })
})
.catch((err)=>{console.log(err)})
*/

//insert a document:

/*
MongoClient.connect(url)

.then((client)=>{
    const db = client.db(dbname);
    return db.createCollection("student")
    .then(()=>{ 
    const docs = [{"srn":"1","name":"meow","dept":"math"},{"srn":"2","name":"meow2","dept":"phy"}]
    const collection = db.collection("student")
    return collection.insertMany(docs)
    //return collection.insertOne({"srn:9","name":"xyz","dept":"ABC"})
    .then((res)=>{
        console.log("inserted many: ")
        console.log("Count of inserted: ",res.insertedCount)
        console.log(res)
        return client.close()
    })
})
})

.catch((err)=>{console.log(err)})
*/

//Displaying:

/*
MongoClient.connect(url)
.then((client)=>{
    const db = client.db(dbname);
    const collection = db.collection("student");
    return collection.find({"dept":"math"}).toArray()
    .then ((res)=>{
        console.log(res)
        return client.close()
    })
    
})

.catch((err)=>console.log(err));
*/

/*
MongoClient.connect(url)
.then((client)=>{
    const db = client.db(dbname);
    const collection = db.collection("student")
    const query = {"srn":"003"}
    const update = {$set:{"dept":"aiml"}}

    return collection.updateOne(query,update)
    .then((res)=>{
        console.log("Update successful");
        console.log("Matched :",res.matchedCount,"Modified :",res.modifiedCount );
        console.log(res)
        return client.close();
    })
    
})
.catch((err)=>{
    console.log(err)
})
*/
//deleteOne
/*
MongoClient.connect(url)
.then((client)=>{
    const db = client.db(dbname);
    const collection = db.collection("student")
    
    return collection.deleteOne({"srn":"004"})
    .then((res)=>{
        console.log("Deleted count :",res.deletedCount)
        console.log(res);
        return client.close();
    })
})
.catch((err)=>{
    console.log(err)
})*/

// drop a collection 
MongoClient.connect(url)
.then((client)=>{
    const db = client.db(dbname);
    //const collection = db.collection("student")
    
    return db.collection("student").drop().then((res)=>{
        console.log("Collection dropped", res)
        return client.close();
    })
})
.catch((err)=>{
    console.log(err)
})





