class Solution {
public:
    int maxOperations(vector<int>& nums) {
        const size_t len {nums.size()};
        const int first_sum {nums[0] + nums[1]};
        int count {0};

        for (int i {0}; i < len; i += 2) {
            if (i + 1 < len && nums[i] + nums[i + 1] == first_sum) {
                count += 1;
            } else {
                break;
            }
        }

        return count;
    }
};
