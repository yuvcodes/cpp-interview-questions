# 🔧 Smart Pointers in C++

Smart pointers are a safer alternative to raw pointers in C++. They automatically manage the memory they point to and help prevent common bugs like memory leaks, dangling pointers, and double deletion.

---

## 🧪 Why Smart Pointers?

In raw pointers:

* You must manually `delete` memory.
* You can accidentally cause memory leaks or crashes.

With smart pointers:

* Memory is **automatically freed** when the pointer goes out of scope.
* Ownership and lifetime are well-defined.

---

## 📅 Types of Smart Pointers

### 1. `unique_ptr`

* **Ownership**: Single owner
* **Copyable?** ❌ No (Only movable)
* **Use case**: You need exclusive control of a resource

### 2. `shared_ptr`

* **Ownership**: Shared among multiple `shared_ptr`
* **Copyable?** ✅ Yes
* **Use case**: Multiple parts of code share ownership

### 3. `weak_ptr`

* **Ownership**: Doesn’t own memory
* **Copyable?** ✅ Yes
* **Use case**: Prevent cyclic references when using `shared_ptr`

---

## 🔄 Key Concepts

| Term                            | Meaning                                                                    |
| ------------------------------- | -------------------------------------------------------------------------- |
| **RAII**                        | Resource Acquisition Is Initialization – memory is tied to object lifetime |
| **use\_count()**                | Shows how many `shared_ptr`s own a resource                                |
| **lock()**                      | Converts `weak_ptr` to `shared_ptr` if resource exists                     |
| **make\_shared / make\_unique** | Safer than using `new` manually                                            |

---

## ❓ Most Common Interview Questions

1. **What is a smart pointer?**

   > A smart pointer is a class that wraps a raw pointer and automatically frees memory when no longer needed.

2. **When would you use `unique_ptr` over `shared_ptr`?**

   > When a resource should have only one owner.

3. **Why is `weak_ptr` important?**

   > To break circular references between `shared_ptr` objects.

4. **How does `shared_ptr` know when to delete memory?**

   > It uses reference counting. When count drops to zero, memory is freed.

5. **Can you assign one `unique_ptr` to another?**

   > No, but you can transfer ownership using `std::move()`.

---

## 📅 Summary Cheatsheet

```
- Use unique_ptr for exclusive ownership
- Use shared_ptr when multiple parts of the code share a resource
- Use weak_ptr to avoid memory leaks from circular references
```

---

## ⭐ Best Practices

* Always use `make_shared` and `make_unique`
* Never use raw `new` and `delete` with smart pointers
* Avoid mixing raw and smart pointers
* Don’t create cycles with `shared_ptr`; use `weak_ptr`

---