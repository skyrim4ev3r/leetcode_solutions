class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        return static_cast<int>(std::min(candyType.size() / 2, unordered_set<int>(candyType.begin(), candyType.end()).size()));
    }
};
