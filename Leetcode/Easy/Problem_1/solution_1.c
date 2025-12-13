int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* tab = malloc(2 * sizeof(int));
    for(int i = 0; i < numsSize - 1; ++i){
        for(int j = i + 1; j < numsSize; ++j){
            if((nums[i] + nums[j]) == target){
                tab[0] = i;
                tab[1] = j;
                *returnSize = 2;
                return tab;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
