#include <string>

#include "sort_algorithm.hpp"

class BubbleSort : public SortAlgorithm {
   public:
    std::string get_name() override { return "BubbleSort"; };
    void sort(std::vector<int>& v) override {
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                if (v[i] > v[j]) {
                    std::swap(v[i], v[j]);
                }
            }
        }
    }
};