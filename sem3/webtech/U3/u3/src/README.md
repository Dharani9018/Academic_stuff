

# ✅ **1. `useState` — State Management**

`useState` lets a component store a value that *changes* and triggers re-render when changed.

### **Color Component**

```js
const [color,setColor] = useState("")
```

* Stores current selected color.
* When you click a button → `setColor("Blue")` → component re-renders → `<h2 style={{color: color}}>` updates.


---

# ✅ **2. `useEffect` — Run code after render**

Used for:

* DOM updates
* API calls
* Timers
* Subscriptions
* Updating browser title
* Anything that should not run during rendering

### **DocumentTitleUpdater**

```js
useEffect(()=>{
    document.title = `You clicked ${count} times`
},[count])
```

* Runs **every time count changes**
* Updates browser tab title

### **Counter2**

```js
useEffect(()=>{
    const timer = setInterval(()=>setCount(c => c+1),2000)
},[])
```

* Empty array `[]` → runs **only once** (on mount)
* Creates a timer that increments count every 2 sec

---

# ✅ **3. `useContext` — Share state across components without props**

Step-by-step:

### **Create context**

```js
const UserContext = createContext()
```

### **Provider**

```js
<UserContext.Provider value={user}>
```

* Makes `user` available to all nested components.

### **Child component**

```js
const user = useContext(UserContext)
```

* Reads the value stored inside context.
* No props needed. Clean and global.

---

# ✅ **4. `useRef` — Store a value without causing re-render**

Useful for:

* Storing previous value
* DOM reference
* Counting renders
* Mutable values

### **ReferenceObject**

```js
const count = useRef(0)
```

`count.current` survives re-renders but does NOT cause re-renders.

```js
useEffect(()=>{
    count.current = count.current + 1;
})
```

* Runs after every render
* Increments render count
* Shows how many times component rendered

---

# ✅ **5. `useReducer` — Alternative to useState for complex logic**

Used when:

* You have multiple state updates
* You want clean state transitions
* Logic depends on action types

### **Reducer function**

```js
function reducer(state,action){
    switch(action.type){
        case "increment_age":return{age: state.age + 1}
        case "decrement_age":return{age: state.age - 1}
        default: throw Error("unknown action")
    }
}
```

### **AgeCounter**

```js
const [state,dispatch] = useReducer(reducer,{age:20})
```

* `state` → `{ age: 20 }`
* `dispatch` sends actions to reducer
* Reducer decides how to update state

---

# 📌 **NOW FULL SUMMARY (EXAM-READY):**

### ✔ `useState`

* Store a value that changes.
* Rerenders component when updated.

### ✔ `useEffect`

* Run side-effects (after render).
* `[dependencies]` decides when it runs.

  * Empty array → only once
  * No array → every render
  * Array with values → runs when values change

### ✔ `useContext`

* Share data without passing props.
* `Provider` gives value.
* `useContext` receives it.

### ✔ `useRef`

* Stores a value that persists across renders.
* Changing it does NOT re-render.
* Good for:

  * Counters
  * DOM access
  * Previous values

### ✔ `useReducer`

* Like useState but better for complex updates.
* Uses a reducer function.
* Dispatch actions to update state.

---

