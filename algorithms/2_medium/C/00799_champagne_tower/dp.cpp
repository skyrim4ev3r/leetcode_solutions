/*
    Each glass with index j has 2 parent glasses: j and j - 1.

    Each glass receives half of the amount that its parents throw.

    using 2 arrays:
        -One array tracks the fill percentage of the glasses.
        -Another array tracks how much they throw.

    Fill the first glass parent with 2 * poured, so the first glass gets half of it.
        throw_info[0] = 2.0 * poured
*/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        const size_t query_row_usize{ static_cast<size_t>(query_row) };
        vector<double> fill_info(query_row_usize + 1, 0);
        vector<double> throw_info(query_row_usize + 1, 0);
        throw_info[0] = static_cast<double>(2 * poured);

        for (size_t i{ 0 }; i < query_row + 1; ++i) {
            for (size_t j{ i }; j < i + 1; --j) {
                const double amount{ (throw_info[j] / 2.0) + (j > 0 ? throw_info[j - 1] / 2.0 : 0.0) };
                fill_info[j] =  std::min(amount, 1.0);
                throw_info[j] = std::max(amount - 1.0, 0.0);
            }
        }

        return fill_info[static_cast<size_t>(query_glass)];
    }
};
