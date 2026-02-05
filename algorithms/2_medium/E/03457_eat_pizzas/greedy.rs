impl Solution {
    pub fn max_weight(mut pizzas: Vec<i32>) -> i64 {
        pizzas.sort_unstable();

        let len = pizzas.len();
        let total_days = len / 4;
        let odd_days = (total_days / 2) + (total_days & 1);
        let even_days = (total_days / 2);
        let mut curr_index = len - 1;
        let mut sum = 0_i64;

        for _ in 0..odd_days {
            sum += pizzas[curr_index] as i64;
            curr_index -= 1;
        }

        for _ in 0..even_days {
            curr_index -= 1;
            sum += pizzas[curr_index] as i64;
            curr_index -= 1;
        }

        sum
    }
}
