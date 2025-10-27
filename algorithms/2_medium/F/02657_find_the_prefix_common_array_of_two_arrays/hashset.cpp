class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {

        unordered_set<int> nums_set{};
        size_t n{a.size()};
        vector<int> res{};
        res.reserve(n);
        int common{0};

        for (size_t i{0}; i < n; ++i) {
            if (nums_set.insert(a[i]).second == false) {
                common += 1;
            }

            if (nums_set.insert(b[i]).second == false) {
                common += 1;
            }

            res.push_back(common);
        }

        return res;
    }
};

