impl Solution {
    pub fn min_processing_time(mut processor_time: Vec<i32>, mut tasks: Vec<i32>) -> i32 {
        let tasks_len = tasks.len();
        let mut res = 0_i32;

        processor_time.sort_unstable_by(|a, b| b.cmp(&a));
        tasks.sort_unstable();

        for i in (0..tasks_len).step_by(4) {
            let max_elem = *tasks[i..(i + 4)].iter().max().unwrap();
            res = res.max(max_elem + processor_time[i / 4]);
        }

        res
    }
}
