const todos = [
    {id:1,task:'Sleep'},
    {id:2,task:"Eat"},
    {id:3,task:"Do nothing"}
]

function TodoList({todos})
{
    return(
        <ul>
            {todos.map((todo)=> (
                <li key={todo.id}>{todo.task}</li>
            ))}
        </ul>
    )
}

function Result1()
{
    return (
        <>
        <h1>Keys using complex components</h1>
        <TodoList todos = {todos} />
        </>
    )
}

export default Result1;