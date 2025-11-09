class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller_count{0};
        int freq{0};

        for (const int &num: nums) {
            if (num < target) {
                smaller_count += 1;
            } else if (num == target) {
                freq += 1;
            }
        }

        vector<int> res;
        res.reserve(static_cast<size_t>(freq));

        for (int i{smaller_count}; i < smaller_count + freq; ++i) {
            res.push_back(i);
        }

        return res;
    }
};
