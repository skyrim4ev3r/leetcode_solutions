impl Solution {
    pub fn average(salary: Vec<i32>) -> f64 {
        let mut min_salary = i32::MAX;
        let mut max_salary = i32::MIN;
        let mut sum = 0_i32;

        for &val in salary.iter() {
            sum += val;
            min_salary = min_salary.min(val);
            max_salary = max_salary.max(val);
        }

        let sum_exclude_min_max = sum - min_salary - max_salary;
        let count_exclude_min_max = (salary.len() - 2) as i32;

        (sum_exclude_min_max) as f64 / (count_exclude_min_max) as f64
    }
}
