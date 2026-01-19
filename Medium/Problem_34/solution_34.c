int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* result = malloc(sizeof((*result)) * 2);
    result[0] = result[1] = -1;
    *returnSize = 2;
    bool flag = false;
    for(register int i = 0; i < numsSize; ++i){
        if(nums[i] != target && !flag) {continue;}
        if(!flag) {result[0] = result[1] = i; flag = true;}
        if(flag && nums[i] == target) {result[1] = i;}
        if(flag && nums[i] != target) {break;}
    }
    return result;
}
