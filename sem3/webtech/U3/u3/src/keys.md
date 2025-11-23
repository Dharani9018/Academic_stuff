

# ✅ **React Keys & Reconciliation — Full Mental Model**

## **1. What React Is Trying to Do**

React’s job during re-render is to **compare the old virtual DOM with the new virtual DOM** and update only what changed.
This comparison process is called **reconciliation**.

React wants to avoid deleting and recreating DOM nodes unless necessary because that’s slow.

---

# ✅ **2. Why Keys Matter**

Keys tell React:

> “This list item is THIS specific item, even if its position changes.”

Without keys, React **assumes items are identified by their index**.

---

# 📌 **3. With Key vs Without Key**

## **🔹 Without keys**

React uses the **position** to match elements:

```
Old list:  [ Iron, Captain, Hulk ]
New list:  [ Thor, Captain, Hulk ]
```

React does this:

* Position 0: Iron → Thor (React reuses the DOM node)
* Position 1: Captain stays
* Position 2: Hulk stays

This means:

* **Iron’s DOM node is reused (mutated) to become Thor**
* Thor **does not get a new node**
* Hulk **stays where he is**

This is why your “Hulk stays put, Thor replaces Iron” scenario happened.

---

## **🔹 With unique keys**

React matches elements by **identity**, not position:

```
Old:
<Hero key="iron" />
<Hero key="captain" />
<Hero key="hulk" />

New:
<Hero key="thor" />
<Hero key="captain" />
<Hero key="hulk" />
```

Now React does this:

* iron → removed completely
* thor → new DOM node created
* captain → reused
* hulk → reused

**Every hero keeps their own node.**
No identity confusion.

---

# ✅ **4. Why Wrong Keys (like “iron has captain's key”) Cause Bugs**

A key is supposed to represent the **real identity** of the item.

If you do this:

```jsx
<Hero key="captain" name="Iron" />
```

React thinks:

> “This is Captain's old DOM node.”

So React reuses Captain’s DOM node and mutates it to “Iron”.

You see **props changing on the wrong component**, and state can get mixed.

### Keys are not labels for UI

They are labels for **identity in memory**.

Say it like this:

* They’re not *names*
* They’re *IDs used for linking old and new nodes*

---

# 🔥 **5. What “new DOM element” actually means**

Yes — React will create a **new DOM node** when:

* A new key appears
* An old key disappears
* You reorder items **with keys**

If keys are missing, React creates new nodes only when the **length** changes, not when **identity** changes.

---

# ⚠️ **6. Why Text Alone Doesn’t Matter**

You asked:

> “They’re just texts right — they can be anything?”

The **text is not identity.**
React cares about keys because:

* keys = identity
* text = content

If identities shuffle, state and DOM get messed.

Example:

If Iron gets Captain’s key, React literally thinks:

> “This is Captain wearing a new costume.”

It won't treat Iron as a new person.

---

# 🧠 **7. The One Golden Rule**

In lists:

### **Use keys that NEVER change for each item.**

✔ Good: database IDs
✔ Good: UUIDs
✔ Good: hero.id

❌ Bad: array index
❌ Bad: random()
❌ Bad: swapping keys between elements
❌ Bad: using values that can repeat

---

# 📌 **8. Bottom-Line Summary for Memory**

Here is the most compressed version:

* React compares old and new lists during reconciliation.
* Without keys → React assumes items are identified by position.
* With keys → React tracks elements by identity.
* Wrong or unstable keys → React mixes up which DOM node belongs to which item.
* Changing text ≠ new item.
  Changing key = new item.
* New key → new DOM node.
  Same key → DOM node reused.

---

