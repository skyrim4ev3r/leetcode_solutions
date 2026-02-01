class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum{ 0 };
        vector<int> res;
        res.reserve(queries.size());

        for (const auto& num : nums) {
            if ((num & 1) == 0) {
                sum += num;
            }
        }

        for (const auto& q : queries) {
            const int val{ q[0] };
            const size_t index{ static_cast<size_t>(q[1]) };

            if ((nums[index] & 1) == 0) {
                sum -= nums[index];
            }

            nums[index] += val;

            if ((nums[index] & 1) == 0) {
                sum += nums[index];
            }

            res.push_back(sum);
        }

        return res;
    }
};
