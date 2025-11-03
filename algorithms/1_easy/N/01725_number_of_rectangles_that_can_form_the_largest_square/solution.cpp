class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int max_len{-1};
        int count{0};

        for (const auto &rec: rectangles) {
            int curr_len{min(rec[0], rec[1])};

            if (max_len < curr_len) {
                max_len = curr_len;
                count = 1;
            } else if (max_len == curr_len) {
                count += 1;
            }
        }

        return count;
    }
};
