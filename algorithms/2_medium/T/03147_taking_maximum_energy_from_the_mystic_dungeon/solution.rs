// Time Complexity: O(N) - Ignore the nested loops; the overall complexity is linear
// Follow i and j's changing behavior for clarification.
impl Solution {
    pub fn maximum_energy(energy: Vec<i32>, k: i32) -> i32 {
        let mut max_energy_absorb = i32::MIN;
        let len = energy.len();
        let k_usize = k as usize;

        for i in 0..k_usize {
            let mut sum = 0_i32;

            for j in (i..len).step_by(k_usize) {
                if sum < 0 {
                    sum = 0;
                }

                sum += energy[j];
            }

            max_energy_absorb = max_energy_absorb.max(sum);
        }

        max_energy_absorb
    }
}
