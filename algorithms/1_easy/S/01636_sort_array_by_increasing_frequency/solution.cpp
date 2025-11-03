class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        vector<int> res{};
        res.reserve(nums.size());
        unordered_map<int, char> map{};

        for (const int &num: nums) {
            map[num] += 1;
        }

        auto map_vec = vector<pair<int, char>> (map.begin(), map.end());
        sort(map_vec.begin(), map_vec.end(),[](auto a, auto b) {
            if (a.second == b.second) {
                return a.first > b.first;
            } else {
                return a.second < b.second;
            }
        });

        for (const auto &it: map_vec) {
            for (auto i{0}; i < it.second; ++i) {
                res.push_back(it.first);
            }
        }

        return res;
    }
};
