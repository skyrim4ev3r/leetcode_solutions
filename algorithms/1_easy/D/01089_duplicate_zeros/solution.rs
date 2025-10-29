impl Solution {
    pub fn duplicate_zeros(arr: &mut Vec<i32>) {

        let len = arr.len();
        let mut count_zeros = 0;

        for &num in arr.iter() {
            if num == 0 {
                count_zeros += 1;
            }
        }

        let mut new_index = len - 1 + count_zeros;
        for i in (0..len).rev() {
            if new_index < len {
                arr[new_index] = arr[i];
            }

            if arr[i] == 0 {
                new_index -= 1;
                if new_index < len {
                    arr[new_index] = 0; 
                }
            }

            new_index -= 1;
        }
    }
}
