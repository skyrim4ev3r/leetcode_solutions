impl Solution {
    pub fn count_students(students: Vec<i32>, sandwiches: Vec<i32>) -> i32 {
        let mut zeros = students.iter().filter(|x| **x == 0).count() as i32;
        let mut ones = students.len() as i32 - zeros;

        for sandwich in sandwiches.iter() {
            if *sandwich == 1 {
                if (ones > 0) {
                    ones -= 1;
                } else {
                    break;
                }
            } else if *sandwich == 0 {
                if (zeros > 0) {
                    zeros -= 1;
                } else {
                    break;
                }
            }
        }

        ones + zeros
    }
}
