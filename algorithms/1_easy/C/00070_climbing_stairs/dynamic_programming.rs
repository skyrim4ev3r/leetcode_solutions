impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {

        // Edge case: Directly return 1 to reduce complexity of creating the memoization vector
        if n == 1 {
            return 1;
        }

        let n_usize = n as usize;
        let mut mem = vec![0_i32; n_usize];

        mem[n_usize - 1] = 1;
        mem[n_usize - 2] = 2;

        for i in (0..(n_usize - 2)).rev() {
            mem[i] = mem[i + 1] + mem[i + 2];
        }

        mem[0]
    }
}
