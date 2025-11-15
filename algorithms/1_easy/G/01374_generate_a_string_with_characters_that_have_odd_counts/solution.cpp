class Solution {
public:
    string generateTheString(int n) {
        string res(static_cast<size_t>(n), 'a');

        if (n % 2 == 0) {
            *(res.end() - 1) = 'b';
        }

        return res;
    }
};
