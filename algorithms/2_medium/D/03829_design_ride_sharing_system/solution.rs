use std::collections::{VecDeque, HashSet};

struct RideSharingSystem {
    riders: VecDeque<i32>,
    drivers: VecDeque<i32>,
    is_rider_valid: HashSet<i32>,
}

impl RideSharingSystem {

    fn new() -> Self {
        Self {
            riders: VecDeque::new(),
            drivers: VecDeque::new(),
            is_rider_valid: HashSet::new(),
        }
    }

    fn add_rider(&mut self, rider_id: i32) {
        self.riders.push_back(rider_id);
        self.is_rider_valid.insert(rider_id);
    }

    fn add_driver(&mut self, driver_id: i32) {
        self.drivers.push_back(driver_id);
    }

    fn match_driver_with_rider(&mut self) -> Vec<i32> {
        while let Some(rider_id) = self.riders.front() && !self.is_rider_valid.contains(rider_id) {
            self.riders.pop_front();
        }

        if self.riders.is_empty() || self.drivers.is_empty() {
            return vec![-1, -1];
        }

        let rider_id = self.riders.pop_front().unwrap();
        let driver_id = self.drivers.pop_front().unwrap();
        self.is_rider_valid.remove(&rider_id);

        vec![driver_id, rider_id]
    }

    fn cancel_rider(&mut self, rider_id: i32) {
        if self.is_rider_valid.contains(&rider_id) {
            self.is_rider_valid.remove(&rider_id);
        }
    }
}
