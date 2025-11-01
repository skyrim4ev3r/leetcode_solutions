impl Solution {
    pub fn get_hint(secret: String, guess: String) -> String {
        //wg stands for "wrong guess"
        let mut wg_digit_counts_secret = [0_i32; 10_usize];
        let mut wg_digit_counts_guess = [0_i32; 10_usize];

        let secret = secret.into_bytes();
        let guess = guess.into_bytes();

        let mut correct_guess_count = 0;
        let mut correct_digit_wrong_pos_count = 0;

        for i in 0..secret.len() {
            if secret[i] == guess[i] {
                correct_guess_count += 1;
            } else {
                wg_digit_counts_secret[(secret[i] - b'0') as usize] += 1;
                wg_digit_counts_guess[(guess[i] - b'0') as usize] += 1;
            }
        }

        for i in 0..10_usize {
            correct_digit_wrong_pos_count += wg_digit_counts_guess[i].min(wg_digit_counts_secret[i]);
        }
        
        format!("{}A{}B", correct_guess_count, correct_digit_wrong_pos_count)
    }
}
