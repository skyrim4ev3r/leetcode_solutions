class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res;
        res.reserve(static_cast<size_t>(a + b));

        while (a > 0 || b > 0) {
            const size_t len{ res.size() };

            if (len >= 2 && res[len - 1] == res[len - 2]) {
                if (res[len - 1] == 'a') {
                    res.push_back('b');
                    b -= 1;
                } else {
                    res.push_back('a');
                    a -= 1;
                }
            } else if (a >= b) {
                res.push_back('a');
                a -= 1;
            } else {
                res.push_back('b');
                b -= 1;
            }
        }

        return res;
    }
};
