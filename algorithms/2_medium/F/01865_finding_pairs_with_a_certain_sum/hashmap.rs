use std::collections::HashMap;

struct FindSumPairs {
    nums1: Vec<i32>,
    nums2: Vec<i32>,
    freqs_nums2: HashMap<i32, i32>,
}

impl FindSumPairs {

    fn new(nums1: Vec<i32>, nums2: Vec<i32>) -> Self {
        let mut freqs_nums2: HashMap<i32, i32> = HashMap::with_capacity(nums2.len());

        for num2 in nums2.iter() {
            *freqs_nums2.entry(*num2).or_insert(0) += 1;
        }

        Self {
            nums1,
            nums2,
            freqs_nums2,
        }
    }

    fn add(&mut self, index: i32, val: i32) {
        let num2_prev_val = self.nums2[index as usize];
        let num2_new_val = num2_prev_val + val;
        self.nums2[index as usize] += val;

        if let Some(val) = self.freqs_nums2.get_mut(&num2_prev_val) {
            *val -= 1;

            if *val == 0 {
                self.freqs_nums2.remove(&num2_prev_val);
            }
        }

        *self.freqs_nums2.entry(num2_new_val).or_insert(0) += 1;
    }

    fn count(&self, tot: i32) -> i32 {
        let mut count = 0_i32;

        for num1 in self.nums1.iter() {
            let other = tot - *num1;
            if let Some(val) = self.freqs_nums2.get(&other) {
                count += *val;
            }
        }

        count
    }
}
