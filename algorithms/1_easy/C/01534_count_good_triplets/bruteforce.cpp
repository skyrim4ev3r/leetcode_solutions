class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        const size_t len {arr.size()};
        int count{0};

        for (size_t i{0}; i < len; ++i) {
            for (size_t j{i + 1}; j < len; ++j) {
                for (size_t k{j + 1}; k < len; ++k) {
                    if (
                        abs(arr[i] - arr[j]) <= a &&
                        abs(arr[j] - arr[k]) <= b &&
                        abs(arr[i] - arr[k]) <= c
                    ) {
                        count += 1;
                    }
                }
            }
        }

        return count;
    }
};
