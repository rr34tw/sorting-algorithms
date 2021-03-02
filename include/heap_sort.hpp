#include <string>

#include "sort_algorithm.hpp"

class HeapSort : public SortAlgorithm {
    void max_heapify(std::vector<int>& v, int idx, int end) {
        int dad = idx;
        for (int son = dad * 2 + 1; son < end; dad = son, son = son * 2 + 1) {
            if (son + 1 < end && v[son + 1] > v[son]) {
                son++;
            }
            if (v[dad] > v[son]) {
                return;
            }
            else {
                std::swap(v[dad], v[son]);
            }
        }
    }
   public:
    std::string get_name() override { return "HeapSort"; }
    void sort(std::vector<int>& v) override {
        for (int i = v.size() / 2 - 1; i >= 0; i--) {
            max_heapify(v, i, v.size());
        }
        for (int i = v.size() - 1; i > 0; i--) {
            std::swap(v[0], v[i]);
            max_heapify(v, 0, i);
        }
    }
};