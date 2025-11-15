class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stack{};
        const size_t len{prices.size()};
        vector<int> res(len, 0);

        for (auto it{prices.rbegin()}, it_res{res.rbegin()}; it != prices.rend(); ++it, ++it_res) {
            while (!stack.empty() && stack.top() > *it) {
                stack.pop();
            }

            if (!stack.empty()) {
                *it_res = *it - stack.top();
            } else {
                *it_res = *it;
            }

            stack.push(*it);
        }

        return res;
    }
};
