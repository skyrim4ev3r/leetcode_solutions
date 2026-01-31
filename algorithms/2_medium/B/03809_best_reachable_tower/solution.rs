impl Solution {
    pub fn best_tower(towers: Vec<Vec<i32>>, center: Vec<i32>, radius: i32) -> Vec<i32> {
        let mut selected_x = -1_i32;
        let mut selected_y = -1_i32;
        let mut selected_quality = -1_i32;

        for t in towers.into_iter() {
            let dist = (t[0] - center[0]).abs() + (t[1] - center[1]).abs();

            if dist > radius {
                continue;
            }

            if selected_quality < t[2] {
                selected_quality = t[2];
                selected_x = t[0];
                selected_y = t[1];
            } else if selected_quality == t[2] {
                if t[0] < selected_x || (t[0] == selected_x && t[1] < selected_y) {
                    selected_x = t[0];
                    selected_y = t[1];
                }
            }
        }

        vec![selected_x, selected_y]
    }
}
