impl Solution {
    pub fn can_arrange(arr: Vec<i32>, k: i32) -> bool {
        if k == 1 {
            return true;
        }

        let k_usize = k as usize;
        let mut reminders_freqs = vec![0_i32; k_usize];

        for a in arr.into_iter() {
            let rem = a % k;
            let index = if rem < 0 {rem + k} else {rem};
            reminders_freqs[index as usize] += 1;
        }

        // if first freq be even
        // then for even values of k
        // freq[(k / 2)] have to be even too
        // so both edge cases are checked!
        if (reminders_freqs[0] & 1) == 1 {
            return false;
        }

        let half = k_usize / 2;
        for i in 1..=half {
            let other = k_usize - i;

            if reminders_freqs[i] != reminders_freqs[other] {
                return false;
            }
        }

        true
    }
}
