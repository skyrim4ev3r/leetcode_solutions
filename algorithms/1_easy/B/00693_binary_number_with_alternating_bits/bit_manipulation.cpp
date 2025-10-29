class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev_remainder{-1};

        while (n > 0) {
            int curr_remainder{n & 1};
            if (curr_remainder == prev_remainder) {
                return false;
            }

            prev_remainder = curr_remainder;
            n = (n >> 1);;
        }

        return true;
    }
};
