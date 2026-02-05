class Solution {
    static inline pair<long long, bool> check_state_zero(
        const vector<int>& nums,
        const array<pair<long long, bool>, 3>& prev_state,
        const size_t& i
    ) {
        if (nums[i - 1] < nums[i]) {
             if (prev_state[0].second == false) {
                return { static_cast<long long>(nums[i - 1] + nums[i]), true };
             } else {
                return { nums[i] + std::max(prev_state[0].first, static_cast<long long>(nums[i - 1])), true };
             }
        }

        return {0, false};
    }

    static inline pair<long long, bool> check_state_one(
        const vector<int>& nums,
        const array<pair<long long, bool>, 3>& prev_state,
        const size_t& i
    ) {
        if (nums[i - 1] > nums[i]) {
             if (prev_state[1].second == false) {
                if (prev_state[0].second == true) {
                    return { static_cast<long long>(nums[i]) + prev_state[0].first, true };
                }
             } else {
                return { static_cast<long long>(nums[i]) + prev_state[1].first, true };
             }
        }

        return {0, false};
    }

    static inline pair<long long, bool> check_state_two(
        const vector<int>& nums,
        const array<pair<long long, bool>, 3>& prev_state,
        const size_t& i
    ) {
        if (nums[i - 1] < nums[i]) {
             if (prev_state[2].second == false) {
                if (prev_state[1].second == true) {
                    return { static_cast<long long>(nums[i]) + prev_state[1].first, true };
                }
             } else {
                return { static_cast<long long>(nums[i]) + prev_state[2].first, true };
             }
        }

        return {0, false};
    }
public:
    static long long maxSumTrionic(const vector<int>& nums) {
        const size_t len{ nums.size() };
        array<pair<long long, bool>, 3> prev_state{ pair<long long, bool>{0, false}, {0, false}, {0, false}};
        array<pair<long long, bool>, 3> curr_state{ pair<long long, bool>{0, false}, {0, false}, {0, false}};
        pair<long long, bool> res{ pair<long long, bool>{0, false} };

        for (size_t i{ 1 }; i < len; ++i) {
            curr_state[0] = check_state_zero(nums, prev_state, i);
            curr_state[1] = check_state_one(nums, prev_state, i);
            curr_state[2] = check_state_two(nums, prev_state, i);

            if (curr_state[2].second == true) {
                if (res.second == true) {
                    res.first = std::max(res.first, curr_state[2].first);
                } else {
                    res.first = curr_state[2].first;
                    res.second = true;
                }
            }

            prev_state = curr_state;
        }

        if (res.second == false) {
            throw "unreachable!"; // It is guaranteed that at least one trionic subarray exists
        }

        return res.first;
    }
};
