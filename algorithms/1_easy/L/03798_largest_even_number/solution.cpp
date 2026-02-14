class Solution {
public:
    static string largestEven(string s) {
        while (!s.empty() && s.back() == '1') {
            s.pop_back();
        }

        return s;
    }
};
