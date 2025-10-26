class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        size_t left{0};
        size_t right{nums.size() - 1};
        int max_sum{0}; //maximum sum of minimized pairs  

        while (left < right) {
            max_sum = max(max_sum, nums[left] + nums[right]);
            left += 1;
            right -= 1;
        }

        return max_sum;
    }
};
