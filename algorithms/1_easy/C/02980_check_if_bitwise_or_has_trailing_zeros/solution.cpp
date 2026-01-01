class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int even_count {0};

        for (const int& num : nums) {
            if ((num & 1) == 0) {
                even_count += 1;

                if (even_count > 1) {
                    return true;
                }
            }
        }

        return false;
    }
};
