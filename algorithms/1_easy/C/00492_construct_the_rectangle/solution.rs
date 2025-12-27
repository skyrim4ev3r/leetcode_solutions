impl Solution {
    pub fn construct_rectangle(area: i32) -> Vec<i32> {
        for i in (1..=area.isqrt()).rev() {
            if (area % i == 0) {
                return vec![area / i, i];
            }
        }

        unreachable!()
    }
}
