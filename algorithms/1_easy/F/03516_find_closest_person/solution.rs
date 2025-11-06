impl Solution {
    pub fn find_closest(x: i32, y: i32, z: i32) -> i32 { 
        ((z-x).abs() < (y-z).abs()) as i32 + 2 *(((z-x).abs() > (y-z).abs()) as i32)
    }
}
