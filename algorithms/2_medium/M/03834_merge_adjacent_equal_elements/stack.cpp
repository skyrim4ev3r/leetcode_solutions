class Solution {
public:
    static vector<long long> mergeAdjacent(const vector<int>& nums) {
        vector<long long> stack{};

        for (const auto& num : nums) {
            long long temp{ static_cast<long long>(num) };

            while (!stack.empty() && stack.back() == temp) {
                temp *= 2;
                stack.pop_back();
            }

            stack.push_back(temp);
        }

        return stack;
    }
};
