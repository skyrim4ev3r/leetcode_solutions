class Solution {
public:
    int differenceOfSums(int n, int m) {
        const int total_sum {(n * (n + 1)) / 2};
        const int div_by_m_count {n / m};
        const int div_by_m_sum {m * ((div_by_m_count * (div_by_m_count + 1)) / 2)};
        const int not_div_by_m_sum {total_sum - div_by_m_sum};

        return not_div_by_m_sum - div_by_m_sum;
    }
};
