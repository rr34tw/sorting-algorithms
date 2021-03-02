#include <string>

#include "sort_algorithm.hpp"

class ShellSort : public SortAlgorithm {
   public:
    std::string get_name() override { return "ShellSort"; }
    void sort(std::vector<int>& v) override {
        for (int gap = v.size() / 2; gap > 0; gap >>= 1) {
            for (int i = gap; i < v.size(); i++) {
                int target = v[i];
                int j;
                for (j = i - gap; j >= 0 && v[j] > target; j -= gap) {
                    v[j + gap] = v[j];
                }
                v[j + gap] = target;
            }
        }
    }
};