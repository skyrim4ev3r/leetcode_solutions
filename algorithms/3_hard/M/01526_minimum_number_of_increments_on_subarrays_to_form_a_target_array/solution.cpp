class Solution {
public:
    int minNumberOperations(vector<int>& target) {

        const size_t len{target.size()};
        int total{target[0]};

        for (size_t i{1}; i < len; ++i) {
            total += max(0, target[i] - target[i - 1]);
        }

        return total;
    }
};
