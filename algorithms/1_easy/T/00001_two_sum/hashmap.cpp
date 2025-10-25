class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        const size_t len{nums.size()};
        unordered_map <int, int> hashmap{};
        vector<int> res{};

        for (size_t i{0}; i < len; ++i) {

            auto it = hashmap.find(target-nums[i]);

            if (it != hashmap.end()) {
                res.push_back(it->second);
                res.push_back(static_cast<int>(i));
                return res;
            }

            hashmap[nums[i]] = static_cast<int>(i);
        }

        return res;
    }
};
