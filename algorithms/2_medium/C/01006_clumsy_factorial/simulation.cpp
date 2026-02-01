class Solution {
public:
    int clumsy(int n) {
        bool is_first{ true };
        int res{ 0 };

        while (n > 0) {
            int curr{ n };
            n -= 1;

            if (n > 0) {
                curr *= n;
                n -= 1;
            }

            if (n > 0) {
                curr /= n;
                n -= 1;
            }

            if (is_first) {
                res += curr;
                is_first = false;
            } else {
                res -= curr;
            }

            if (n > 0) {
                res += n;
                n -= 1;
            }
        }

        return res;
    }
};
