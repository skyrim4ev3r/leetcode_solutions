class Solution {
    class compare {
    public:
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            if (a.first == b.first) {
                return a.second > b.second;
            }

            return a.first > b.first;
        }    
    };
public:
    long long findScore(vector<int>& nums) {
        const size_t len {nums.size()};
        long long res {0};
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> heap;

        for (size_t i {0}; i < len; ++i) {
            heap.push({nums[i], static_cast<int>(i)});
        }

        while (!heap.empty()) {
            const auto index {static_cast<size_t>(heap.top().second)};
            heap.pop();

            if (nums[index] < 0) {
                continue;
            }

            res += static_cast<long long>(nums[index]);
            nums[index] = -1;

            if (index > 0) {
                nums[index - 1] = -1;
            }

            if (index + 1 < len) {
                nums[index + 1] = -1;
            }
        }

        return res;
    }
};
