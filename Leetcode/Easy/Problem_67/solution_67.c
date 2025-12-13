char* addBinary(char* a, char* b){
    int n1 = strlen(a);
    int n2 = strlen(b);
    int position= n1 > n2 ? n1 + 1 : n2 + 1;
    int cpy = position;
    char* result = malloc(position * sizeof(*result));
    result[--position] = '\0';
    int adition = 0;
    while(n2 && n1){
        if(a[n1 - 1] == '1' && b[n2 - 1] == '1'){
            result[position - 1] = '0' + adition;
            adition = 1;
        }
        else if(a[n1 - 1] == '1' || b[n2 - 1] == '1'){
            if(adition){
                result[position - 1] = '0';
                adition = 1;
            }
            else{
                result[position - 1] = '1';
                adition = 0;
            }
        }
        else{
            result[position - 1] = '0' + adition;
            adition = 0;
        }
        n2--; n1--; position--;
    }
    if(n1){
        while(n1){
            if(a[n1 - 1] == '1' && adition){
                result[position - 1] = '0';
                adition = 1;
            }
            else if(a[n1 - 1] == '1' || adition){
                result[position - 1] = '1';
                adition = 0;
            }
            else{
                result[position - 1] = '0';
                adition = 0;
            }
            n1--; position--;
        }
    }
    if(n2){
        while(n2){
            if(b[n2 - 1] == '1' && adition){
                result[position - 1] = '0';
                adition = 1;
            }
            else if(b[n2 - 1] == '1' || adition){
                result[position - 1] = '1';
                adition = 0;
            }
            else{
                result[position - 1] = '0';
                adition = 0;
            }
            n2--; position--;
        }
    }
    if(adition){
        result = realloc(result, (cpy + 1) * sizeof(char));
        memmove(result + 1, result, cpy * sizeof(char));
        result[0] = '1';
    }
    return result;
}
