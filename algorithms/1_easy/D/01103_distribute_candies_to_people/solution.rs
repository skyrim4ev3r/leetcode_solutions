impl Solution {
    pub fn distribute_candies(mut candies: i32, num_people: i32) -> Vec<i32> {

        if num_people == 1 {
            return vec![candies];
        }

        let len = num_people as usize;
        let mut res = vec![0_i32; len];
        let mut curr_count = 1_i32;
        let mut curr_index = 0_usize;

        while candies > 0 {
            res[curr_index] += curr_count.min(candies);
            candies -= curr_count;
            curr_count += 1;
            curr_index += 1;

            if curr_index == len {
                curr_index = 0;
            }
        }

        res
    }
}
