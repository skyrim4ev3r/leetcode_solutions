impl Solution {
    pub fn count_bits(n: i32) -> Vec<i32> {
        (0..=n).into_iter().fold(Vec::<i32>::new(), |mut res, i| {
            res.push(i.count_ones() as i32);
            res
        })
    }
}
