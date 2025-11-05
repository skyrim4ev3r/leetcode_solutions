impl Solution {
    pub fn valid_mountain_array(arr: Vec<i32>) -> bool {
        let mut is_increasing = true;
        let arr_len = arr.len();

        if arr_len < 3 || arr[1] <= arr[0] || arr[arr_len - 1] >= arr[arr_len - 2] {
            return false;
        }

        for i in 1..arr_len {
            if is_increasing {
                if arr[i] == arr[i - 1] {
                    return false;
                }

                if arr[i] < arr[i - 1] {
                    is_increasing = false;
                }
            } else {
                if arr[i] >= arr[i - 1] {
                    return false;
                }
            }
        }

        true
    }
}
