impl Solution {
    pub fn total_fruit(fruits: Vec<i32>) -> i32 {
        let mut left = 0_usize;
        let mut fruit_a = -1_i32;
        let mut fruit_a_count = 0_i32;
        let mut fruit_b = -1_i32;
        let mut fruit_b_count = 0_i32;
        let mut max = 0_i32;

        for right in 0..fruits.len() {
            if fruit_a == fruits[right] {
                fruit_a_count += 1;
            } else if fruit_b == fruits[right] {
                fruit_b_count += 1;
            } else {
                while fruit_b_count > 0 && fruit_a_count > 0 {
                    if fruits[left] == fruit_a {
                        fruit_a_count -= 1;
                    } else {
                        fruit_b_count -= 1;
                    }

                    left += 1;
                }

                if fruit_a_count == 0 {
                    fruit_a_count = 1;
                    fruit_a = fruits[right];
                } else {
                    fruit_b_count = 1;
                    fruit_b = fruits[right];
                }
            }

            max = max.max(fruit_a_count + fruit_b_count);
        }

        max
    }
}
