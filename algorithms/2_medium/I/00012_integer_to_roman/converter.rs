impl Solution {
    pub fn int_to_roman(mut num: i32) -> String {
        let mut steps = 0_usize;
        let mut res: Vec<u8> = Vec::new();

        let map_steps = [
            [b'I',b'V',b'X'],
            [b'X',b'L',b'C'],
            [b'C',b'D',b'M'],
            [b'M',b'_',b'_'],
        ];

        while num > 0 {
            let rem = num % 10;
            num /= 10;

            match rem {
                1 => {
                    res.push(map_steps[steps][0]);
                },
                2 => {
                    res.push(map_steps[steps][0]);
                    res.push(map_steps[steps][0]);
                },
                3 => {
                    res.push(map_steps[steps][0]);
                    res.push(map_steps[steps][0]);
                    res.push(map_steps[steps][0]);
                },
                4 => {
                    res.push(map_steps[steps][1]);
                    res.push(map_steps[steps][0]);
                },
                5 => {
                    res.push(map_steps[steps][1]);
                },
                6 => {
                    res.push(map_steps[steps][0]);
                    res.push(map_steps[steps][1]);
                },
                7 => {
                    res.push(map_steps[steps][0]);
                    res.push(map_steps[steps][0]);
                    res.push(map_steps[steps][1]);
                },
                8 => {
                    res.push(map_steps[steps][0]);
                    res.push(map_steps[steps][0]);
                    res.push(map_steps[steps][0]);
                    res.push(map_steps[steps][1]);
                },
                9 => {
                    res.push(map_steps[steps][2]);
                    res.push(map_steps[steps][0]);
                },
                _ => {}
            };

            steps += 1;
        }

        res.reverse();

        String::from_utf8(res).unwrap()
    }
}
