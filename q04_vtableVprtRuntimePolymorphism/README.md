## 🧱 Runtime Polymorphism, `vptr`, and `vtable` in C++

### 📌 What is Runtime Polymorphism?
Runtime polymorphism in C++ allows a **derived class to override virtual functions** of its base class, and the correct function is called **based on the object type at runtime**, not compile time. This is achieved using **virtual functions**, **vptr**, and **vtable**.

---

### 🔧 How It Works: `vptr` and `vtable`

- **vptr (Virtual Pointer)**: A hidden pointer in every polymorphic object that points to the **vtable** of the class it belongs to.
- **vtable (Virtual Table)**: A static table generated per class containing addresses of **virtual functions**. Each entry points to the **most derived override** of a virtual function.

When a virtual function is called through a base class pointer, the call is resolved **using the vtable at runtime** through the vptr.

---

### 📊 ASCII Diagram

```
+-------------------+                             +--------------------------+
|      Animal       |                             |      Animal vtable       |
|-------------------|                             |--------------------------|
| virtual speak()   | <-- [vptr] ----------------> | speak() → Animal::speak |
| eat()             |                             |                          |
+-------------------+                             +--------------------------+


+-------------------+                             +-----------------------+
|       Dog         |                             |      Dog vtable       |
|-------------------|                             |-----------------------|
| override speak()  | <-- [vptr] ----------------> | speak() → Dog::speak  |
| eat()             |                             | fetch() → Dog::fetch  |
| virtual fetch()   |                             |                       |
+-------------------+                             +-----------------------+


+-------------------+                             +-----------------------------+
|     Bulldog       |                             |     Bulldog vtable          |
|-------------------|                             |-----------------------------|
| override speak()  | <-- [vptr] ----------------> | speak() → Bulldog::speak   |
| override fetch()  |                             | fetch() → Bulldog::fetch   |
| sleep()           |                             |                             |
+-------------------+                             +-----------------------------+
```

---

### 🧪 Sample Code with 3-Level Inheritance

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() { cout << "Animal speaks" << endl; }
    void eat() { cout << "Animal eats" << endl; }
};

class Dog : public Animal {
public:
    void speak() override { cout << "Dog barks" << endl; }
    void eat() { cout << "Dog eats" << endl; } // Non-virtual
    virtual void fetch() { cout << "Dog fetches" << endl; }
};

class Bulldog : public Dog {
public:
    void speak() override { cout << "Bulldog growls" << endl; }
    void fetch() override { cout << "Bulldog fetches lazily" << endl; }
    void sleep() { cout << "Bulldog sleeps" << endl; } // Non-virtual
};

int main() {
    Animal* a = new Bulldog();
    a->speak();  // Resolves to Bulldog::speak (runtime)
    a->eat();    // Resolves to Animal::eat (compile time)

    Dog* d = new Bulldog();
    d->speak();  // Bulldog::speak
    d->fetch();  // Bulldog::fetch

    delete a;
    delete d;
    return 0;
}
```

---

### 💡 Common Interview Questions

| Question | Answer Summary |
|---------|----------------|
| What is vtable? | A table containing addresses of virtual functions per class. |
| What is vptr? | A hidden pointer inside each object pointing to the class's vtable. |
| How is polymorphism achieved? | Using vptr → vtable → actual method at runtime. |
| Can static functions be virtual? | ❌ No, because static functions are not tied to instances. |
| Is vtable shared or per object? | Shared per class, not per object. |
| Is vtable a static array? | Yes, internally compiler maintains it as a static lookup table. |
| Can constructor/destructor be virtual? | Constructor ❌, Destructor ✅ (destructor should be virtual in base class for cleanup). |
| Does vptr increase object size? | Yes, it adds size of one pointer per object. |

---

### 🧠 Layman Summary
- Virtual means **"decide later"**.
- vptr is like a **TV remote**; vtable is the **channel list**.
- At runtime, object **points to correct vtable**, so the right function is called.
- Only **virtual functions** use vtables; normal functions are directly linked.

---

### ✅ Tip to Remember
> Use `virtual` for base class functions when you expect **different behavior in child classes**.

---

## 🎥 Recommended YouTube References
- [Understanding the vtable (Popular interview question)](https://www.youtube.com/watch?v=hS7kPtVB1vI)
- [Virtual Tables](https://www.youtube.com/watch?v=NCKBIi8vfM4)
- [C++ vpointers and vtables](https://youtu.be/Eaz0P_gJ9FE)

---