use std::cmp::Ordering;

impl Solution {
    pub fn find_the_distance_value(arr1: Vec<i32>, mut arr2: Vec<i32>, d: i32) -> i32 {
        arr2.sort_unstable();
        let mut count = 0_i32;
        let len2 = arr2.len();

        for num1 in arr1.iter() {
            let pos = arr2.binary_search_by(|num2| match num2.cmp(num1) {
                Ordering::Less => Ordering::Less,
                _ => Ordering::Greater
            }).unwrap_or_else(|x| x);

            let mut can_be_count = true;

            if pos + 1 < len2 && (num1 - arr2[pos + 1]).abs() <= d {
                can_be_count = false;
            }

            if pos < len2 && (num1 - arr2[pos]).abs() <= d {
                can_be_count = false;
            }

            if pos != 0 && (num1 - arr2[pos - 1]).abs() <= d {
                can_be_count = false;
            }

            if can_be_count {
                count += 1;
            }
        }

        count
    }
}
