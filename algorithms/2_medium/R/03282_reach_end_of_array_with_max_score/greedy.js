/**
 * @param {number[]} nums
 * @return {number}
 */
const findMaximumScore = (nums) => {
    let curr_max = 0 ;
    let score = 0;

    for (const num of nums) {
        score += curr_max;
        curr_max = Math.max(curr_max, num);
    }

    return score;
};
