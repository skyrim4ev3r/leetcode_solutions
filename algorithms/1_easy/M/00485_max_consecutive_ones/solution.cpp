class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int max{0};
        int curr{0};

        for (const int &num: nums) {
            if (num == 1) {
                curr += 1;
                max = std::max(max, curr);
            } else {
                curr = 0;
            }
        }

        return max;
    }
};
