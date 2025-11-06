class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        const size_t MAX_NUM{100};
        array<int, MAX_NUM> freqs{};

        for (const int &num: nums) {
            freqs[static_cast<size_t>(num)] += 1;
        }

        vector<int> res{};
        for (size_t i{0}; i < MAX_NUM; ++i) {
            if (freqs[i] > 1) {
                res.push_back(static_cast<int>(i));
            }
        }

        return res;
    }
};
