typedef ptrdiff_t isize;

struct Entity {
    int difficulty;
    int profit;
};

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        assert(std::ssize(difficulty) == std::ssize(profit));
        const isize jobs_len = std::ssize(difficulty);
        auto jobs = vector<Entity>(jobs_len);
        for (isize i = 0; i < jobs_len; i += 1) {
            jobs[i] = { difficulty: difficulty[i], profit: profit[i]};
        }
        ranges::sort(jobs, [] (const auto& a, const auto& b) {
            return a.difficulty < b.difficulty;
        });
        ranges::sort(worker);

        int res = 0;
        int max_profit = 0;
        isize jobs_idx = 0;

        for (const auto w : worker) {
            while (jobs_idx < jobs_len && jobs[jobs_idx].difficulty <= w) {
                max_profit = std::max(max_profit, jobs[jobs_idx].profit);
                jobs_idx += 1;
            }

            res += max_profit;
        }

        return res;
    }
};
