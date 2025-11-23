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

function ResImage({src1,alt})
{
  return(
    <div>
      <img src={src1} alt={alt}/>
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
      <a href="https://unsplash.com/">Link to Unsplash</a>
    </div>
  )
}
//The props keyword.
function Link2(props)
{
  return(
    <div>
      <a {...props}>Link to Unsplash2</a>
    </div>
  )
}

//parent component
function ParentComponent()
{
  return(
    <div>
      <ChildComponent name = "Ajay" college = "PESU"/>
      <ResImage src1 = "https://images.unsplash.com/photo-1506744038136-46273834b3fb?ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D&auto=format&fit=crop&w=1170&q=80" alt="I'm an Image" />
      <Link />
      <ResCaption />
      <div> 
        <h3>Using 'props' keyword:</h3>
        <Link2 href = "https://unsplash.com/"/>
      </div> 

    </div>
  )
}

export default ParentComponent;