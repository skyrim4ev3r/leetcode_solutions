impl Solution {
    pub fn maximum_sum(arr: Vec<i32>) -> i32 {
        assert!(arr.len() > 0);
        let mut keep = arr[0];
        let mut del = 0;
        let mut res = arr[0];

        for a in arr.into_iter().skip(1) {
            let new_keep = a.max(keep + a);
            let new_del = keep.max(del +  a);
            (del, keep) = (new_del, new_keep);
            res = res.max(del).max(new_keep);
        }

        res
    }
}
