/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * unsafe fn guess(num: i32) -> i32 {}
 */

impl Solution {
    unsafe fn guessNumber(n: i32) -> i32 {

        let mut low = 1_i32;
        let mut high = n;

        while low <= high {
            let guess_num = low + (high - low) / 2;
            let guess_result = guess(guess_num);

            match guess_result {
                1 => low = guess_num + 1,
                -1 => high = guess_num - 1,
                _ => return guess_num,
            }
        }

        return -1;
    }
}
