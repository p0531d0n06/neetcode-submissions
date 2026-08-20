class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int present = 0;
        int num;
        
        for(auto o_i{0uz}; o_i < 9; ++o_i){
            present = 0;
            for(auto o_j{0uz}; o_j < 9; ++o_j){
                num = board[o_i][o_j] - '0';
                if(num <= 0) continue;
                if(present & (1 << (num-1))) return false;
                present += 1 << (num-1);
            }
        }

        for(auto o_i{0uz}; o_i < 9; ++o_i){
            present = 0;
            for(auto o_j{0uz}; o_j < 9; ++o_j){
                num = board[o_j][o_i] - '0';
                if(num <= 0) continue;
                if(present & (1 << (num-1))) return false;
                present += 1 << (num-1);
            }
        }


        // Squares
        for(auto i{0uz}; i < 3; ++i){
            for(auto j{0uz}; j < 3; ++j){

                present = 0;
                // Square
                for(auto o_i{0uz}; o_i < 3; ++o_i){
                    for(auto o_j{0uz}; o_j < 3; ++o_j){
                        num = board[i*3 + o_i][j*3 + o_j] - '0';
                        if(num <= 0) continue;
                        if(present & (1 << (num-1))) return false;
                        present += 1 << (num-1);
                    }
                }

            }
        }

        return true;
    }
};
