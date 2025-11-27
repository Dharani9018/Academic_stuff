import {useState,useEffect,createContext,useContext,useRef,useReducer} from "react";

// const [state,setState] = useState(initialValue);

function Color()
{
    const [color,setColor] = useState("")

    return (
        <>
            <h2 style = {{color:color}}>I'm {color}</h2>
            <button onClick = {()=>setColor("Blue")}>Blue</button>
            <button onClick = {()=>setColor("Red")}>REd</button>
        </>
    )
}

function Counter()
{
    const [count,setCount] = useState(0);

    return(
        <div>
            <h2>Counter: {count}</h2>
            <button onClick={()=>setCount(count + 1)}>+</button>
        </div>
    )

}

function FormExample()
{
    const [name, setName] = useState("");

    return(
        <div>
            <input type="text" value={name} onChange={(e)=> setName(e.target.value)} />
            <p>Hello, {name}</p>
        </div>
    )
}

//UseEffect:
/*Syntax:
useEffect(()=>{
    effect logic
    return () => {
        // cleanup logic (optional)
    }
},[dependencies]
)
*/
function DocumentTitleUpdater()
{
    const [count,setCount] = useState(0);

    useEffect(()=>{
        document.title = `You clicked ${count} times`
    },[count]);

    return(
        <button onClick = {() => setCount(count + 1)}>Click {count}</button>
    )
}

function Counter2()
{
    const [count,setCount] = useState(0)
    useEffect(()=>{
        const timer = setInterval(()=>setCount(c => c+1),2000)
        
    },[])

    return(
        <>
            <h1>Counter value is {count}</h1>
        </>
    )
}
//Use Context:

const UserContext = createContext()
function App(){
    const [user,setUser] = useState("Pranav")
    return(
        <UserContext.Provider value = {user}>
            <Child />
            <button onClick={()=>setUser("Akshay")}>Change User</button>
        </UserContext.Provider>
    )
}

function Child()
{
    const user = useContext(UserContext)
    return(
        <h1>Hello, {user}</h1>
    )
}

//Use Ref:
function ReferenceObject(){
    const [inputValue,setInputvalue] = useState("")
    const count = useRef(0)
    useEffect(()=>{
        count.current = count.current + 1;
    })
    return(
        <>
            <p>Type the input field: </p>
            <input type = "text" value = {inputValue}
            onChange={
                (e)=>setInputvalue(e.target.value) 
            }/>
            <h1>Render Count: {count.current}</h1>
        </>
    )
}
function AgeCounter(){
    const [state,dispatch] = useReducer(reducer,{age:20})
    return(
        <>
        <p>Age: {state.age}</p>
        <button onClick={()=>dispatch({type:"increment_age"})}>+</button>
        <button onClick={()=>dispatch({type:"decrement_age"})}>-</button>
        </>
    )
}
function reducer(state,action)
{
    switch(action.type){
        case "increment_age":return{age:state.age + 1}
        case "decrement_age":return{age:state.age - 1}
        default: throw Error("unknown action")
    }
}

function Hooks()
{
    return( 
    <>
        <h2>Use State: </h2>
        <Color />
        <Counter />
        <FormExample />
        <h2>Use Effect:</h2>
        <DocumentTitleUpdater />
        <Counter2 />
        <h2>Use Context</h2>
        <App />
        <ReferenceObject />
        <AgeCounter />
    </>
    )
}


export default Hooks;
