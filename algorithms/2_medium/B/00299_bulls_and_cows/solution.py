class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        #wg stands for "wrong guess"
        wg_digit_counts_secret = [0] * 10
        wg_digit_counts_guess = [0] * 10

        correct_guess_count = 0;
        correct_digit_wrong_pos_count = 0;

        for i in range(len(secret)):
            if secret[i] == guess[i]:
                correct_guess_count += 1
            else:
                wg_digit_counts_secret[ord(secret[i]) - ord('0')] += 1
                wg_digit_counts_guess[ord(guess[i]) - ord('0')] += 1

        for i in range(10):
            correct_digit_wrong_pos_count += min(wg_digit_counts_guess[i],(wg_digit_counts_secret[i]))

        return  str(correct_guess_count) + "A" + str(correct_digit_wrong_pos_count) + "B"
