#include <memory>
#include <vector>

#include "sort_algorithm.hpp"

/*
 * Sorting algorithms header file.
 */
#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "selection_sort.hpp"

template <typename T>
class Sort {
    static_assert(std::is_base_of<SortAlgorithm, T>::value,
                  "typename T must be derived from SortAlgorithm.");
    T sort_algo_;

   public:
    std::string get_name() { return sort_algo_.get_name(); };
    void sort(std::vector<int>& v) { sort_algo_.sort(v); }
};