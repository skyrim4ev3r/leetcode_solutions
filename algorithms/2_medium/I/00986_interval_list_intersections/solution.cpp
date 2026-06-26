typedef ptrdiff_t isize;

class Solution {
public:
    static vector<vector<int>> intervalIntersection(const vector<vector<int>>& l1, const vector<vector<int>>& l2) {
        auto res = vector<vector<int>>();
        const isize len1 = std::ssize(l1);
        const isize len2 = std::ssize(l2);
        isize idx1 = 0;
        isize idx2 = 0;

        while (idx1 < len1 && idx2 < len2) {
            const int lo = std::max(l1[idx1][0], l2[idx2][0]);
            const int hi = std::min(l1[idx1][1], l2[idx2][1]);

            if (lo <= hi)  {
                res.push_back(vector<int>{lo, hi});
            }

            if (l1[idx1][1] == hi) {
                idx1 += 1;
            }

            if (l2[idx2][1] == hi) {
                idx2 += 1;
            }
        }

        return res;
    }
};
