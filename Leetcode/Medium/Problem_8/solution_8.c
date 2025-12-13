int myAtoi(char* s){
    int n, result, multi, counter, translate;
    n = strlen(s);
    result = multi = counter = 0;
    bool sign, flag, over, through;
    sign = true;
    flag = over = through = false;
    int* ptr = malloc(n * sizeof(*ptr));
    for(int i = 0; i < n; i++){
        if(s[i] == ' ' && through == false) continue;
        if(s[i] == '-' && through == false){
            sign = false;
            through = !sign;
            continue;
        }
        if(s[i] == '+' && through == false){
            through = sign = true;
            continue;
        }
        if(!(isdigit(s[i]))) goto inter;
        if(s[i] == '0' && flag == false){
            through = true;
            continue;
        }
        if(through == true && !isdigit(s[i]))
            return 0;
        else{
            through = flag = true;
            switch(s[i]){
                case 48: translate = 0; break;
                case 49: translate = 1; break;
                case 50: translate = 2; break;
                case 51: translate = 3; break;
                case 52: translate = 4; break;
                case 53: translate = 5; break;
                case 54: translate = 6; break;
                case 55: translate = 7; break;
                case 56: translate = 8; break;
                case 57: translate = 9; break;
            }
            ptr[counter++] = translate;
        }
    }
    inter: 
    multi = pow(10, counter - 1);
    if(multi < 0){
        over = true;
        goto end;
    }
    for(int j = 0; j < counter; j++){
        if(ptr[j] > INT_MAX / multi || INT_MAX - result - multi * ptr[j] < 0){
            result = INT_MAX;
            over = true;
            goto end;
        }
        result += ptr[j] * multi;
        multi /= 10;
    }
    end:
    if(sign == false && over == true)
        result = INT_MIN;
    else if(sign == false)
        result = result - 2 * result;
    free(ptr);
    return result;
}
