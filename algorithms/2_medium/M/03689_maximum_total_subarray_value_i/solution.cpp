class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        int max{INT_MIN};
        int min{INT_MAX};

        for (const int &num: nums) {
            min = std::min(min, num);
            max = std::max(max, num);
        }

        return static_cast<long long>(max - min) * static_cast<long long>(k);
    }
};
