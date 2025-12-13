char* longestCommonPrefix(char** strs, int strsSize) {
    bool flag = true;
    int position = 0;
    char* result = malloc((position + 1) * sizeof(char));
    result[0] = '\0';
    char sign;
    while(flag){
        if(position > strlen(strs[0]))
            break;
        sign = strs[0][position]; 
        for(int i = 1; i < strsSize; i++){
            if(strs[i][position] != sign)
                flag = false; 
        }
        if(flag == false)
            break;
        position++;
        result = realloc(result, (position + 1) * sizeof(char));
        result[position] = '\0';
        result[position - 1] = sign;
    }
    return result;
}
