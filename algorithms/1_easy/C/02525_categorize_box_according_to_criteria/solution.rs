impl Solution {
    pub fn categorize_box(length: i32, width: i32, height: i32, mass: i32) -> String {
        const min_bulky_len: i32 = 10_000;
        const min_bulky_volume: i64 = 1_000_000_000;
        const min_heavy_mass: i32 = 100;

        let mut is_bulky = false;
        let mut is_heavy = false;

        let volume = (length as i64) * (width as i64) * (height as i64);

        if  length >= min_bulky_len || width >= min_bulky_len 
            || height >= min_bulky_len || volume >= min_bulky_volume 
        {
            is_bulky = true;
        }

        if mass >= min_heavy_mass {
            is_heavy = true;
        }

        let ans = if is_bulky && is_heavy {
            "Both"
        } else if is_bulky {
            "Bulky"
        } else if is_heavy {
            "Heavy"
        } else {
            "Neither"
        };

        String::from(ans)
    }
}
