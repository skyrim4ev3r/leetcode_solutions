class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;

        for (const int &num: nums) {
            if (!hashset.insert(num).second) {
                return true;
            }
        }

        return false;
    }
};
