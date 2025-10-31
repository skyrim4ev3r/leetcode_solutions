class Solution {
public:
    int fib(int n) {
        int prev{1}, res{0}, tmp{0};

        for(int i{1}; i <= n; ++i) {
            tmp = res;
            res += prev;
            prev = tmp;
        }

        return res;
    }
};
