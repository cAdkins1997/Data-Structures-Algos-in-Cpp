#include <iostream>
#include <algorithm>
#include <ctime>

#include <vector>
#include <list>
#include <chrono>

#include "LinkedList.h"
#include "DArray.h"

using namespace std::chrono;
using namespace std::literals;

void benchmark(const time_point<high_resolution_clock>& startTime, const time_point<high_resolution_clock>& stopTime,
              const char* outputMessage) {
    duration<long double> dur = stopTime - startTime;
    std::cout << outputMessage << duration_cast<nanoseconds>(dur) << '\n';
}

int main() {
    wstd::DArray<int> dArray(10);
    std::vector<int> vector(10);

    wstd::LinkedList<int> linkedList;
    std::list<int> list;

    auto startTime = high_resolution_clock::now();

    for (int i = 0; i < 100000; i++) {
        dArray.push_back(i);
    }

    auto endTime = high_resolution_clock::now();
    benchmark(startTime, endTime, "Pushing back into dArray took: ");

    startTime = high_resolution_clock::now();

    for (int i = 0; i < 100000; i++) {
        vector.push_back(i);
    }

    endTime = high_resolution_clock::now();
    benchmark(startTime, endTime, "Pushing back into std::vector took: ");

    startTime = high_resolution_clock::now();

    for (int i = 0; i < 100000; i++) {
        linkedList.append(i);
    }

    endTime = high_resolution_clock::now();
    benchmark(startTime, endTime, "Appending to linked list took: ");

    startTime = high_resolution_clock::now();

    for (int i = 0; i < 100000; i++) {
        list.push_back(i);
    }

    endTime = high_resolution_clock::now();
    benchmark(startTime, endTime, "Appending to std::list took: ");
}
