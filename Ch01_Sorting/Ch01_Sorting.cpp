// Ch01_Sorting.cpp
// Created 8/24/2020 7:01:04 PM

#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << '{';
    int n = v.size();
    if (n > 0) {
        os << v[0];
        for (int i = 1; i < n; i++)
            os << ',' << v[i];
    }
    os << '}';
    return os;
}

//void selection_sort(std::vector<int>& v) {
//    int n = v.size();
//    for (int i = 0; i < n - 1; i++) {
//        int smallest = i;
//        for (int j = i + 1; j < n; j++)
//            if (v[j] < v[smallest])
//                smallest = j;
//        if (smallest != i)
//            std::swap(v[i], v[smallest]);
//    }
//}

std::vector<int> selection_sort(std::vector<int>& v, 
                                std::function<bool(int, int)> comparer) {
    int n = v.size();
    std::vector<int> result(n);
    std::iota(result.begin(), result.end(), 0);
    std::cout << "result starts out as: " << result << '\n';

    for (int i = 0; i < n - 1; i++) {
        int smallest = i;
        for (int j = i + 1; j < n; j++)
            if (comparer(v[j], v[smallest]))
                smallest = j;
        if (smallest != i)
            std::swap(v[i], v[smallest]);
    }
    return result;
}

//bool less_than(int a, int b) {
//    return a < b;
//}
//
//bool greater_than(int a, int b) {
//    return a > b;
//}

int main() {
    std::vector<int> original{ 45, 2, 17, 22, 2, 51, 80, 32, 7 },
                     working;

    working = original;
    std::cout << "Before: " << working << '\n';
    selection_sort(working, [](int a, int b) { return a > b; });
    std::cout << "After : " << working << '\n';
    std::cout << "Orig. : " << original << '\n';
    
}
