class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count{0};

        for (const int &num: nums) {
            if (num % 3 != 0) {
                count += 1;
            }
        }

        return count;
    }
};
