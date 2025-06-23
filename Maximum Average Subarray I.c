double findMaxAverage(int* nums, int numsSize, int k)
{
    double sum = 0, max_ave = 0;

    for (int i = 0; i < k; i++)
        sum += nums[i];
    max_ave = sum / k;
    if (k >= numsSize)
        return max_ave;

    for (int i = k; i < numsSize; i++)
    {
        sum += nums[i] - nums[i - k];
        max_ave = fmax(sum / k, max_ave);
    }

    return max_ave;

    // int i = 0, j = k;
    // double max_ave = 0, max_sum_temp = 0, max_sum = 0;

    // if (k == 1 && numsSize == 1)
    //     return nums[0];
    // else if (k == 1)
    // {
    //     while (i < numsSize)
    //     {
    //         if (max_ave < nums[i])
    //             max_ave = nums[i];
    //         i++;
    //     }
    //     return max_ave;
    // }

    // while (i < j)
    // {
    //     max_sum += nums[i];
    //     i++;
    // }
    // max_ave = max_sum / k;
    // i = 0;

    // while (j < numsSize)
    // {
    //     max_sum_temp = max_sum - nums[i] + nums[j];
    //     i++;
    //     j++;
    //     if (max_sum_temp > max_sum)
    //     {
    //         max_ave = max_sum_temp / k;
    //         max_sum = max_sum_temp;
    //     }
    // }

    // return max_ave;
}