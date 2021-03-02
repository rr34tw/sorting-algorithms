#include <string>

#include "sort_algorithm.hpp"

class InsertionSort : public SortAlgorithm {
   public:
    std::string get_name() override { return "InsertionSort"; }
    void sort(std::vector<int>& v) override {
        for (int i = 1; i < v.size(); i++) {
            int target = v[i];
            int j;
            for (j = i - 1; v[j] > target && j >= 0; j--) {
                v[j + 1] = v[j];
            }
            v[j + 1] = target;
        }
    }
};