impl Solution {
    pub fn maximum_sum(arr: Vec<i32>) -> i32 {
        let len = arr.len();
        assert!(len > 0);

        if arr.iter().all(|&x| x < 0) { 
            return arr.into_iter().max().unwrap();
        }

        let mut suffix = Vec::with_capacity(len + 1);
        unsafe { suffix.set_len(len + 1) };
        suffix[len] = 0;

        for i in (0..len).rev() {
            suffix[i] = (suffix[i + 1] + arr[i]).max(0);
        }

        let mut prefix = 0_i32;
        let mut res = i32::MIN;

        for i in 0..len {
            res = res.max(prefix + arr[i].max(0) + suffix[i + 1]);
            prefix = (prefix + arr[i]).max(0);
        }

        res
    }
}
