impl Solution {
    pub fn busy_student(start_time: Vec<i32>, end_time: Vec<i32>, query_time: i32) -> i32 {
        let len = start_time.len();
        let mut count = 0_i32;

        for i in 0..len {
            if start_time[i] <= query_time && query_time <= end_time[i] {
                count += 1;
            }
        }

        count
    }
}
