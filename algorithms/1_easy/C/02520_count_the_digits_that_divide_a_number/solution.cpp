class Solution {
public:
    int countDigits(int num) {

        int num_cp{num};
        int count{0};

        while (num_cp > 0) {
            int dig = num_cp % 10;
            num_cp /= 10;

            if (dig == 0) {
                continue;
            }

            if (num % dig == 0) {
                count += 1;
            }
        }

        return count;
    }
};
