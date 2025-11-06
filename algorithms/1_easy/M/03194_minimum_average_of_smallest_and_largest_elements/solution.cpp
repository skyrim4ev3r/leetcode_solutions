class Solution {
public:
    double minimumAverage(vector<int>& nums) {

        size_t l{0};
        size_t r{nums.size() - 1};
        double avg_min{static_cast<double>(INT_MAX)};

        sort(nums.begin(), nums.end());

        while (l < r) {
            avg_min = min(avg_min, (static_cast<double>(nums[l] + nums[r])) / 2);
            --r;
            ++l;
        }

        return avg_min;
    }
};
