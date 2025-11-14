class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int prev_reminder{1 % k};
        unordered_set<int> seen{};
        int curr_len{1};

        while (prev_reminder != 0) {
            if (!seen.insert(prev_reminder).second) {
                return -1;
            }

            prev_reminder = (prev_reminder * 10 + 1) % k;
            curr_len += 1;
        }

        return curr_len;
    }
};
