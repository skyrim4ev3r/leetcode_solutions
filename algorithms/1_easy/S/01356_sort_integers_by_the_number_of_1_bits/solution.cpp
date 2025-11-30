class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
            const auto a_count_ones{__builtin_popcount(a)};
            const auto b_count_ones{__builtin_popcount(b)};

            if (a_count_ones == b_count_ones) {
                return a < b;
            } else {
                return a_count_ones < b_count_ones;
            }
        });

        return arr;
    }
};
