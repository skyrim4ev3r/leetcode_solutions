class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int nums_xor{reduce(nums.begin(), nums.end(), 0, bit_xor<int>())};
        //least_bit_one INT_MIN is INT_MIN,
        int least_bit_one{nums_xor == numeric_limits<int>::min() ? nums_xor : nums_xor & (-nums_xor)};
        int num1{0};
        int num2{0};

        for (const int& num : nums) {
            if ((least_bit_one & num) == 0) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }

        return vector<int>{num1, num2};
    }
};
