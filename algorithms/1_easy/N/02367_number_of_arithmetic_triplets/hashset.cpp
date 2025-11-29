class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> hashset{};
        int count{0};

        for (const int& num : nums) {
            if (hashset.contains(num - diff) && hashset.contains(num - (2 * diff))) {
                count += 1;
            }

            hashset.insert(num);
        }

        return count;
    }
};
