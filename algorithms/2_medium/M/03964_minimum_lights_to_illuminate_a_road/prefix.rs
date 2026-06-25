impl Solution {
    pub fn min_lights(lights: Vec<i32>) -> i32 {
        let n = lights.len() as isize;
        let mut prefix = vec![0_i32; (n + 3) as usize];

        for (i, light) in lights.into_iter().enumerate() {
            if light > 0 {
                let lo = (i as isize - light as isize).max(0);
                let hi = (i as isize + light as isize + 1).min(n);
                prefix[lo as usize] += 1;
                prefix[hi as usize] -= 1;
            }
        }

        let mut sum = 0_i32;
        let mut cnt_need = 0_i32;
        for i in 0..n {
            sum += prefix[i as usize];
            if sum == 0 {
                sum += 1;
                cnt_need += 1;
                prefix[i as usize + 3] -= 1;
            }
        }

        cnt_need
    }
}
