class Solution {
    int solve(vector<int> &mem, string &s, const size_t len, size_t pos) {
        if (pos == len) {
            return 1;
        }

        if (mem[pos] > -1) {
            return mem[pos];
        }

        if(s[pos] == '0') {
            mem[pos] = 0;
            return 0;
        }

        int res = solve(mem, s, len, pos + 1);
        if (pos + 1 < len && (s[pos] == '1' || (s[pos] == '2' && s[pos + 1] < '7'))) {
            res += solve(mem, s, len, pos + 2);
        }

        mem[pos] = res;

        return res;
    }
public:
    int numDecodings(string s) {
        vector<int> mem(s.size(), -1);
        return solve(mem, s, s.size(), 0);
    }
};
