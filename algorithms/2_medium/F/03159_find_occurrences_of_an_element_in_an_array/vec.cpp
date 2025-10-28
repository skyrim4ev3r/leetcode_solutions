class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> occurrences_vec{};
        const size_t nums_len{nums.size()};

        for (size_t index{0}; index < nums_len; ++index) {
            if (nums[index] == x) {
                occurrences_vec.push_back(static_cast<int>(index));
            }
        }

        vector<int> res{};
        res.reserve(queries.size());
        size_t occurrences_vec_len{occurrences_vec.size()};

        for (const auto &query: queries) {
            size_t index = static_cast<size_t>(query) - 1;

            if (index >= occurrences_vec_len) {
                res.push_back(-1);
            } else {
                res.push_back(occurrences_vec[index]);
            }
        }

        return res;
    }
};
