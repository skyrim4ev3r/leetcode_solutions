/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);

int guessNumber(int n)
{
	int lo = 1;
    int hi = n;

    while (lo <= hi) {
        const int guess_num = lo + (hi - lo) / 2;
        const int guess_result = guess(guess_num);

        if (guess_result == 1) {
            lo = guess_num + 1;
        } else if(guess_result == -1) {
            hi = guess_num - 1;
        } else {
            return guess_num;
        }
    }

    return -1;
}
