int mySqrt(int x)
{
    double low = 0, high = x, mid;
    if (x == 1) return 1;

    while ((high - low) > 0.00001)
    {
        mid = (high + low) / 2.0;

        if (mid * mid > x)
            high = mid;
        else
            low = mid;
    }

    return high;
}