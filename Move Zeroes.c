void moveZeroes(int* nums, int numsSize)
{
    int buf, i, flag = 1;

    while (flag == 1)
    {
        i = 0;
        flag = 0;
        while (i < numsSize - 1)
        {
            if (nums[i] == 0 && nums[i+1] != 0)
            {
                buf = nums[i + 1];
                nums[i + 1] = 0;
                nums[i] = buf;
                flag = 1;
            }
            i++;
        }
    }
}