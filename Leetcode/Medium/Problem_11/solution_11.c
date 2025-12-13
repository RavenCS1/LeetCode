int maxArea(int* height, int heightSize) {
    int* start = height;
    int* end = height + heightSize - 1;
    int result, tmp, len, heigh;
    result = tmp = len = heigh = 0;
    while(start != end){
        len = (int)(end - start);
        if(*start > *end)
            heigh = *end--;
        else
            heigh = *start++;
        tmp = len * heigh;
        if(tmp > result)
            result = tmp;
    }
    return result;
}
