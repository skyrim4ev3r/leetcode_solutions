class Solution {
public:
    static int minAllOneMultiple(const int k) {
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }

        int curr_rem {0};

        for (int dig_count {1}; dig_count <= k; ++dig_count) {
            curr_rem = (curr_rem * 10 + 1) % k;

            if (curr_rem == 0) {
                return dig_count;
            }
        }

        return -1;
    }
};
