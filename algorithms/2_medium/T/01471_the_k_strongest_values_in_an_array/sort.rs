impl Solution {
    pub fn get_strongest(mut arr: Vec<i32>, k: i32) -> Vec<i32> {
        assert!(k >= 1 && k as usize <= arr.len());
        if (k as usize == arr.len()) { return arr; }
        arr.sort_unstable();
        let mid = (arr.len() - 1) / 2;
        let m = arr[mid];
        let mut res: Vec<i32> = Vec::with_capacity(k as usize);

        let mut lo = 0_usize;
        let mut hi = arr.len() - 1;

        for _ in 0..k {
            if (arr[lo] - m).abs() > (arr[hi] - m).abs() {
                res.push(arr[lo]);
                lo += 1;
            } else {
                res.push(arr[hi]);
                hi -= 1;
            }
        }

        res
    }
}
