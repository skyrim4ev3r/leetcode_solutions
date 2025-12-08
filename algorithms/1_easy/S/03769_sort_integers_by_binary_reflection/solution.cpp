class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int& a, const int& b) {
            auto manual_rev_bin = [](int num) -> int {
                int rev{0};

                while (num > 0) {
                    rev = rev << 1;
                    rev |= (num & 1);
                    num = num >> 1;
                }

                return rev;
            };

            int rev_a = manual_rev_bin(a);
            int rev_b = manual_rev_bin(b);

            if (rev_a == rev_b) {
                return a < b;
            }

            return rev_a < rev_b;
        });

        return nums;
    }
};
