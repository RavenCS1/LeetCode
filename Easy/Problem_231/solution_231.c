bool isPowerOfTwo(int n){
    if(n == 0 || n < 0)
        return false;
    n = abs(n);
    int counter = 0;
    while(n != 1){
        if(n % 2 != 0)
            return false;
        n /= 2;
        counter++;
    }
    return true;
}
