#include <bits/stdc++.h>

#include "include/sort.hpp"

#define N 25000

using namespace std;

void print_all_vector_elements(vector<int>& v) {
    for (auto& nums : v) {
        cout << nums << " ";
    }
    cout << endl;
}

template <typename T>
void test_sorted_result(Sort<T> sorting_algorithm, vector<int>& v) {
    int n = v.size();

    random_shuffle(v.begin(), v.end());

    // print_all_vector_elements(v);

    using namespace chrono;

    cout << "running: " << sorting_algorithm.get_name() << endl;
    auto begin = steady_clock::now();
    sorting_algorithm.sort(v);
    auto end = steady_clock::now();
    cout << "elapsed time: " << duration_cast<milliseconds>(end - begin).count()
         << " ms." << endl
         << endl;

    // print_all_vector_elements(v);

    if (v.size() != n) {
        throw length_error("The size of the vector has been changed.");
    }
    for (int i = 0; i < n - 1; i++) {
        if (v[i] + 1 != v[i + 1]) {
            throw runtime_error("The vector has been modified.");
        }
    }
}

int main() {
    vector<int> v(N);

    // 0 ~ N-1
    iota(v.begin(), v.end(), 0);

    try {
        test_sorted_result(Sort<BubbleSort>(), v);
    }
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
    catch (...) {
        cerr << "An unexpected exception occurred." << endl;
    }

    return 0;
}