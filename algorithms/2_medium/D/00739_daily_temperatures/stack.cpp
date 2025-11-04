class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<pair<int, size_t>> stack{};
        const size_t len{temperatures.size()};
        vector<int> res(len, 0);

        for (auto it{temperatures.rbegin()}; it != temperatures.rend(); ++it) {
            while (!stack.empty() && stack.top().first <= *it) {
                stack.pop();
            }

            const size_t new_index {static_cast<size_t>(temperatures.rend() - it - 1)};

            if (!stack.empty()) {
                const size_t old_index = stack.top().second;
                res[new_index] = static_cast<int>(old_index - new_index);
            }

            stack.push(pair<int, size_t>(*it, new_index));
        }

        return res;
    }
};
