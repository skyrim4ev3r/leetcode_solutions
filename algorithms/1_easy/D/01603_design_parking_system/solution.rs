struct ParkingSystem {
    capacity: [i32; 3],
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl ParkingSystem {
    fn new(big: i32, medium: i32, small: i32) -> Self {
        Self {
            capacity: [big, medium, small],
        }
    }

    fn add_car(&mut self, car_type: i32) -> bool {
        let car_type_index = car_type as usize - 1;

        if self.capacity[car_type_index] > 0 {
            self.capacity[car_type_index] -= 1;
            return true;
        }

        false
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * let obj = ParkingSystem::new(big, medium, small);
 * let ret_1: bool = obj.add_car(carType);
 */
