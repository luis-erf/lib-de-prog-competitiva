// Questão da rainha
bool valid(vector<vector<int>>& mat, int l, int c){
    if(mat[l][c] == 2){
        return false;
    }
 
    for(int i = l; i > -1; i--){
        if(mat[i][c] == 1){
            return false;
        }
    }
 
    int a = l, b = c;
    while(a > -1 && b > -1){
        if(mat[a][b] == 1){
            return false;
        }
        a--;
        b--;
    }
 
    a = l;
    b = c;
    while(a > -1 && b < mat.size()){
        if(mat[a][b] == 1){
            return false;
        }
        a--;
        b++;
    }
 
    return true;
}
 
void coloring(vector<vector<int>>& mat, int l, int& resp){
    if(l == 8){
        resp++;
    }
    else{
        for(int i = 0; i < 8; i++){
            if(valid(mat, l, i)){
                mat[l][i] = 1;
                coloring(mat, l + 1, resp);
                mat[l][i] = 0;
            }
        }
    }
}
