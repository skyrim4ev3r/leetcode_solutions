impl Solution {
    pub fn cells_in_range(s: String) -> Vec<String> {
        let bytes = s.as_bytes();
        let mut curr = bytes[0..2].to_vec();
        let target = bytes[3..5].to_vec();
        let mut res: Vec<String> = vec![String::from_utf8(curr.clone()).unwrap()];
        let start_row = bytes[1];
        let end_row = bytes[4];

        while curr != target {
            curr[1] += 1;

            if curr[1] > end_row {
                curr[1] = start_row;
                curr[0] += 1;
            }

            res.push(String::from_utf8(curr.clone()).unwrap());
        }

        res
    }
}
