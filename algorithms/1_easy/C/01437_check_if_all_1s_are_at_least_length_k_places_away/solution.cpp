class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int curr_distance{k};

        for (const int& num : nums) {
            if (num == 1) {
                if (curr_distance < k) {
                    return false;
                }

                curr_distance = 0;
            } else {
                curr_distance += 1;
            }
        }

        return true;
    }
};
