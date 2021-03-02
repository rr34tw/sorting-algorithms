#include <algorithm>
#include <string>

#include "sort_algorithm.hpp"

class STLSort : public SortAlgorithm {
   public:
    std::string get_name() override { return "STLSort"; }
    void sort(std::vector<int>& v) override { std::sort(v.begin(), v.end()); }
};