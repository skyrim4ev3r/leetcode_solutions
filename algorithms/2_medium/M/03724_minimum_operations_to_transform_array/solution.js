/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
const minOperations = (nums1, nums2) => {
    const len = nums1.length;
    const extra_num = nums2[nums2.length - 1];
    let extra_num_min_cost = Number.MAX_SAFE_INTEGER;
    let total_cost = 0;

    for (let i = 0; i < len; ++i) {
        const min = Math.min(nums1[i], nums2[i]);
        const max = Math.max(nums1[i], nums2[i]);
        total_cost += (max - min);

        if (extra_num >= min && extra_num <= max) {
            extra_num_min_cost = 0;
        } else if (extra_num > max) {
            extra_num_min_cost = Math.min(extra_num_min_cost, extra_num - max);
        } else {
            extra_num_min_cost = Math.min(extra_num_min_cost, min - extra_num);
        }
    }

    return total_cost + 1 + extra_num_min_cost;
};
