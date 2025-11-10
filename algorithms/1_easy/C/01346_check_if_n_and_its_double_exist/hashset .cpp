class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> set;

        for (const int &num: arr) {
            if (set.contains(num * 2) || ((num & 1) != 1 && set.contains(num / 2))) {
                return true;
            }

            set.insert(num);
        }

        return false;
    }
};
