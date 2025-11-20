class Solution {
public:
    int minChanges(int n, int k) {
        return (n | k) != n ? -1 : __builtin_popcount(n ^ k);
    }
};
