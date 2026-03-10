int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize - k + 1;
    int* result = malloc(*returnSize * sizeof(int));
    int deque[100005];
    int front = 0, rear = -1;
    
    for (int i = 0; i < numsSize; i++) {
        if (front <= rear && deque[front] < i - k + 1)
            front++;
        
        while (front <= rear && nums[deque[rear]] <= nums[i])
            rear--;
        
        deque[++rear] = i;
        
        if (i >= k - 1)
            result[i - k + 1] = nums[deque[front]];
    }
    return result;
}
