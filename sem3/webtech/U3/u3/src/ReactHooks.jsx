import { createRoot } from 'react-dom/client';
import {useState} from "react";

function Color()
{
    const [color,setColor] = useState("")
    useState(()=> {
        if (color) {
            console.log(`color: ${color}`)
        }
    },[color]);

    return (
        <>
            <h2 style = {{color:color}}>I'm {color}</h2>
            <button onClick = {()=>setColor("Blue")}>Blue</button>
            <button onClick = {()=>setColor("Red")}>REd</button>
        </>
    )
}

createRoot(document.getElementById("root")).render(<Color />)
