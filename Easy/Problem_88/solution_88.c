void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    if(!nums2 || nums2Size == 0) return;
    if(m == 0){
        for(int i = 0; i < nums2Size; ++i){
            nums1[i] = nums2[i];
        }
        return;
    }
    int counter = 0; bool check = false;
    int tmp_1, tmp_2;
    for(int i = 0; i < nums1Size; ++i){
        if(nums2[counter] <= nums1[i]){
            tmp_1 = nums1[i];
            for(int w = i + 1; w < nums1Size; ++w){
                tmp_2 = nums1[w];
                nums1[w] = tmp_1;
                tmp_1 = tmp_2;
            }
            nums1[i] = nums2[counter++];
            if(counter == nums2Size) break;
            else continue;
        }
        if(nums1[i] == 0){
            if(!check){
                for(int j = i + 1; j < nums1Size; ++j){
                    if(nums1[j] != 0){check = true; break;}
                }
            }
            if(!check) nums1[i] = nums2[counter++];
            if(counter == nums2Size) break;
            check = false;
        }
    }
    return;
}
