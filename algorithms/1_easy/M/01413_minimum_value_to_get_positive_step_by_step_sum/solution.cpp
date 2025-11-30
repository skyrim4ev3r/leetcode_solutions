class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min_sum{numeric_limits<int>::max()};
        int curr_sum{0};

        for (const int& num : nums) {
            curr_sum += num;
            min_sum = std::min(min_sum, curr_sum);
        }

        return std::max(1, min_sum * -1 + 1);
    }
};
