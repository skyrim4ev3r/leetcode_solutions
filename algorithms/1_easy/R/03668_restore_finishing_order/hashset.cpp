class Solution {
public:
    static vector<int> recoverOrder(const vector<int>& order, const vector<int>& friends) {
        vector<int> res;
        res.reserve(friends.size());
        unordered_set<int> exact(friends.cbegin(), friends.cend());

        for (const auto& o : order) {
            if (exact.contains(o)) {
                res.push_back(o);
            }
        }

        return res;
    }
};
