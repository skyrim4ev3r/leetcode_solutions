impl Solution {
    pub fn valid_mountain_array(arr: Vec<i32>) -> bool {
        let len = arr.len();

        if len < 3 || arr[1] <= arr[0] || arr[len - 1] >= arr[len - 2] {
            return false;
        }

        let mut index = 1_usize;

        while index < len && arr[index] > arr[index - 1] {
            index += 1;
        }

        if index == 1 || index == len || arr[index] == arr[index - 1] {
            return false;
        }

        while index < len && arr[index] < arr[index - 1] {
            index += 1;
        }

        index == len
    }
}
