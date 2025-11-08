class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int avg{std::reduce(nums.begin(), nums.end(), 0) / static_cast<int>(nums.size())};
        unordered_set<int> set{};
    
        for (const int &num : nums) {
            if (num > avg && num > 0) {
                set.insert(num);
            }
        }

        int res = max(1, avg + 1);
        while (set.contains(res)) {
            res += 1;
        }

        return res;
    }
};
