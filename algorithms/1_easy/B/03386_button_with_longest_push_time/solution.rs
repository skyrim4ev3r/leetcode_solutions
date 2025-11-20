impl Solution {
    pub fn button_with_longest_time(events: Vec<Vec<i32>>) -> i32 {
        let mut max_duration = events[0][1];
        let mut pressed_btn = events[0][0];

        for w in events.windows(2) {
            let curr_duration = w[1][1] - w[0][1];
            let curr_btn = w[1][0];

            if curr_duration > max_duration {
                max_duration = curr_duration;
                pressed_btn = curr_btn;
            } else if curr_duration == max_duration {
                pressed_btn = pressed_btn.min(curr_btn);
            }
        }

        pressed_btn
    }
}
