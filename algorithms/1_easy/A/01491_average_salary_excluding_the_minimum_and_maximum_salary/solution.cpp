class Solution {
public:
    double average(vector<int>& salary) {
        int min_salary {numeric_limits<int>::max()};
        int max_salary {numeric_limits<int>::min()};
        int sum {0};

        for (const int val : salary) {
            sum += val;
            min_salary = std::min(min_salary, val);
            max_salary = std::max(max_salary, val);
        }

        const int sum_exclude_min_max {sum - min_salary - max_salary};
        const int count_exclude_min_max {static_cast<int>(salary.size() - 2)};

        return static_cast<double>(sum_exclude_min_max) / static_cast<double>(count_exclude_min_max);
    }
};
