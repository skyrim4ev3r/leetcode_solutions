class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap{};
        int sum{0};

        for (const int &num: nums) {
            hashmap[num] += 1;
        }

        for (const auto [key, val]: hashmap) {
            if (val % k == 0) {
                sum += key * val;
            }
        }

        return sum;
    }
};
