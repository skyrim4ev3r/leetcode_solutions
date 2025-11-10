impl Solution {
    fn backtrack_selector(n: i32, n_digits_count: i32, curr_degits_count: i32, curr_index: i32, res: &mut i32, curr_selected_digits: &mut Vec<(i32, i32)>) {
        for i in curr_index..=6 {
            if i + curr_degits_count < n_digits_count {
                curr_selected_digits.push((i, i));
                Self::backtrack_selector(n, n_digits_count, curr_degits_count + i, i + 1, res, curr_selected_digits);
                curr_selected_digits.pop();
            } else if i + curr_degits_count == n_digits_count {
                curr_selected_digits.push((i, i));

                let mut temp_res = 0_i32;
                Self::backtrack(n, &mut temp_res, 0, curr_selected_digits);
                if temp_res > 0 {
                    if *res == 0 || temp_res < *res {
                        *res = temp_res;
                    }
                }

                curr_selected_digits.pop();
            }
        }
    }

    fn backtrack(n: i32, temp_res: &mut i32, mut curr_num: i32, curr_selected_digits: &mut Vec<(i32, i32)>) {
        if *temp_res > 0 {
            return;
        }

        if curr_num > n {
            *temp_res = curr_num;
            return;
        }

        for i in 0..curr_selected_digits.len() {
            if *temp_res > 0 {
                return;
            }

            if curr_selected_digits[i].1 > 0 {
                curr_selected_digits[i].1 -= 1;
                curr_num *= 10;
                curr_num += curr_selected_digits[i].0;
                Self::backtrack(n, temp_res, curr_num, curr_selected_digits);
                curr_num /= 10;
                curr_selected_digits[i].1 += 1;
            }
        }
    }

    pub fn next_beautiful_number(n: i32) -> i32 {
        
        let mut n_digits_count = 0;

        let mut temp = n;
        while temp > 0 {
            temp /= 10;
            n_digits_count += 1;
        }

        let mut res = 0_i32;
        let mut curr_selected_digits: Vec<(i32, i32)> = Vec::new();
        Self::backtrack_selector(n, n_digits_count, 0, 1, &mut res, &mut curr_selected_digits);

        if res > 0 {
            return res;
        }

        // if n is bigger or equal to all permution of balanced number with same size of digits then
        // return smallest balanced digits with 1 extra digit
        // this can get calculated by backtracking aswell.
        // but its easier to use result table for this edge-cases
        let smallest_values_for_each_digits_range = [1, 22, 122, 1333, 22333, 122333, 1224444];
        smallest_values_for_each_digits_range[n_digits_count as usize]
    }
}
