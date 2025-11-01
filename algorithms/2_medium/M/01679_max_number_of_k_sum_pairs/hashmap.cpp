class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        unordered_map<int, int> map{};
        int count{0};

        for (const int &num: nums) {
            const int other{k - num};
            auto it{map.find(other)};

            if (it != map.end() && it->second > 0) {
                it->second -= 1;
                count += 1;
            } else {
                map[num] += 1;
            }
        }

        return count;
    }
};
