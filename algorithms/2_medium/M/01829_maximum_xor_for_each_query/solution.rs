impl Solution {
    pub fn get_maximum_xor(nums: Vec<i32>, maximum_bit: i32) -> Vec<i32> {
        assert!(maximum_bit <= 20 && maximum_bit >= 0);
        let mask = (1 << maximum_bit) - 1;
        let mut xor = 0;
        let mut res = nums;
        let len = res.len();

        for x in res.iter_mut() {
            xor ^= *x;
            *x = mask ^ xor;
        }

        res.reverse();
        res
    }
}
