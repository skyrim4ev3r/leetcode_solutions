impl Solution {
    pub fn pivot_integer(n: i32) -> i32 {
        let mut prefix_sum = (n * (n + 1)) / 2;
        let mut postfix_sum = n;
        let mut pivot = n;

        while pivot > 0 && prefix_sum >= postfix_sum {
            if prefix_sum == postfix_sum {
                return pivot;
            }

            prefix_sum -= pivot;
            postfix_sum += pivot - 1;
            pivot -= 1;
        }

        -1
    }
}
