char* numberToWords(int num){
    if(num == 0){
        static char* result = "Zero";
        return result;
    }

    int counter = 0;
    int copy = num;
    
    while(copy > 0){    
        copy /= 10;
        counter++;
    }

    copy = num;

    int counter_copy = counter - 1;
    int digits[counter];

    while(copy >= 1){
        digits[counter_copy--] = copy % 10;
        copy /= 10;
    }

    counter_copy = counter;

    char* result = calloc(150, sizeof(*result));
    char* tmp = 0;
    bool check = false;

    for(int i = 0; i < counter; ++i){
        check = false;
        if(counter_copy == 1 || counter_copy == 3 || counter_copy == 4 || counter_copy == 6 || counter_copy == 7 || counter_copy == 9 || counter_copy == 10){
            switch(digits[i]){
                case 0: tmp = ""; break;
                case 1: tmp = "One "; break;
                case 2: tmp = "Two "; break;
                case 3: tmp = "Three "; break;
                case 4: tmp = "Four "; break;
                case 5: tmp = "Five "; break;
                case 6: tmp = "Six "; break;
                case 7: tmp = "Seven "; break;
                case 8: tmp = "Eight "; break;
                case 9: tmp = "Nine "; break;
            }
            if(tmp) strcat(result, tmp);
        }
        if(counter_copy == 2 || counter_copy == 5 || counter_copy == 8){
            switch(digits[i]){
                case 0: tmp = ""; break;
                case 1: {
                    switch(digits[i + 1]){
                        case 0: tmp = "Ten "; break;
                        case 1: tmp = "Eleven "; break;
                        case 2: tmp = "Twelve "; break;
                        case 3: tmp = "Thirteen "; break;
                        case 4: tmp = "Fourteen "; break;
                        case 5: tmp = "Fifteen "; break;
                        case 6: tmp = "Sixteen "; break;
                        case 7: tmp = "Seventeen "; break;
                        case 8: tmp = "Eighteen "; break;
                        case 9: tmp = "Nineteen "; break;
                    }
                    check = true;
                    break;
                }
                case 2: tmp = "Twenty "; break;
                case 3: tmp = "Thirty "; break;
                case 4: tmp = "Forty "; break;
                case 5: tmp = "Fifty "; break;
                case 6: tmp = "Sixty "; break;
                case 7: tmp = "Seventy "; break;
                case 8: tmp = "Eighty "; break;
                case 9: tmp = "Ninety "; break;
            }
            if(tmp) strcat(result, tmp);
        }
        switch(counter_copy--){
            case 1: tmp = ""; break;
            case 2: {
                tmp = ""; 
                if(check){
                    counter_copy--;
                    i++;
                }
                break;
            }
            case 3: {
                if(digits[i] != 0){
                    tmp = "Hundred "; 
                }
                break;
            }
            case 4: {
                if((counter == 6 && (digits[i - 2] != 0 || digits[i - 1] != 0 || digits[i] != 0)) ||
                   (counter == 5 && (digits[i - 1] != 0 || digits[i] != 0)) ||
                   (counter == 4 && digits[i] != 0) ||
                   (counter > 6 && (digits[i - 2] != 0 || digits[i - 1] != 0 || digits[i] != 0))
                ){
                    tmp = "Thousand "; 
                }
                break;
            }
            case 5: {
                tmp = ""; 
                if(check){
                    tmp = "Thousand ";
                    counter_copy--;
                    i++;
                }
                break;
            }
            case 6: {
                if(digits[i] != 0){
                    tmp = "Hundred "; 
                }
                break;
            }
            case 7: {
                 if((counter == 9 && (digits[i - 2] != 0 || digits[i - 1] != 0 || digits[i] != 0)) ||
                   (counter == 8 && (digits[i - 1] != 0 || digits[i] != 0)) ||
                   (counter == 7 && digits[i] != 0) ||
                   (counter > 9 && (digits[i - 2] != 0 || digits[i - 1] != 0 || digits[i] != 0))
                ){
                    tmp = "Million "; 
                }
                break;
            }
            case 8: {
                    tmp = ""; 
                    if(check){
                        tmp = "Million ";
                        counter_copy--;
                        i++;
                    }
                    break;
            }
            case 9: {
                if(digits[i] != 0){
                    tmp = "Hundred "; 
                }
                break;
            }
            case 10: tmp = "Billion "; break;
        }
        if(tmp) strcat(result, tmp);
    }

    result[strlen(result) - 1] = '\0';
    return result;
}
