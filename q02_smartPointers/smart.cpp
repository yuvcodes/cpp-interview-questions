#include <iostream>
#include <memory>  // Required for smart pointers
using namespace std;

// Demonstrates unique_ptr: A smart pointer that owns and manages a resource exclusively
void uniquePtrDemo() {
    cout << "\n--- unique_ptr Demo ---" << endl;
    // Output: --- unique_ptr Demo ---

    // Creating a unique_ptr to an integer with value 10
    unique_ptr<int> ptr = make_unique<int>(10);

    // Accessing the value inside the unique_ptr using *
    cout << "unique_ptr value: " << *ptr << endl;
    // Output: unique_ptr value: 10

    // No need to delete manually; memory is automatically freed when ptr goes out of scope
}

// Demonstrates shared_ptr: Allows multiple shared ownerships of the same resource
void sharedPtrDemo() {
    cout << "\n--- shared_ptr Demo ---" << endl;
    // Output: --- shared_ptr Demo ---

    shared_ptr<int> p1 = make_shared<int>(20);
    shared_ptr<int> p2 = p1;  // Shared ownership, use_count becomes 2

    cout << "shared_ptr value: " << *p1 << endl;
    // Output: shared_ptr value: 20

    cout << "shared_ptr use count: " << p1.use_count() << endl;
    // Output: shared_ptr use count: 2
}

// Demonstrates weak_ptr: A non-owning "observer" of a shared_ptr
void weakPtrDemo() {
    cout << "\n--- weak_ptr Demo ---" << endl;
    // Output: --- weak_ptr Demo ---

    shared_ptr<int> p1 = make_shared<int>(30);
    weak_ptr<int> wp = p1;  // wp observes p1

    cout << "shared_ptr use count: " << p1.use_count() << endl;
    // Output: shared_ptr use count: 1 (weak_ptr doesn’t count)

    // Try to lock the weak_ptr to get a shared_ptr
    if (auto sp = wp.lock()) {
        cout << "weak_ptr locked value: " << *sp << endl;
        // Output: weak_ptr locked value: 30
    } else {
        cout << "weak_ptr expired." << endl;
    }
}

int main() {
    uniquePtrDemo();
    sharedPtrDemo();
    weakPtrDemo();
    return 0;
}