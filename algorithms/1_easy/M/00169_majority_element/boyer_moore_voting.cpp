class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority_candidate{0};
        int count{0};

        for (const int &num: nums) {
            if (count == 0) {
                majority_candidate = num;
                count = 1;
            } else if (majority_candidate == num) {
                count += 1;
            } else {
                count -= 1;
            }
        }

        return majority_candidate;
    }
};
