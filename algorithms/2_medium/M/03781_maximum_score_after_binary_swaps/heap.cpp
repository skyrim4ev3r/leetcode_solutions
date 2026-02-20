class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        const size_t len{ nums.size() };
        priority_queue<int> heap{};
        long long sum{ 0 };

        for (size_t i{ 0 }; i < len; ++i) {
            heap.push(nums[i]);

            if (s[i] == '1') {
                sum += static_cast<long long>(heap.top());
                heap.pop();
            }
        }

        return sum;
    }
};
