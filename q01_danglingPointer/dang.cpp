// dangling_pointer_examples.cpp
// Demonstrates different types of dangling pointers in C++

#include <iostream>
#include <memory> // for smart pointers
using namespace std;

// 1. After delete
void afterDelete() {
    int* ptr = new int(10);
    delete ptr;
    ptr = nullptr; // Safe practice
    if (ptr == nullptr) {
        cout << "Pointer is null after delete.\n";
    }
}

// 2. Returning local variable address
int* returnLocalAddress() {
    int x = 42;
    return &x; // Dangerous: x will be destroyed
}

// 3. Out-of-scope variable
void outOfScopeExample() {
    int* ptr;
    {
        int temp = 99;
        ptr = &temp; // temp will be destroyed after block ends
    }
    // cout << *ptr << endl; // This would be undefined behavior
    cout << "ptr now points to out-of-scope variable.\n";
}

// 4. Double delete
void doubleDelete() {
    int* ptr = new int(5);
    delete ptr;
    ptr = nullptr; // Always nullify to prevent double delete
    if (ptr == nullptr) {
        cout << "Pointer nullified to avoid double delete.\n";
    }
}

// 5. Smart Pointer usage (safe)
void smartPointerExample() {
    unique_ptr<int> smartPtr = make_unique<int>(100);
    cout << "Value using smart pointer: " << *smartPtr << endl;
    // No need to delete manually
}

int main() {
    cout << "--- After Delete Example ---\n";
    afterDelete();

    cout << "\n--- Return Local Address Example ---\n";
    int* dangling = returnLocalAddress();
    cout << "Returned pointer from function now points to invalid memory (don't use it).\n";

    cout << "\n--- Out of Scope Example ---\n";
    outOfScopeExample();

    cout << "\n--- Double Delete Example ---\n";
    doubleDelete();

    cout << "\n--- Smart Pointer Example ---\n";
    smartPointerExample();

    return 0;
}
