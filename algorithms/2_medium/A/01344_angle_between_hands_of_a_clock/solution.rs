impl Solution {
    pub fn angle_clock(hour: i32, minutes: i32) -> f64 {
        let m_degree = (minutes * 6) as f64;
        let h_degree = (hour * 30) as f64 + (m_degree / 12.0);
        let diff = (h_degree - m_degree).abs();

        diff.min(360.0 - diff)
    }
}
