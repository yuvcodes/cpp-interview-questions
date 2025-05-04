# ⚠️ Dangling Pointers in C++ – Complete Interview Guide

A **dangling pointer** in C++ is a pointer that points to a memory location that has been **freed**, **deleted**, or is **out of scope**.

This guide will teach you:

* What dangling pointers are (in simple words)
* Code examples that cause them
* How to avoid them in interviews and real projects
* Best practices and tools to catch them

---

## 🧠 What is a Dangling Pointer?

> Imagine storing your friend’s old phone number. They changed it, but you still try to call them. That’s what a dangling pointer does — it holds onto memory that doesn’t exist anymore.

---

## 📌 Table of Contents

| #   | Topic                    | Description                                      |
| --- | ------------------------ | ------------------------------------------------ |
| 1️⃣ | After `delete`           | Memory freed, but still accessed                 |
| 2️⃣ | Returning local variable | Function returns address of a destroyed variable |
| 3️⃣ | Out-of-scope variable    | Pointer to variable that went out of scope       |
| 4️⃣ | Double delete            | Memory freed twice                               |
| 5️⃣ | ✅ Smart Pointers         | Safe handling of dynamic memory                  |

---

## 📋 Examples & Explanations

---

### 1️⃣ After `delete`

```cpp
int* ptr = new int(10);
delete ptr;
cout << *ptr; // ❌ Accessing freed memory – dangling pointer!
```

✔️ **Fix**:

```cpp
delete ptr;
ptr = nullptr;
```

---

### 2️⃣ Returning Local Variable Address

```cpp
int* getPtr() {
    int x = 42;
    return &x; // ❌ x is destroyed when function ends
}
```

✔️ **Fix**: Use heap allocation or pass a pointer as argument.

---

### 3️⃣ Out-of-Scope Variable

```cpp
int* ptr;
{
    int temp = 99;
    ptr = &temp;
} // ❌ temp is destroyed here
cout << *ptr; // Dangling access
```

✔️ **Fix**: Use `new` or ensure variable stays in scope.

---

### 4️⃣ Double Delete

```cpp
int* ptr = new int(5);
delete ptr;
delete ptr; // ❌ Dangerous — double delete
```

✔️ **Fix**:

```cpp
delete ptr;
ptr = nullptr;
```

---

### 5️⃣ ✅ Smart Pointers (Safe Way)

```cpp
#include <memory>

unique_ptr<int> smartPtr = make_unique<int>(100);
cout << *smartPtr;
```

✅ **Explanation**: Automatically manages memory. No manual delete needed.

---

## 💡 Tips to Avoid Dangling Pointers

| ✅ Do This                               | ❌ Avoid This                         |
| --------------------------------------- | ------------------------------------ |
| Set pointer to `nullptr` after `delete` | Accessing pointer after `delete`     |
| Use `unique_ptr`, `shared_ptr`          | Returning address of local variables |
| Use tools like Valgrind or ASan         | Double delete                        |

---

## 📜 Final Cheat Code

```
Dangling pointers = pointers to memory that is deleted or out of scope.
Never use them. Nullify pointers after delete. Use smart pointers to stay safe.
```

