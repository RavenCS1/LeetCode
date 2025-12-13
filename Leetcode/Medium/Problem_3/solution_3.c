int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    if(n == 0)
        return 0;
    int counter = 1;
    int longest = 1;
    int starter = 0;
    for(int i = 1; i < n; i++){
        for(int j = starter; j < i; j++){
            if(s[j] == s[i]){
                starter = j + 1;
                i = starter;
                counter = 0;
                break;
            }
        }
        counter++;
        if(counter > longest)
            longest = counter;
    }
    return longest;;
}
