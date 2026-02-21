const MIN_WIDTH = 3;

/**
 * @param {number[]} capacity
 * @return {number}
 */
const countStableSubarrays = (capacity) => {
    const len = capacity.length;
    let count = 0;
    let pref_sum_left = 0;
    let pref_sum_right = 0;
    const freqs = new Map();

    for (let i = 0; i < len; ++i) {
        if (i >= (MIN_WIDTH - 1)) {
            const val_left = capacity[i - (MIN_WIDTH - 1)];
            pref_sum_left += val_left;
            const key = [pref_sum_left, val_left].join(',');
            freqs.set(key, (freqs.get(key) || 0) + 1);
        }

        const val_right = capacity[i];
        pref_sum_right += val_right;
        const other_sum = pref_sum_right - (2 * val_right);
        const key = [other_sum, val_right].join(',');
        count += (freqs.get(key) || 0);
    }

    return count;
};
