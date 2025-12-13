int removeDuplicates(int* nums, int numsSize){
    int counter = 1;
    int position = 0;
   for(int i = 1; i < numsSize; i++){
        if(nums[i] == nums[i - 1] || nums[i] < nums[i - 1]){
            if(!position) position = i;
            while(position < numsSize - 1){
                position++;
                if(nums[position] != nums[position - 1] && nums[position] > nums[i - 1]){
                    nums[i] = nums[position];
                    counter++;
                    break;
                }
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
