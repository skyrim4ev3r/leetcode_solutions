class Solution {
public:
    static long long countSubarrays(const vector<int>& nums, long long k) {
        const size_t len{ nums.size() };
        deque<int> q_max;
        deque<int> q_min;
        size_t count{ 0 };
        size_t left{ 0 };

        for (size_t right{ 0 }; right < len; ++right) {
            const int curr{ nums[right] };

            while (!q_max.empty() && q_max.back() < curr) {
                q_max.pop_back();
            }

            while (!q_min.empty() && q_min.back() > curr) {
                q_min.pop_back();
            }

            q_max.push_back(curr);
            q_min.push_back(curr);

            long long width{ static_cast<long long>(right - left + 1) };
            long long cost{ width * static_cast<long long>(q_max.front() - q_min.front()) };

            while (cost > k) {
                if (nums[left] == q_max.front()) {
                    q_max.pop_front();
                }

                if (nums[left] == q_min.front()) {
                    q_min.pop_front();
                }

                left += 1;
                width =  static_cast<long long>(right - left + 1);
                cost = width * static_cast<long long>(q_max.front() - q_min.front());
            }

            count += width;
        }

        return count;
    }
};
