impl Solution {
    pub fn minimum_boxes(apple: Vec<i32>, mut capacity: Vec<i32>) -> i32 {
        let mut total_apples = apple.iter().map(|x| *x).sum::<i32>();
        capacity.sort_unstable();
        let mut count = 0_i32;

        while total_apples > 0 {
            let curr_capacity = capacity.pop().unwrap();

            count += 1;
            total_apples -= curr_capacity;
        }

        count
    }
}
