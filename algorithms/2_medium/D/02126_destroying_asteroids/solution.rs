impl Solution {
    pub fn asteroids_destroyed(mass: i32, mut asteroids: Vec<i32>) -> bool {
        asteroids.sort_unstable();
        let mut curr_mass = mass as i64;

        for a in asteroids.into_iter() {
            if a as i64 > curr_mass {
                return false;
            }

            curr_mass += a as i64;
        }

        true
    }
}
