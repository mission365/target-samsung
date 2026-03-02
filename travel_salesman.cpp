function totalCost(mask, curr, cost, dp) {
    
    const n = cost.length;
    
    // Base case: if all cities are visited, return the
    // cost to return to the starting city (0)
    if (mask === (1 << n) - 1) {
        return cost[curr][0];
    }

    // If the value has already been computed, return it
    // from the dp table
    if (dp[curr][mask] !== -1) {
        return dp[curr][mask];
    }

    let ans = Number.MAX_SAFE_INTEGER;

    // Try visiting every city that has not been visited yet
    for (let i = 0; i < n; i++) {
        if ((mask & (1 << i)) === 0) {

            // If city i is not visited 
            // Visit city i and update the mask
            ans = Math.min(ans, cost[curr][i]
                                + totalCost(mask | (1 << i), i, cost, dp));
        }
    }
    return dp[curr][mask] = ans;
}

function tsp(cost) {
    const n = cost.length;
    const dp = Array.from({ length: n }, () => Array(1 << n).fill(-1));

    // Initialize the dpization table with -1
    // (indicating uncomputed states)
    for (let i = 0; i < n; i++) {
        dp[i].fill(-1);
    }
    
    const mask = 1, curr = 0;
    
    // Start from city 0, with only city 0
    // visited initially (mask = 1)
    return totalCost(mask, curr, cost, dp);
}

// Driver code
const cost = [
    [0, 10, 15, 20],
    [10, 0, 35, 25],
    [15, 35, 0, 30],
    [20, 25, 30, 0]
];
const res = tsp(cost);
console.log(res);
