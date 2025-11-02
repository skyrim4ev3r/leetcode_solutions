impl Solution {
    pub fn can_place_flowers(flowerbed: Vec<i32>, mut n: i32) -> bool {
        if n == 0 {
            return true;
        }

        let len = flowerbed.len();
        let mut curr_index = 0_usize;

        while curr_index < len {

            if flowerbed[curr_index] == 1 
                || (curr_index > 0 && flowerbed[curr_index - 1] == 1)
                || (curr_index < (len - 1) && flowerbed[curr_index + 1] == 1)
            {
                curr_index += 1;
            } else {
                n -= 1;

                if n == 0 {
                    return true;
                }

                curr_index += 2;
            }
        }

        false
    }
}
