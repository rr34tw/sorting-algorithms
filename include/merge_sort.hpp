#include <string>

#include "sort_algorithm.hpp"

class MergeSort : public SortAlgorithm {
   public:
    std::string get_name() override { return "MergeSort"; }
    void sort(std::vector<int>& v) override {
        std::vector<int> t(v.size());
        for (int gap = 1; gap < v.size(); gap *= 2) {
            for (int i = 0; i < v.size(); i += gap * 2) {
                int low = i, mid = std::min(i + gap, (int)v.size()),
                    high = std::min(i + gap * 2, (int)v.size());
                int l = low, r = mid, cur = i;
                while (l < mid && r < high) {
                    t[cur++] = v[l] < v[r] ? v[l++] : v[r++];
                }
                while (l < mid) {
                    t[cur++] = v[l++];
                }
                while (r < high) {
                    t[cur++] = v[r++];
                }
            }

            // swap vectors by their pointers
            // same as t.swap(v) or v.swap(t)
            std::swap(t, v);
        }
    }
};