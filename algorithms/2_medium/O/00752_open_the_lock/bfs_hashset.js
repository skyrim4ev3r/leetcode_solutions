/**
 * @param {string[]} deadends
 * @param {string} target
 * @return {number}
 */
const modifyChar = (originalChar, changeAmount) => {
    const asciiValue = originalChar.charCodeAt(0);
    const modifiedAscii = asciiValue + changeAmount;
    return String.fromCharCode(modifiedAscii);
}
const openLock = (deadends, target) => {
    let invalids = new Set(deadends);
    let q = [];
    let first_str = "0000";

    if (invalids.has(first_str)) {
        return -1;
    }

    q.push(first_str);
    let turns = 0;

    while (q.length != 0) {
        const len = q.length;
        for (let c = 0; c < len; c += 1) {
            let curr = q.shift();

            if (curr == target) {
                return turns;
            }

            for (let i = 0; i < curr.length; i += 1) {
                const temp1 = curr.slice(0, i)  + (curr[i] === '9' ? '0' : modifyChar(curr[i], 1)) + curr.slice(i + 1);

                if (!invalids.has(temp1)) {
                    q.push(temp1);
                    invalids.add(temp1);
                }

                const temp2 = curr.slice(0, i)  + (curr[i] === '0' ? '9' : modifyChar(curr[i], -1)) + curr.slice(i + 1);

                if (!invalids.has(temp2)) {
                    q.push(temp2);
                    invalids.add(temp2);
                }
            }
        }

        turns += 1;
    }

    return -1;
};
