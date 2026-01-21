void sortColors(int* nums, int numsSize){
    bool red, white;
    red = white = false;
    int* checker = nums + 1;
    for(register int i = 0; i < numsSize; ++i){
        start:
        if(nums[i] == 0 && !red){checker++; continue;}
        else if (nums[i] != 0 && !red){
            while(checker < nums + numsSize && *checker != 0){checker++;}
            if(checker < nums + numsSize){
                *checker = nums[i];
                checker++;
                nums[i] = 0;
            }
            else{red = true; checker = nums + i + 1; goto start;}
        }
        else if(nums[i] == 1 && red && !white){checker++; continue;}
        else if(nums[i] != 1 && red && !white){
            while(checker < nums + numsSize && *checker != 1){checker++;}
            if(checker < nums + numsSize){
                *checker = nums[i];
                checker++;
                nums[i] = 1;
            }
            else{white = true; checker = nums + i + 1; goto start;}  
        }
        else if(red && white){break;}
    }
    return;
}
