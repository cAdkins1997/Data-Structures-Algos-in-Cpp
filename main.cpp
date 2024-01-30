#include <iostream>
#include <algorithm>
#include <ctime>

#include <vector>
#include <list>

#include "LinkedList.h"
#include "DArray.h"

using namespace wstd;

int main() {
    wstd::DArray<int> dArray(10);
    std::vector<int> vector(10);

    wstd::LinkedList<int> linkedList;
    std::list<int> list;

    clock_t start = clock();

    for (int i = 0; i < 100000; i++) {
        dArray.push_back(i);
    }

    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    std::cout << "Pushing into dynamic array took " << seconds << '\n';

    start = clock();

    for (int i = 0; i < 100000; i++) {
        vector.push_back(i);
    }

    end = clock();
    seconds = (float)(end - start) / CLOCKS_PER_SEC;

    std::cout << "Pushing back into std::vector took " << seconds << '\n';

    start = clock();

    for (int i = 0; i < 100000; i++) {
        linkedList.append(i);
    }

    end = clock();
    seconds = (float)(end - start) / CLOCKS_PER_SEC;

    std::cout << "Appending to linked list " << seconds << '\n';

    start = clock();

    for (int i = 0; i < 100000; i++) {
        list.push_back(i);
    }

    end = clock();
    seconds = (float)(end - start) / CLOCKS_PER_SEC;

    std::cout << "Pushing back into std::list took " << seconds << '\n';
}
