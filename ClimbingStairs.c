int climbStairs(int n)
{
    int dp[46];
    if (n <= 2)
        return n;

    if (dp[n] != 0)
        return dp[n];

    dp[n] = climbStairs(n - 2) + climbStairs(n - 1);
    return dp[n];
}