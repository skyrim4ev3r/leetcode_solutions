class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        size_t left{0};
        int sum{0};
        const size_t len{colors.size()};

        for (size_t right{1}; right < len; ++right) {
            if (colors[left] == colors[right]) {
                if (neededTime[left] < neededTime[right]) {
                    sum += neededTime[left];
                    left = right;
                } else {
                    sum += neededTime[right];
                }
            } else {
                left = right;
            }
        }

        return sum;
    }
};
