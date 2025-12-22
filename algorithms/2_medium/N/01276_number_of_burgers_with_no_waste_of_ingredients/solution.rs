impl Solution {
    pub fn num_of_burgers(tomato_slices: i32, cheese_slices: i32) -> Vec<i32> {
        if (
            (tomato_slices & 1) == 1 ||
            tomato_slices > cheese_slices * 4 ||
            tomato_slices < cheese_slices * 2
        ) {
            return Vec::new();
        }

        let small = cheese_slices;
        let remain_tomato = tomato_slices - small * 2;
        let possible_upgrades = remain_tomato / 2;

        vec![possible_upgrades, small - possible_upgrades]
    }
}
