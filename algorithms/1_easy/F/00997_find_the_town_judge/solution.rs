impl Solution {
    pub fn find_judge(n: i32, trust: Vec<Vec<i32>>) -> i32 {
        let len = n as usize + 1;
        let mut count = vec![0_i32; len];

        for t in trust.iter() {
            count[t[0] as usize] -= 1;
            count[t[1] as usize] += 1;
        }

        for i in 1..len {
            if count[i] == n - 1 {
                return i as i32;
            }
        }

        -1
    }
}
