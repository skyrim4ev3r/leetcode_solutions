impl Solution {
    pub fn asteroid_collision(asteroids: Vec<i32>) -> Vec<i32> {

        let mut stack: Vec<i32> = Vec::new();

        for asteroid in asteroids.into_iter() {
            if asteroid > 0 {
                stack.push(asteroid);
            } else {
                while let Some(val) = stack.last() && *val > 0 && *val < asteroid.abs() {
                    stack.pop();
                }

                if let Some(val) = stack.last() && *val > 0 {
                    if (*val).abs() == asteroid.abs() {
                        stack.pop();
                    }

                    continue;
                }

                stack.push(asteroid);
            }
        }

        stack
    }
}
