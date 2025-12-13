double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if(!nums1Size){
        if(nums2Size % 2 == 0){
            int upper = nums2[nums2Size / 2];
            int lower = nums2[nums2Size / 2 - 1];
            return (double)(upper + lower) / 2;
        }
        else
            return (double)(nums2[nums2Size / 2]);
    }
    if(!nums2Size){
        if(nums1Size % 2 == 0){
            int upper = nums1[nums1Size / 2];
            int lower = nums1[nums1Size / 2 - 1];
            return (double)(upper + lower) / 2;
        }
        else
            return (double)(nums1[nums1Size / 2]);
    }
    double wynik;
    int* ptr1 = nums1;
    int* ptr2 = nums2;
    int* median = NULL;
    while((int)(ptr1 - nums1) + (int)(ptr2 - nums2) != ((nums1Size + nums2Size) / 2) + 1){
        if((int)(ptr1 - nums1) != nums1Size && (int)(ptr2 - nums2) != nums2Size){
            if(*ptr1 >= *ptr2){
                ptr2++;
                median = ptr2;
            }
            else{
                ptr1++;
                median = ptr1;
            }
        }
        else if((int)(ptr1 - nums1) == nums1Size && (int)(ptr2 - nums2) != nums2Size){
            if(*ptr2 > *(ptr1 - 1))
                median = ++ptr2;
            else
                ptr2++;
        }
        else{
            if(*ptr1 > *(ptr2 - 1))
                median = ++ptr1;
            else
                ptr1++;
        }
    }
    if(ptr1 == nums1 + nums1Size || ptr1 - 1 >= nums1){
        if(median == ptr1)
            median = --ptr1;
        else
            ptr1--;
    }
    if(ptr2 == nums2 + nums2Size || ptr2 -1 >= nums2){
        if(median == ptr2)
            median = --ptr2;
        else
            ptr2--;
    }
    if((nums1Size + nums2Size) % 2 == 0){
        int lower, upper;
        upper = *median;
        if(ptr1 == median){
            if((ptr1 - 1 >= nums1 && *(ptr1 - 1) > *ptr2) || (ptr1 - 1 >= nums1 && *ptr2 > *ptr1))
                lower = *(ptr1 - 1);
            else
                lower = *ptr2;
        }
        else{
            if((ptr2 - 1 >= nums2 && *(ptr2 - 1) > *ptr1) || (ptr2 - 1 >= nums2 && *ptr1 > *ptr2))
                lower = *(ptr2 - 1);
            else
                lower = *ptr1;
        }
        wynik = (double)(lower + upper) / 2;
    }
    else{
        wynik = *median;
    }
    return wynik;
}
