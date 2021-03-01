#include <string>
#include <vector>

#ifndef SORT_ALGORITHM_HPP
#define SORT_ALGORITHM_HPP
class SortAlgorithm {
   public:
    SortAlgorithm() {}
    virtual ~SortAlgorithm() {}

    virtual std::string get_name() = 0;
    virtual void sort(std::vector<int>&) = 0;
};
#endif