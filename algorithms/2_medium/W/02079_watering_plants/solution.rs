impl Solution {
    pub fn watering_plants(plants: Vec<i32>, capacity: i32) -> i32 {
        let mut can = capacity;
        let mut count = 0_i32;
        let len = plants.len();

        for i in 0..len {
            can -= plants[i];
            count += 1;

            if i < len - 1 && can < plants[i + 1] {
                count += 2 * (i as i32 + 1);
                can = capacity;
            }
        }

        count
    }
}
