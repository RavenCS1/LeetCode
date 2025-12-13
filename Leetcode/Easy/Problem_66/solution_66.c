int* plusOne(int* digits, int digitsSize, int* returnSize){
    *returnSize = digitsSize;
    if(digits[digitsSize - 1] < 9){
        digits[digitsSize - 1] += 1;
        return digits;
    }
    bool flag, over;
    flag = over = true;
    for(int i = 0; i < digitsSize; ++i){
        if(digits[i] != 9){
            flag = false;
            break;
        }
    }
    if(flag){
        int* tab = calloc(digitsSize + 1, sizeof(*tab));
        (*returnSize)++;
        tab[0] = 1;
        return tab;
    }
    int position = digitsSize - 1;
    digits[position--] = 0;
    while(over){
        if(digits[position] + 1 > 9)
            digits[position--] = 0;
        else{
            digits[position] += 1;
            over = false;
        }
    }
    return digits;
}
