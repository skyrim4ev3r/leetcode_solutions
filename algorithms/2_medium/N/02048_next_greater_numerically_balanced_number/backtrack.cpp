class Solution {
    void backtrack_selector(int n, int n_digits_count,int curr_degits_count, int curr_index, int &res, vector<pair<int, int>> &curr_selected_digits) {
        for (int i{curr_index}; i <= 6; ++i) {
            if (i + curr_degits_count < n_digits_count) {
                curr_selected_digits.push_back(make_pair(i, i));
                backtrack_selector(n, n_digits_count, curr_degits_count + i, i + 1, res, curr_selected_digits);
                curr_selected_digits.pop_back();
            } else if (i + curr_degits_count == n_digits_count) {
                curr_selected_digits.push_back(make_pair(i, i));

                int temp_res{0};
                backtrack(n, temp_res, 0, curr_selected_digits);

                if (temp_res > 0) {
                    if (res == 0 || temp_res < res) {
                        res = temp_res;
                    }
                }

                curr_selected_digits.pop_back();
            }
        }
    }

    void backtrack(int n, int &temp_res, int curr_num, vector<pair<int, int>> &curr_selected_digits) {
        if (temp_res > 0) {
            return;
        }

        if (curr_num > n) {
            temp_res = curr_num;
            return;
        }

        size_t len = curr_selected_digits.size();
        for (size_t i{0}; i < len; ++i) {
            if (temp_res > 0) {
                return;
            }

            if (curr_selected_digits[i].second > 0) {
                curr_selected_digits[i].second -= 1;
                curr_num *= 10;
                curr_num += curr_selected_digits[i].first;
                backtrack(n, temp_res, curr_num, curr_selected_digits);
                curr_num /= 10;
                curr_selected_digits[i].second += 1;
            }
        }
    }

public:
    int nextBeautifulNumber(int n) {

        int n_digits_count{0};

        int temp{n};
        while (temp > 0) {
            temp /= 10;
            n_digits_count += 1;
        }

        int res{0};
        vector<pair<int, int>> curr_selected_digits{};
        backtrack_selector(n, n_digits_count, 0, 1, res, curr_selected_digits);

        if (res > 0) {
            return res;
        }

        // if n is bigger or equal to all permution of balanced number with same size of digits then
        // return smallest balanced digits with 1 extra digit
        // this can get calculated by backtracking aswell.
        // but its easier to use result table for this edge-cases
        const int smallest_values_for_each_digits_range[7]{1, 22, 122, 1333, 22333, 122333, 1224444};
        return smallest_values_for_each_digits_range[static_cast<size_t>(n_digits_count)];
    }
};
