//
// Created by smmm on 19.06.2025.
//

#include <iostream>
#include <list>
#include <forward_list>
#include <algorithm>
#include <vector>

void demo_list() {
    std::cout << "===== std::list DEMO =====\n";

    std::list<int> lst = {1, 2, 3};
    lst.push_front(0);
    lst.push_back(4);

    auto it = std::next(lst.begin(), 2);
    lst.insert(it, 10);

    std::cout << "Initial: ";
    for (int n : lst) std::cout << n << " ";
    std::cout << "\n";

    lst.erase(it);

    lst.remove_if([](int x) { return x % 2 == 0; }); // [1,3]

    lst = {1, 3, 2, 2, -8, 5, 1, 1, 1, 2};

    lst.unique();
    lst.sort();
    lst.reverse();

    std::list<int> lst2 = {10, 20, 30};
    lst.splice(lst.begin(), lst2);

    std::cout << "After ops: ";
    for (int n : lst) std::cout << n << " ";
    std::cout << "\n\n";
}

void demo_forward_list() {
    std::cout << "===== std::forward_list DEMO =====\n";

    std::forward_list<int> flst = {1, 2, 3};
    flst.push_front(0);

    auto it = flst.begin();
    flst.insert_after(it, 10);

    flst.erase_after(it);

    flst.remove_if([](int x) { return x < 2; }); // [2,3]

    flst = {1, 3, 2, 2, -8, 5, 1, 1, 1, 2};

    flst.unique();

    flst.sort();

    flst.reverse();

    std::forward_list<int> flst2 = {10, 20, 30};
    flst.splice_after(flst.before_begin(), flst2);

    size_t count = 0;
    for (auto it = flst.begin(); it != flst.end(); ++it) count++;
}

int main() {
    demo_list();
    demo_forward_list();
    return 0;
}
