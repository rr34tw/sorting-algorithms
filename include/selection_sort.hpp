#include <string>

#include "sort_algorithm.hpp"

class SelectionSort : public SortAlgorithm {
   public:
    std::string get_name() override { return "SelectionSort"; }
    void sort(std::vector<int>& v) override {
        for (int i = 0; i < v.size(); i++) {
            int min_idx = i;
            for (int j = i + 1; j < v.size(); j++) {
                if (v[j] < v[min_idx]) {
                    min_idx = j;
                }
            }
            std::swap(v[i], v[min_idx]);
        }
    }
};