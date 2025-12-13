char* intToRoman(int num){
    int position = 0;
    int longest = 16; /* 3 + 4 + 4 + 4 + 1 */
    char* result = malloc(longest * sizeof(*result));
    start:
    while(num > 0){
        if(num >= 1000){
            result[position] = 'M';
            position++;
            num -= 1000;
            goto start;
        }
        if(num >= 900 && num <= 999){
            result[position] = 'C';
            result[position + 1] = 'M';
            position += 2;
            num -= 900;
            goto start;
        }
        if(num >= 500 && num < 900){
            result[position] = 'D';
            position += 1;
            num -= 500;
            goto start;
        }
        if(num >= 400 && num < 500){
            result[position] = 'C';
            result[position + 1] = 'D';
            position += 2;
            num -= 400;
            goto start;
        }
        if(num >= 100 && num < 400){
            result[position] = 'C';
            position += 1;
            num -= 100;
            goto start;
        }
        if(num >= 90 && num < 100){
            result[position] = 'X';
            result[position + 1] = 'C';
            position += 2;
            num -= 90;
            goto start;
        }
        if(num >= 50 && num < 90){
            result[position] = 'L';
            position += 1;
            num -= 50;
            goto start;
        }
        if(num >= 40 && num < 50){
            result[position] = 'X';
            result[position + 1] = 'L';
            position += 2;
            num -= 40;
            goto start;
        }
        if(num >= 10 && num < 40){
            result[position] = 'X';
            position += 1;
            num -= 10;
            goto start;
        }
        switch(num){
            case 9: result[position] = 'I';
                    result[position + 1] = 'X';
                    position += 2; 
                    goto end;
            case 8: result[position] = 'V';
                    result[position + 1] = 'I';
                    result[position + 2] = 'I';
                    result[position + 3] = 'I';
                    position += 4; 
                    goto end;
            case 7: result[position] = 'V';
                    result[position + 1] = 'I';
                    result[position + 2] = 'I';
                    position += 3;
                    goto end;
            case 6: result[position] = 'V';
                    result[position + 1] = 'I';
                    position += 2;
                    goto end;
            case 5: result[position] = 'V';
                    position += 1; 
                    goto end;
            case 4: result[position] = 'I';
                    result[position + 1] = 'V';
                    position += 2; 
                    goto end;
            case 3: result[position] = 'I';
                    result[position + 1] = 'I';
                    result[position + 2] = 'I';
                    position += 3;
                    goto end;
            case 2: result[position] = 'I';
                    result[position + 1] = 'I';
                    position += 2; 
                    goto end;
            case 1: result[position] = 'I';
                    position += 1; 
                    goto end;
        }
    }
    end:
    result[position] = '\0';
    return result;
}
