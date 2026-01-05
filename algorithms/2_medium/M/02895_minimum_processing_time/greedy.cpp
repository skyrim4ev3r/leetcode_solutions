class Solution {
public:
    static int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        const size_t tasks_len {tasks.size()};
        int res {0};

        std::ranges::sort(processorTime, [](const int& a, const int& b) {
            return a > b;
        });
        std::ranges::sort(tasks);

        for (size_t i {0}; i < tasks_len; i += 4) {
            const int max_elem {*std::max_element(tasks.cbegin() + i, tasks.cbegin() + i + 4)};
            res = std::max(res, max_elem + processorTime[i / 4]);
        }

        return res;
    }
};
