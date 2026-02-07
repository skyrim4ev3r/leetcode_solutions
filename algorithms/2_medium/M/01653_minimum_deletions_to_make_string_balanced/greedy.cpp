class Solution {
public:
    static int minimumDeletions(const string& s) {
        int res{ 0 };
        int b_count{ 0 };

        for (const auto& ch : s) {
            if (ch == 'b') {
                b_count += 1;
            } else if (b_count > 0) {
                res += 1;
                b_count -= 1;
            }
        }

        return res;
    }
};
