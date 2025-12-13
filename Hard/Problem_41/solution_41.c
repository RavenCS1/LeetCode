int firstMissingPositive(int* nums, int numsSize){
    for(register int i = 0; i < numsSize; ++i)
        if(nums[i] <= 0 || nums[i] > numsSize) nums[i] = numsSize + 1;
    int checker = 0;
    for(register int i = 0; i < numsSize; ++i){
        checker = abs(nums[i]);
        if(checker-- > numsSize) continue;
        if(nums[checker] > 0) nums[checker] = -1 * nums[checker];
    }
    for(register int i = 0; i < numsSize; ++i)
        if(nums[i] >= 0) return i + 1;
    return numsSize + 1;
}
