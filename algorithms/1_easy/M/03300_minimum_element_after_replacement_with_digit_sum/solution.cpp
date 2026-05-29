class Solution {
public:
    static int minElement(const vector<int>& nums) {
        int res = numeric_limits<int>::max();

        for (auto num : nums) {
            int sum = 0;

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            res = std::min(res, sum);
        }

        return res;
    }
};
