int strStr(char* haystack, char* needle){
    int result = -1;
    int hay = strlen(haystack);
    int need = strlen(needle);
    int cmp;
    char* new;
    for(int i = 0; i <= hay - need; i++){
        new = haystack + i;
        cmp = strncmp(needle, new, need);
        if(cmp == 0){
            result = i;
            break;
        }
    }
    return result;
}
