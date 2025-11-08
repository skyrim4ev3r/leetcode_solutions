class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sum{0};
        bool flip_flop{true};

        for (const int &num: nums) {
            if (flip_flop) {
                sum += num;
            } else {
                sum -= num;
            }

            flip_flop = !flip_flop;
        }

        return sum;
    }
};
