/**
 * @param {number[]} nums
 * @return {number}
 */
const splitArray = (nums) => {
    const len = nums.length;

    let left = 0;
    while (left + 1 < len && nums[left] < nums[left + 1]) {
        left += 1;
    }

    let right = len - 1;
    while (right > 0 && nums[right - 1] > nums[right]) {
        right -= 1;
    }

    if (left === right) {
        const index = left;
        const sum_left_part = nums.slice(0, index).reduce((acc, x) => x + acc, 0);
        const sum_right_part = nums.slice(index + 1).reduce((acc, x) => x + acc, 0);

        if (index === len - 1) {
            return Math.abs(sum_left_part - nums[index]);
        } else if (index === 0) {
            return Math.abs(nums[index] - sum_right_part);
        } else {
            const max = Math.max(sum_left_part, sum_right_part);
            const min = Math.min(sum_left_part, sum_right_part);

            return Math.abs(max - (min + nums[index]));
        }
    } else if (left + 1 === right) {
        const sum_left_part = nums.slice(0, left + 1).reduce((acc, x) => x + acc, 0);
        const sum_right_part = nums.slice(right).reduce((acc, x) => x + acc, 0);

        return Math.abs(sum_left_part - sum_right_part);
    } else {
        return -1;
    }
};
