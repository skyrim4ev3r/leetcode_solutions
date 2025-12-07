class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> hashset{};

        for (const int &num : nums) {
            if (num % k == 0) {
                hashset.insert(num);
            }
        }

        int curr{k};

        while (hashset.find(curr) != hashset.end()) {
            curr += k;
        }

        return curr;
    }
};
