class ParkingSystem:

    def __init__(self, big: int, medium: int, small: int):
        self.capacity = [big, medium, small]

    def addCar(self, car_type: int) -> bool:
        car_type_index = car_type - 1

        if self.capacity[car_type_index] > 0:
            self.capacity[car_type_index] -= 1
            return True

        return False

# Your ParkingSystem object will be instantiated and called as such:
# obj = ParkingSystem(big, medium, small)
# param_1 = obj.addCar(carType)
