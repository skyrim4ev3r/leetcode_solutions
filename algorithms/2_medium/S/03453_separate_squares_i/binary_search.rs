impl Solution {
    const VALID_DIFF: f64 = 0.00001;

    #[inline(always)]
    fn calc_area_under_line(squares: &Vec<(i32, i32)>, y_line: f64) -> f64 {
        let mut area = 0_f64;

        for s in squares.iter() {
            let (y, h) = (s.0 as f64, s.1 as f64);

            if y < y_line {
                let upper_y = (y + h).min(y_line);
                area += (upper_y - y) * h;
            }
        }

        area
    }

    pub fn separate_squares(squares: Vec<Vec<i32>>) -> f64 {
        let squares = squares.into_iter().map(|x| (x[1], x[2])).collect::<Vec<(i32, i32)>>();
        let mut low = 0_f64;
        let mut high = squares.iter().map(|x| x.0 + x.1).max().unwrap() as f64;
        let total_area = squares.iter().map(|x| (x.1 as f64).powf(2_f64)).sum::<f64>();

        while high - low > Self::VALID_DIFF {
            let mid = low + (high - low) / 2_f64;
            let area_under_line = Self::calc_area_under_line(&squares, mid);

            if area_under_line < total_area / 2_f64 {
                low = mid;
            } else {
                high = mid;
            }
        }

        low
    }
}
