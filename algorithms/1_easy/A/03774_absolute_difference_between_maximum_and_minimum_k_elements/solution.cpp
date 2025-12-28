class Solution {
public:
    static int absDifference(vector<int>& nums, int k) {
        if (nums.size() == static_cast<size_t>(k)) {
            return 0;
        }

        ranges::sort(nums);

        const int sum_k_largest {reduce(
            nums.end() - static_cast<size_t>(k),
            nums.end(),
            0
        )};

        const int sum_k_smallet {reduce(
            nums.begin(),
            nums.begin() + static_cast<size_t>(k),
            0
        )};

        return abs(sum_k_largest - sum_k_smallet);
    }
};
