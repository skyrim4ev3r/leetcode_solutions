impl Solution {
    fn helper(
        a_start_time: &Vec<i32>,
        a_duration: &Vec<i32>,
        b_start_time: &Vec<i32>,
        b_duration: &Vec<i32>,
    ) -> i32 {
        let a_len = a_start_time.len();
        let b_len = b_start_time.len();
        let min_a_end = (0..a_len).into_iter()
                                  .map(|i| a_start_time[i] + a_duration[i])
                                  .min()
                                  .unwrap();
        let mut res = i32::MAX;

        for j in 0..b_len {
            let start_b = std::cmp::max(min_a_end, b_start_time[j]);
            let end_b = start_b + b_duration[j];

            res = res.min(end_b);
        }

        res
    }

    pub fn earliest_finish_time(
        land_start_time: Vec<i32>,
        land_duration: Vec<i32>,
        water_start_time: Vec<i32>,
        water_duration: Vec<i32>,
    ) -> i32 {
        let land_first = Self::helper(&land_start_time, &land_duration, &water_start_time, &water_duration);
        let water_first = Self::helper(&water_start_time, &water_duration, &land_start_time, &land_duration);

        std::cmp::min(land_first, water_first)
    }
}
