class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {

        const size_t len{heights.size()};
        vector<int> res(len, 0);
        stack<int> stack{};

        for (size_t i{len - 1}; i < len; --i) {
            while (!stack.empty()) {
                res[i] += 1;

                int val = stack.top();
                if (val <= heights[i]) {
                    stack.pop();
                } else {
                    break;
                }
            }

            stack.push(heights[i]);
        }

        return res;
    }
};
