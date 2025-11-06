class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum{0};

        for (auto it{prices.cbegin() + 1}; it != prices.cend(); ++it) {
            sum = sum + max(0, *it - *(it - 1));
        }

        return sum;
    }
};
