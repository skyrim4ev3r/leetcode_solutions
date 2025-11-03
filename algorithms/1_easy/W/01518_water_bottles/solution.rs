impl Solution {
    pub fn num_water_bottles(mut num_bottles: i32, num_exchange: i32) -> i32 {
        let mut count = num_bottles;
        while num_bottles >= num_exchange {
            count += num_bottles / num_exchange;
            num_bottles = num_bottles / num_exchange + num_bottles % num_exchange;
        }

        count
    }
}
