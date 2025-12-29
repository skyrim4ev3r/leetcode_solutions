class Solution {
public:
    static inline long long minimumCost(long long c1, long long c2, long long cb, long long n1, long long n2) {
        return min(c1 * n1 + c2 * n2, min(n1, n2) * cb + min(abs(n2 - n1) * cb, n2 > n1 ? c2 * (n2 - n1) : c1 * (n1 - n2)));
    }
};
