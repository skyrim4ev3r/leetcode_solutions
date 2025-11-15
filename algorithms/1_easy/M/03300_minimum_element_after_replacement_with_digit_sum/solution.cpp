class Solution {
public:
    int minElement(vector<int>& nums) {
        int min{numeric_limits<int>::max()};

        for (int num : nums) {
            int sum{0};

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            min = std::min(min, sum);
        }

        return min;
    }
};
