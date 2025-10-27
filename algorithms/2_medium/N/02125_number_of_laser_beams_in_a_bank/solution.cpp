class Solution {
public:
    int numberOfBeams(vector<string>& bank) {

        int res{0};
        int prev_valid_count{0};

        for (auto &row: bank) {
            int curr_count = std::count(row.begin(), row.end(), '1');

            if (curr_count > 0) {
                res += prev_valid_count * curr_count;
                prev_valid_count = curr_count;
            }
        }

        return res;
    }
};
