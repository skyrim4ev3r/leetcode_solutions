class Solution {
public:
    int climbStairs(int n) {

        // Edge case: Directly return 1 to reduce complexity of creating the memoization vector
        if (n == 1) {
            return 1;
        }

        size_t n_usize = static_cast<size_t>(n);
        vector<int> mem(n_usize, -1);

        mem[n_usize - 1] = 1;
        mem[n_usize - 2] = 2;

        for (auto it{mem.rbegin() + 2}; it != mem.rend(); ++it) {
            *it = *(it - 1) + *(it - 2);
        }

        return mem[0];
    }
};
