class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stack;

        for (const char& ch : s) {
            if (!stack.empty() && stack.back().first == ch) {
                stack.back().second += 1;

                if (stack.back().second == k) {
                    stack.pop_back();
                }
            } else {
                    stack.push_back({ch, 1});
            }
        }

        string res {};

        for (const auto& [ch, freq] : stack) {
            for (int i{ 0 }; i < freq; ++i) {
                res.push_back(ch);
            }
        }

        return res;
    }
};
