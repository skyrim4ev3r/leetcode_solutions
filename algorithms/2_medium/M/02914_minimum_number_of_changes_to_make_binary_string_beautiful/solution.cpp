class Solution {
public:
    int minChanges(string s) {

        const size_t len{s.size()};
        int count{0};

        for (size_t index{1}; index < len; index += 2) {
            if (s[index] != s[index - 1]) {
                count += 1;
            }
        }

        return count;
    }
};
