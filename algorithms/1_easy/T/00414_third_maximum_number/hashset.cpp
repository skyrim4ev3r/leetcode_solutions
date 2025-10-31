class Solution {
public:
    int thirdMax(vector<int>& nums) {

        unordered_set<int> distinct_nums_set{nums.begin(), nums.end()};
        vector<int> distinct_nums_vec{distinct_nums_set.begin(), distinct_nums_set.end()};

        sort(distinct_nums_vec.rbegin(), distinct_nums_vec.rend());

        if (distinct_nums_vec.size() < 3) {
            return distinct_nums_vec[0];
        }

        return distinct_nums_vec[2];
    }
};
