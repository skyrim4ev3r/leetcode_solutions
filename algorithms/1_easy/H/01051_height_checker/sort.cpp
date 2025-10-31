class Solution {
public:
    int heightChecker(vector<int>& heights) {

        int count{0};
        const size_t len{heights.size()};

        vector<int> heights_sorted{heights};
        sort(heights_sorted.begin(), heights_sorted.end());

        for (size_t i{0}; i < len; ++i) {
            if (heights[i] != heights_sorted[i]) {
                count += 1;
            }
        }

        return count;
    }
};
