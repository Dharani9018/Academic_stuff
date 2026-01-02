import { createRoot } from 'react-dom/client';
import ParentComponent from './ComplexComponents.jsx';
import Result from "./KeysAndMap.jsx"
import Result1 from "./KeysWithComplexComponents.jsx"
import Result2 from "./EventHanding.jsx";
import Hooks from "./ReactHooks.jsx";
import TodoList from './TodoList.jsx';
import {useState,useEffect,useContext,createContext,useRef,useReducer} from 'react';
import { BrowserRouter,Routes,Route,NavLink} from 'react-router-dom';


/*
//Child component
function ChildComponent({name,college})
{
  return(
    <div>
      <h2>Name: {name}</h2>
      <h2>College: {college}</h2>
    </div>
  )
}

//parent component
function ParentComponent()
{
  return(
    <div>
      <ChildComponent name = "Ajay" college = "PESU"/>
    </div>
  )
}
createRoot(document.getElementById('root')).render(<ParentComponent/>)
*/

/*
function ResImage({src1})
{
  return(
    <div>
      <img src={src1} />
    </div>
  )
}

function ResCaption()
{
  return(
    <div>
      <p>This is a random image from Unsplash</p>
    </div>
  )
}

function Link()
{
  return(
    <div>
      <a href="https://unsplash.com/" target="_blank">Link to Unsplash</a>
    </div>
  )
}

function Parent({src1})
{
  return(<div>
    <ResImage src1 = "https://images.unsplash.com/photo-1506744038136-46273834b3fb?ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D&auto=format&fit=crop&w=1170&q=80" alt="RandomImage"/>
    <Link/>
    <ResCaption/>
    
  </div>)
}


createRoot(document.getElementById('root')).render(<Parent/>)
*/

/*
function ResImage({src1,alt})
{
  return(
    <div>
      <img src={src1} alt={alt} />
    </div>
  )
}

function ResCaption()
{
  return(
    <div>
      <p>This is a random image from Unsplash</p>
    </div>
  )
}

function Link()
{
  return(
    <div>
      <a href="https://unsplash.com/" target="_blank">Link to Unsplash</a>
    </div>
  )
}

function Parent(props)
{
  return(<div>
    <ResImage {...props}/>
    <Link/>
    <ResCaption/>
    
  </div>)
}

function Result()
{
  return(
  <div>
      <Parent src1="https://images.unsplash.com/photo-1506744038136-46273834b3fb?ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D&auto=format&fit=crop&w=1170&q=80" alt="RandomImage"/>
    </div>)
}
createRoot(document.getElementById('root')).render(<Result />)
*/

// 3/10
//keys and map function

/*
function Avengers()
{
  return(
    <div>
      <p>Ironman</p>
      <p>Captain America</p>
      <p>Thor</p>
    </div>
  )
}

function AvengersList()
{
  return[
      <p key = "1">Ironman</p>,
      <p key = "2">Captain America</p>,
      <p key = "3">Thor</p>  //Every child in an array or iterator should have a unique "key".
  ]
}
//MAP FUNCTION
function NumberList(props)
{
  const n = props.numbers;
  const newarray = n.map((num) =><li>{num*2}</li> ) //Each child should have a unique "key" prop.
  return(
    <ul>
      {newarray}
    </ul> 
  )
}
const numbers = [1,2,3,4,5];

function NumberListwithKey(props)
{
  const n = props.numbers;
  const newarray = n.map((num) =><li key={num.toString()}>{num*2}</li> ) //Using key prop to avoid warning, using num itself as key
  return(
    <ul>
      {newarray}
    </ul> 
  )
}
const names = ['Bruce','Clark','Diana'];

function NameList(props)
{
  const n = props.names;
  const newarray = n.map((name,index) =><li key = {index}>{name}</li>)
  return(
    <ul>
      {newarray}
    </ul> 
  )
}
function Parent()
{
  return(
    <div>
      <h3>without keys: has warning</h3>
      <Avengers />
      <NumberList numbers = {numbers}/>
      <h3>with keys</h3>
      <AvengersList />
      <NumberListwithKey numbers = {numbers}/>
      <NameList names = {names}/>
    </div>
  )
}

createRoot(document.getElementById('root')).render(<Parent />)

*/

//Keys with complex components:

/*
function TodoList({todos})
{
  return(
    <ul>
      {todos.map((todo) => (
        <li key ={todo.id}>{todo.task}</li>
      ))}
    </ul>
  )
}

const todos = [
  {id:1,task:'Do laundry',completed:true},
  {id:2,task:'Clean room',completed:false},
  {id:3,task:'Grocery shopping',completed:true}
];

function Parent()
{
  return(
    <div>
      <h3>Todo List</h3>
      <TodoList todos = {todos}/>
    </div>
  )
}

createRoot(document.getElementById('root')).render(<Parent />)
*/

//Event handling
/*
function Counter()
{
  let count = 0;
  function increment()
  {
    count = count + 1;
    document.getElementById("value").innerHtml = "Counter: " + count;
    
  }
  return(
    <div>
      <h2 id="value">Counter: {count}</h2>
      <button onClick={increment()}>+</button>
      </div>)
      }
   
createRoot(document.getElementById('root')).render(<Counter />)
*/

/*

function ToggleText()
{
  let isVisible = true;
  function toggle()
  {
    isVisible = !isVisible;
    document.getElementById("visible").textContent = isVisible ? "This is a Toggle event" : "";
  }
  return(
    <div>
      <h2>Toggle Text</h2>
      <p id = "visible">This is a Toggle event</p>
      <button onClick={toggle}>Show/Hide</button>
    </div>
  )
}

createRoot(document.getElementById('root')).render(<ToggleText />)

*/


//

//Controlled form:
/*
function Myform()
{
  const [name,setName] = useState("")
  const handleChange = (event) => {
    setName(event.target.value);
  }
const handleSubmit = (event) => {
  event.preventDefault();
  alert("Submitted name: " + name)
}
  return(

    <form onSubmit={handleSubmit}>
      <p>Name is :{name}</p>
      Enter your name: <input type = "text" value= {name} onChange={handleChange}/>

      <button type = "submit">Submit</button>
    </form>

  )
}
createRoot(document.getElementById('root')).render(<Myform />)
*/

//Uncontrolled form

/*
function Uncontrolledform()
{
  const inputRef = useRef(null);
  const handleSubmit = (event) => 
  {
    event.preventDefault()
    alert("name is : "+ inputRef.current.value)
  }
  return(

    <form onSubmit={handleSubmit}>

      Enter your name: <input type = "text" defaultValue = "alice" ref={inputRef}/>

      <button type = "submit">Submit</button>
    </form>

  )
}
createRoot(document.getElementById('root')).render(<Uncontrolledform />)
*/

//React Router:
/*
function Home()
{
  return <h2>This is Home Page</h2>
}

function AboutUs()
{
  return <h2>Welcome to the product page</h2>
}

function Contact()
{
  return <h2>Please contact us at abc@gmail.com</h2>
}

function App()
{
  return(
    <BrowserRouter>
      <nav>
        <NavLink to ="/">home</NavLink>|
        <NavLink to ="/about">about</NavLink>|
        <NavLink to ="/contact">Contact</NavLink>
      </nav>

      <Routes>
        <Route path='/' element= {<Home />} />
        <Route path='/contact' element= {<Contact />} />
        <Route path='/about' element= {<AboutUs />} />
      </Routes>
    </BrowserRouter>
  )
}

createRoot(document.getElementById('root')).render(<App />)
*/

function Meow()
{/*
  return(
    <>
    <div> 
      <h1>Complex Components</h1>
        <ParentComponent />
        <Result />
        <Result1 />
        <Result2 />
      <h1>React Hooks</h1>
        <Hooks />
    </div>

    </>
  )*/
 return(
  <>
    <TodoList />
  </>
 )
}

createRoot(document.getElementById('root')).render(<Meow />)


