/**
 * @param {string} s
 * @param {string} t
 * @param {number} flipCost
 * @param {number} swapCost
 * @param {number} crossCost
 * @return {number}
 */
const minimumCost = (s, t, flipCost, swapCost, crossCost) => {
    const len = s.length;
    let xy = 0;
    let yx = 0;

    for (let i = 0; i < len; ++i) {
        if (s[i] != t[i]) {
            if (s[i] === '1') {
                xy += 1;
            } else {
                yx += 1;
            }
        }
    }

    const unequalPairs = xy + yx;
    const possibleDirectSwaps = Math.min(xy, yx);
    const impossibleDirectSwaps = Math.abs(xy - yx);
    const possibleCross = Math.floor(impossibleDirectSwaps / 2);
    const forceFlips = (impossibleDirectSwaps & 1);

    const allFlipsCost = unequalPairs * flipCost;

    const allFlipsSwapCost = impossibleDirectSwaps * flipCost +
                                possibleDirectSwaps * swapCost;

    const flipsSwapCrossCost = forceFlips * flipCost +
                                  possibleDirectSwaps * swapCost +
                                  possibleCross * (crossCost + swapCost);

    return Math.min(
        allFlipsCost,
        allFlipsSwapCost,
        flipsSwapCrossCost
    );
};
