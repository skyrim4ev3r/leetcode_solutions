class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int res = 0;
        for (auto num: derived) {
            res ^= num;
        }

        return res == 0;
    }
};
