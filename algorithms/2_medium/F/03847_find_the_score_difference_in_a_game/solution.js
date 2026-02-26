/**
 * @param {number[]} nums
 * @return {number}
 */
const scoreDifference = (nums) => {
    const len = nums.length;
    const points = new Array(2).fill(0);
    let curr_player = 0;

    for (let i = 0; i < len; ++i) {
        if (i % 6 === 5) {
            curr_player = (curr_player + 1) % 2;
        }

        if ((nums[i] & 1) === 1) {
            curr_player = (curr_player + 1) % 2;
        }

        points[curr_player] += nums[i];
    }

    return points[0] - points[1];
};
