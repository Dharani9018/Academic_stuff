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
        <p key = "3">Thor</p> //Every child in an array or iterator should have a unique "key".
    ]
}

//Mapfunction

const numbers = [1,2,3,4,5]
function NumberList(props)
{
    const n = props.numbers;
    const newarray = n.map((num) => <li>{num*2}</li>)
    return(
        <ul>
            {newarray}
        </ul>
    )
}

//with keys:

function NumberListwithKey(props)
{
    const n = props.numbers;
    const newarray = n.map((num) => <li key={num.toString()}>{num*2}</li>)
    return(
        <ul>
            {newarray}
        </ul>
    )
}
function Result()
{
    return ( 
    <>
        <h1>Keys and Map function</h1>
        <Avengers />
        <h3>With keys</h3>
        <AvengersList />
        <h3>Map</h3>
        <h4>without keys</h4>
        <NumberList numbers={numbers} />
        <h4>With keys</h4>
        <NumberListwithKey numbers={numbers} />

    </>
    )
}

export default Result;