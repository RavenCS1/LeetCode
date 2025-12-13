int removeDuplicates(int* nums, int numsSize){
    if(nums == 0 || numsSize == 0) return 0;
    if(numsSize == 1) return 1;
    int position = 0, count = 1, smallest = nums[0] - 1;
    bool flag = false;
    for(int i = 1; i < numsSize; ++i){
        if(nums[position] != nums[i] && nums[i] > nums[position]){count = 1; flag = false;}
        if(nums[position + 1] == smallest && count != 2){
            nums[position + 1] = nums[i];
            if(nums[i] == nums[position]){count++; flag = true;}
            nums[i] = smallest;
            goto end;
        }
        if(nums[position] == nums[i] && flag == true){
            while(i < numsSize){
                if(nums[position] != nums[i]){
                    nums[position + 1] = nums[i];
                    nums[i] = smallest;
                    break;
                }
                nums[i] = smallest; i++;
            }
            count = 1; flag = false;
            goto end;
        }
        if(nums[position] == nums[i] && flag == false) count++;
        if(count == 2) flag = true;
        end:
            if(!(nums[i - 1] == smallest && i == numsSize)) position++;
    }
    return position + 1;
}
