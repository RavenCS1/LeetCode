bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int kwp, kkp, kwk, kkk;
    for(int wiersz = 0; wiersz < boardSize; ++wiersz){
        for(int kolumna = 0; kolumna < *boardColSize; ++kolumna){
            if(board[wiersz][kolumna] == '.')
                continue;
            for(int i = kolumna + 1; i < *boardColSize; ++i)
                if(board[wiersz][kolumna] == board[wiersz][i])
                    return false;
            for(int j = wiersz + 1; j < boardSize; ++j)
                if(board[wiersz][kolumna] == board[j][kolumna])
                    return false;
            if(wiersz < 3){kwp = 0; kwk = 3;}
            else if(wiersz < 6){kwp = 3; kwk = 6;}
            else{kwp = 6; kwk = 9;}
            if(kolumna < 3){kkp = 0; kkk = 3;}
            else if(kolumna < 6){kkp = 3; kkk = 6;}
            else{kkp = 6; kkk = 9;}
            for(int k = kwp; k < kwk; ++k){
                for(int l = kkp; l < kkk; ++l){
                    if(wiersz == k && kolumna == l)
                        continue;
                    if(board[k][l] == board[wiersz][kolumna])
                        return false;
                }
            }
        }
    }
    return true;
}
