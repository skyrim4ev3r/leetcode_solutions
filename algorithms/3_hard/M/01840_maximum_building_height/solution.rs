impl Solution {

    #[inline(always)]
    fn clac_max(p1: (i32, i32), p2:(i32, i32)) -> i32 {
        let ((mut i1, mut h1), (mut i2, mut h2)) = (p1, p2);

        if h1 < h2 {
            let diff = h2 - h1;
            h1 += diff;
            i1 += diff;
        } else {
            let diff = h1 - h2;
            h2 += diff;
            i2 -= diff;
        }

        let space_in_between = i2 - i1 - 1;

        ((space_in_between + 1) / 2) + h1
    }

    pub fn max_building(n: i32, restrictions: Vec<Vec<i32>>) -> i32 {
        assert!(n >= 2 && n as usize > restrictions.len());
        let restrictions_len = restrictions.len();
        if restrictions_len == 0 { return n - 1; }
        let mut data: Vec<(i32, i32)> = Vec::with_capacity(restrictions_len + 2);

        data.push((1, 0));
        for r in restrictions {
            data.push((r[0], r[1]));
        }

        data.sort_unstable_by_key(|x| x.0);

        if data[restrictions_len].0 != n {
            data.push((n, n - 1));
        }

        let len = data.len();

        for i in 1..len {
            let diff_i = data[i].0 - data[i - 1].0;
            data[i].1 = data[i].1.min(data[i - 1].1 + diff_i);
        }

        for i in (0..(len - 1)).rev() {
            let diff_i = data[i + 1].0 - data[i].0;
            data[i].1 = data[i].1.min(data[i + 1].1 + diff_i);
        }

        data.windows(2).map(|d| Self::clac_max(d[0], d[1])).max().unwrap()
    }
}
