class Solution {
public:
    int countTriplets(vector<int>& arr) {
        const size_t len{arr.size()};
        int count{0};

        for (size_t i{0}; i < len; ++i) {
            int curr_xor{0};

            for (size_t j{i}; j < len; ++j) {
                curr_xor ^= arr[j];

                if (curr_xor == 0) {
                    count += static_cast<int>(j - i);
                }
            }
        }

        return count;
    }
};
