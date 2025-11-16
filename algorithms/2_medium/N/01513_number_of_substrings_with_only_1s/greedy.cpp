class Solution {
public:
    int numSub(string s) {
        const int mod_to{1'000'000'007};
        int total_count{0};
        int curr_count{0};

        for (const char& ch : s) {
            if (ch == '1') {
                curr_count += 1;
            } else {
                curr_count = 0;
            }

            total_count = (total_count + curr_count) % mod_to;
        }

        return total_count;
    }
};
