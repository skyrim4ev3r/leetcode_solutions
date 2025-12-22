class Solution:
    def numOfBurgers(self, tomato_slices: int, cheese_slices: int) -> List[int]:
        if (
            (tomato_slices & 1) == 1 or
            tomato_slices > cheese_slices * 4 or
            tomato_slices < cheese_slices * 2
        ):
            return []

        small = cheese_slices
        remain_tomato = tomato_slices - small * 2
        possible_upgrades = remain_tomato // 2

        return [possible_upgrades, small - possible_upgrades]
