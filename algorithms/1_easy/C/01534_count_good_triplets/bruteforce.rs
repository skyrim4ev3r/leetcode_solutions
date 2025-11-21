impl Solution {
    pub fn count_good_triplets(arr: Vec<i32>, a: i32, b: i32, c: i32) -> i32 {
        let len = arr.len();
        let mut count = 0_i32;

        for i in 0..len {
            for j in (i + 1)..len {
                for k in (j + 1)..len {
                    if (
                        (arr[i] - arr[j]).abs() <= a &&
                        (arr[j] - arr[k]).abs() <= b &&
                        (arr[i] - arr[k]).abs() <= c
                    ) {
                        count += 1;
                    }
                }
            }
        }

        count
    }
}
