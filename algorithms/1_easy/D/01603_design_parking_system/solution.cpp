class ParkingSystem {
    array<int, 3> capacity;
public:
    ParkingSystem(int big, int medium, int small): capacity{big, medium, small} {}

    bool addCar(int car_type) {
        const size_t car_type_index{static_cast<size_t>(car_type) - 1};

        if (capacity[car_type_index] > 0) {
            capacity[car_type_index] -= 1;
            return true;
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
