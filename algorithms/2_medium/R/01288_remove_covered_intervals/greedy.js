/**
 * @param {number[][]} intervals
 * @return {number}
 */
const removeCoveredIntervals = (intervals) => {
    intervals.sort((a, b) => a[0] === b[0] ? b[1] - a[1] : a[0] - b[0]);

    const len = intervals.length;
    let invalids_count = 0;
    let prev_end = intervals[0][1];

    for (let i = 1; i < len; ++i) {
        if (intervals[i][1] <=  prev_end) {
            invalids_count += 1;
        } else {
            prev_end = intervals[i][1];
        }
    }

    return len - invalids_count;
};
