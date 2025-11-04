struct ExamTracker {
    time_score: Vec<(i32, i64)>
}

impl ExamTracker {

    fn new() -> Self {
        ExamTracker {
            time_score: vec![(0, 0)]
        }
    }

    fn record(&mut self, time: i32, score: i32) {
        let sum = score as i64 + self.time_score.last().unwrap().1;
        self.time_score.push((time, sum));
    }

    fn total_score(&self, start_time: i32, end_time: i32) -> i64 {
        let left = self.time_score.binary_search_by(|t| t.0.cmp(&start_time)).unwrap_or_else(|x| x);

        let right = self.time_score.binary_search_by(|t| match t.0.cmp(&end_time) {
            std::cmp::Ordering::Less | std::cmp::Ordering::Equal => std::cmp::Ordering::Less,
            std::cmp::Ordering::Greater => std::cmp::Ordering::Greater,
        }).unwrap_or_else(|x| x) ;

        self.time_score[right - 1].1 - self.time_score[left - 1].1
    }
}
