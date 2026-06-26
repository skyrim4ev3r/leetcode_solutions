impl Solution {
    pub fn interval_intersection(l1: Vec<Vec<i32>>, l2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();
        let (len1, len2) = (l1.len(), l2.len());
        let (mut idx1, mut idx2) = (0_usize, 0_usize);

        while idx1 < len1 && idx2 < len2 {
            let (lo, hi) = (l1[idx1][0].max(l2[idx2][0]), l1[idx1][1].min(l2[idx2][1]));

            if lo <= hi  {
                res.push(vec![lo, hi]);
            }

            if l1[idx1][1] == hi {
                idx1 += 1;
            }

            if l2[idx2][1] == hi {
                idx2 += 1;
            }
        }

        res
    }
}
