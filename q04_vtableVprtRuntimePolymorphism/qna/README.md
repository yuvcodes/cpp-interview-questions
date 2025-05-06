## C++ Virtual Function Interview Q\&A

### 🔹 Q1: What is the difference between `virtual` and `pure virtual` functions?

| Feature                             | `virtual` Function         | `pure virtual` Function                            |
| ----------------------------------- | -------------------------- | -------------------------------------------------- |
| Definition                          | `virtual void foo();`      | `virtual void foo() = 0;`                          |
| Base class provides implementation? | Yes (optional to override) | No implementation (must override in derived class) |
| Instantiable?                       | Yes                        | No, abstract class                                 |
| Must be overridden?                 | No                         | Yes                                                |

---

### 🔹 Q2: Is it necessary to override all virtual functions in a derived class?

* No, unless it's a **pure virtual** function.
* If it's a regular `virtual`, the base version is used if the derived class doesn't override it.

---

### 🔹 Q3: Can constructors be virtual?

* ❌ No.
* Virtual mechanism depends on `vtable` which is set up **after** the constructor is called.

---

### 🔹 Q4: Can destructors be virtual?

* ✅ Yes, and they **should be** when using polymorphism.
* Ensures proper destruction of derived objects when deleted via base pointer.

```cpp
class Base {
public:
    virtual ~Base() { cout << "Base Destructor\n"; }
};
```

---

### 🔹 Q5: What is `vtable` and `vptr`?

* `vptr`: Hidden pointer in each object that points to that class's virtual function table.
* `vtable`: A static table (per class) containing function pointers to virtual methods.

---

### 🔹 Q6: Is `vtable` static?

* Yes, one per class with virtual functions.
* But `vptr` is per object.

---

### 🔹 Q7: Can virtual functions be `static`?

* ❌ No. Static methods don't belong to object instances, so they can't be overridden.

---

### 🔹 Q8: Can we make destructor pure virtual?

* ✅ Yes, but you **must** provide a body:

```cpp
class Abstract {
public:
    virtual ~Abstract() = 0; // pure virtual
};
Abstract::~Abstract() { cout << "Destructor\n"; }
```

---

### 🔹 Q9: What is object slicing?

* When a derived object is assigned to a base object, only the base part is copied.
* This **removes** the derived behavior.

```cpp
Derived d;
Base b = d;  // slicing occurs
```

---

### 🔹 Q10: What is runtime polymorphism?

* Achieved by using `virtual` functions.
* Function call is resolved at runtime based on actual object type (via `vptr/vtable`).

---

### ✅ Best Practices:

* Always make base destructors `virtual` when working with inheritance.
* Use `override` keyword in derived classes to avoid bugs.
* Avoid virtual calls in constructors/destructors.

