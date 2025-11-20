class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int final_res{0};

        for (int num : nums) {
            int dig_count{0};
            int max_dig{0};

            while (num > 0) {
                int curr_dig{num % 10};
                num /= 10;

                max_dig = max(max_dig, curr_dig);
                dig_count += 1;
            }

            int curr_res{0};
            for (size_t i{0}; i < dig_count; ++i) {
                curr_res *= 10;
                curr_res += max_dig;
            }

            final_res += curr_res;
        }

        return final_res;
    }
};
