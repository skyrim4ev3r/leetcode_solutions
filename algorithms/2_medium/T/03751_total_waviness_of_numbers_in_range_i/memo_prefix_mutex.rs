use std::sync::Mutex;

const MAX_INPUT: usize = 100_000;

struct State {
    memo: [i32; MAX_INPUT + 1],
    pref: [i32; MAX_INPUT + 1],
    curr_max: i32,
}

impl Solution {
    pub fn total_waviness(num1: i32, num2: i32) -> i32 {
        static STATE: Mutex<State> = Mutex::new(State {
            memo: [-1; MAX_INPUT + 1],
            pref: [0; MAX_INPUT + 1],
            curr_max: 0,
        });

        let mut state = STATE.lock().unwrap();

        if state.curr_max <= num2 {
            for num in state.curr_max..=num2 {
                let idx = num as usize;
                if num < 100 {
                    state.memo[idx] = 0;
                    state.pref[idx] = 0;
                } else {
                    let c = num % 10;
                    let b = (num / 10) % 10;
                    let a = (num / 100) % 10;
                    let has_wave = (b > a && b > c) || (b < a && b < c);
                    let count = state.memo[idx / 10] + has_wave as i32;

                    state.pref[idx] = count + state.pref[idx - 1];
                    state.memo[idx] = count;
                }
            }
            state.curr_max = num2 + 1;
        }

        state.pref[num2 as usize] - state.pref[num1 as usize - 1]
    }
}
