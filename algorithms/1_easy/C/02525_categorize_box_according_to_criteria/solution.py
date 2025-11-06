class Solution:
    def categorizeBox(self, length: int, width: int, height: int, mass: int) -> str:
        min_bulky_len = 10000
        min_bulky_volume = 1000000000
        min_heavy_mass = 100

        is_bulky = False
        is_heavy = False

        volume = length * width * height

        if length >= min_bulky_len or width >= min_bulky_len \
            or height >= min_bulky_len or volume >= min_bulky_volume:

            is_bulky = True

        if mass >= min_heavy_mass:
            is_heavy = True

        if is_bulky and is_heavy:
            return "Both"
        elif is_bulky:
            return "Bulky"
        elif is_heavy:
            return "Heavy"
        else:
            return "Neither"
