class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const size_t len{nums.size()};
        const int median{nums[len / 2]};
        int cost{0};

        for (const int& num : nums) {
            cost += abs(num - median);
        }

        return cost;
    }
};
