impl Solution {
    pub fn difference_of_sums(n: i32, m: i32) -> i32 {
        let total_sum = (n * (n + 1)) / 2;
        let div_by_m_count = n / m;
        let div_by_m_sum = m * ((div_by_m_count * (div_by_m_count + 1)) / 2);
        let not_div_by_m_sum = total_sum - div_by_m_sum;

        not_div_by_m_sum - div_by_m_sum
    }
}
