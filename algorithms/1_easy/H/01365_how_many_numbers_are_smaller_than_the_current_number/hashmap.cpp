class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        const size_t len{nums.size()};
        vector<int> sorted_nums{nums};
        sort(sorted_nums.begin(), sorted_nums.end());

        unordered_map<int, int> counts;

        for (size_t i = 0; i < len; ++i) {
            if (i > 0 && sorted_nums[i] == sorted_nums[i - 1]) {
                    continue;
            }

            counts[sorted_nums[i]] = static_cast<int>(i);
        }

        vector<int> res;
        res.reserve(len);

        for (int &num: nums) {
            res.push_back(counts[num]);
        }

        return res;
    }
};
