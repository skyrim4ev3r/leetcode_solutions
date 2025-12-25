class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        const size_t k_usize{static_cast<size_t>(k)};

        ranges::sort(score, [k_usize](const auto& a, const auto& b) {
            return a[k_usize] > b[k_usize];
        });

        return score;
    }
};
