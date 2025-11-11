impl Solution {
    pub fn min_operations(boxes: String) -> Vec<i32> {

        let boxes_bytes = boxes.into_bytes();
        let mut res: Vec<i32> = vec![0; boxes_bytes.len()];

        let mut sum = 0_i32;
        let mut balls = 0_i32;
        for i in 0..boxes_bytes.len() {
            sum += balls;
            res[i] += sum;

            if boxes_bytes[i] == b'1' {
                balls += 1;
            }
        }

        sum = 0;
        balls = 0;
        for i in (0..boxes_bytes.len()).rev() {
            sum += balls;
            res[i] += sum;

            if boxes_bytes[i] == b'1' {
                balls += 1;
            }
        }

        res
    }
}
