int removeElement(int* nums, int numsSize, int val){
    int counter = 0;
    int position = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == val){
            position = i;
            while(position < numsSize - 1){
                if(nums[position] != val){
                    nums[i] = nums[position];
                    nums[position] = val;
                    counter++;
                    break;
                }
                position++;
            }
            if(position == numsSize - 1)
                goto end;
        }
        else
            counter++;
    }
    end:
    return counter;  
}
