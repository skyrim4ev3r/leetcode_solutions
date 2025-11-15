class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stack{};
        const size_t len{prices.size()};
        vector<int> res(len, 0);

        for (size_t i{len - 1}; i < len; --i) {
            while (!stack.empty() && stack.top() > prices[i]) {
                stack.pop();
            }

            if (!stack.empty()) {
                res[i] = prices[i] - stack.top();
            } else {
                res[i] = prices[i];
            }

            stack.push(prices[i]);
        }

        return res;
    }
};
