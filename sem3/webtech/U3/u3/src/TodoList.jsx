function CreateList()
{
    let x = document.getElementsById("input").value;
    p = document.createElement("p");
    p.textContext = x;

}
function Button()
{
    return(
        <> 
         <input id="input" type="text"></input>
        <button onClick={CreateList}>ADD +</button>
        </>
    )
}
function TodoList()
{
    return(
        <>
            <div>
                <Button />
                <div id="insert">

                </div>
            </div>

        </>
    )
}

export default TodoList()