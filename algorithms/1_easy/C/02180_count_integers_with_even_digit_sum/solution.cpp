class Solution {
public:
    int countEven(int num) {
        int count {0};

        for (int i{1}; i <= num; ++i) {
            int temp {i};
            int dig_sum {0};

            while (temp > 0) {
                dig_sum += temp % 10;
                temp /= 10;
            }

            if ((dig_sum & 1) == 0) {
                count += 1;
            }
        }

        return count;
    }
};
