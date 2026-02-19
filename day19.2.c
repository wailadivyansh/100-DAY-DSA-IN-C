int maxSubarraySumCircular(int* nums, int numsSize) {

    if (0 == numsSize) return 0;

    int sum = 0;

    int curr_min_sum = 0;
    int min_sum = nums[0];

    int curr_sum = 0;
    int max_sum = nums[0];
    for (int i = 0; i < numsSize; ++i) {
        curr_sum += nums[i];
        if (curr_sum > max_sum) max_sum = curr_sum;
        if (curr_sum < 0) curr_sum = 0;

        curr_min_sum += nums[i];
        if (curr_min_sum < min_sum) min_sum = curr_min_sum;
        if (curr_min_sum > 0) curr_min_sum = 0;

        sum += nums[i];
    }

    int tmp = sum - min_sum;
    if (min_sum != sum && tmp > max_sum) max_sum = tmp;

    return max_sum;

}