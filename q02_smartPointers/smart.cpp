// smart_pointers_full_code.cpp
// Demonstrates unique_ptr, shared_ptr, weak_ptr in one running example

#include <iostream>
#include <memory>
using namespace std;

void uniquePtrDemo() {
    cout << "\n--- unique_ptr Demo ---" << endl;
    unique_ptr<int> ptr = make_unique<int>(10);
    cout << "unique_ptr value: " << *ptr << endl;
    // No delete needed
}

void sharedPtrDemo() {
    cout << "\n--- shared_ptr Demo ---" << endl;
    shared_ptr<int> p1 = make_shared<int>(20);
    shared_ptr<int> p2 = p1; // Shared ownership
    cout << "shared_ptr value: " << *p1 << endl;
    cout << "shared_ptr use count: " << p1.use_count() << endl;
}

void weakPtrDemo() {
    cout << "\n--- weak_ptr Demo ---" << endl;
    shared_ptr<int> p1 = make_shared<int>(30);
    weak_ptr<int> wp = p1; // Observes but doesn’t own
    cout << "shared_ptr use count: " << p1.use_count() << endl;

    if (auto sp = wp.lock()) {
        cout << "weak_ptr locked value: " << *sp << endl;
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
