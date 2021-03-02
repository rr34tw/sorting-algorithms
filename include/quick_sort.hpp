#include <stack>
#include <string>

#include "sort_algorithm.hpp"

class QuickSort : public SortAlgorithm {
    void quick_sort(std::vector<int>& v) {
        std::stack<std::pair<int, int>> st;
        st.push(std::make_pair(0, v.size()));
        while (!st.empty()) {
            int begin = st.top().first, end = st.top().second;
            st.pop();
            int pivot = partition(v, begin, end);

            // if there have elements on left side of the pivot
            if (begin + 1 < pivot) {
                st.push(std::make_pair(begin, pivot));
            }

            // if there have elements on right side of the pivot
            if (pivot < end - 1) {
                st.push(std::make_pair(pivot, end));
            }
        }
    }
    int partition(std::vector<int>& v, int begin, int end) {
        int last_idx = end - 1, pivot_value = v[last_idx], cur = begin;
        for (int i = begin; i < last_idx; i++) {
            if (v[i] <= pivot_value) {
                std::swap(v[i], v[cur++]);
            }
        }
        std::swap(v[cur], v[last_idx]);
        return cur;
    }

   public:
    std::string get_name() override { return "QuickSort"; }
    void sort(std::vector<int>& v) override { quick_sort(v); }
};