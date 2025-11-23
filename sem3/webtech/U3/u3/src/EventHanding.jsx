//Event handling
function Counter()
{
    let count = 0;
    function increment()
    {
        count = count + 1;
        document.getElementById("value").innerText = "Counter: " +  count;
    }
    return(
        <div>
            <h2 id="value">Counter: 0</h2>
            <button onClick={increment}>+</button>
        </div>
    )
}

function ToggleText()
{
    let isVisible = true;
    let value = "Hide";
    function toggle()
    { 
        isVisible = !isVisible;
        document.getElementById("visible").textContent = isVisible ? "This is a Toggle event" : " ";
        value = isVisible ? "Hide" : "show";
        document.getElementById("btn").textContent = value;
        
    }
    return(
        <div>
            <h2>Toggle Text</h2>
            <p id="visible">This is a Toggle event</p>
            <button id="btn" onClick={toggle}>Hide</button>
        </div>
    )
    
}

function Result2()
{
    return(
        <>
            <h1>Event Handling</h1>
            <Counter />
            <ToggleText />
        </>
    )
}

export default Result2;