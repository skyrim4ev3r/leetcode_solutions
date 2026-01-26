class Solution {
    static inline int find_min_diff(const vector<int>& arr) {
        const size_t len{ arr.size() };
        int temp_min{ numeric_limits<int>::max() };

        for (size_t i{ 0 }; i + 1 < len; ++i) {
            temp_min = std::min(temp_min, arr[i + 1] - arr[i]);
        }

        return temp_min;
    }
public:
    static vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        ranges::sort(arr);

        const size_t len{ arr.size() };
        const int min{ find_min_diff(arr) };
        vector<vector<int>> res{};

        for (size_t i{ 0 }; i + 1 < len; ++i) {
            if (min == arr[i + 1] - arr[i]) {
                res.push_back(vector<int>{arr[i], arr[i + 1]});
            }
        }

        return res;
    }
};
