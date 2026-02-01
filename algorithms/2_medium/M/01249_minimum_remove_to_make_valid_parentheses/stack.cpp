class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<pair<char, size_t>> stack{};

        for (size_t i{ 0 }; const auto& ch : s) {
            if (ch == '(') {
                stack.push_back({ch, i});
            } else if (ch == ')') {
                if (!stack.empty() && stack.back().first == '(') {
                    stack.pop_back();
                } else {
                    stack.push_back({ch, i});
                }
            }

            i += 1;
        }

        for (const auto [_, index] : stack) {
            s[index] = '*';
        }

        s.erase(std::remove(s.begin(), s.end(), '*'), s.end());

        return s;
    }
};
