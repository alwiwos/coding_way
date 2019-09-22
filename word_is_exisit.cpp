#include<iostream>
#include<vector>
using namespace std;

class Sulotion
{
    private:
        vector<vector<bool>> visited;
        int m,n;
        int dir[4][2] = {{-1,0},{1,0}, {0,-1},{0,1}};
        bool inArea(int x, int y) {
            return x >=0 && x < m && y >= 0 && y < n;
        }

        bool searchWord(vector<vector<char>> &board, string word, int index, int x, int y)
        {
            if (index == (word.size() - 1)) {
                return word[index] == board[x][y];
            }

            if (word[index] == board[x][y]) {
                visited[x][y] = true;
                for (int i = 0; i < 4; i++) {
                    int newx = dir[i][0] + x;
                    int newy = dir[i][1] + y;
                    if (inArea(newx, newy) && !visited[newx][newy])
                    {
                        if (searchWord(board, word, index + 1, newx, newy))
                        {
                            return true;
                        }
                    }
                    
                }
                visited[x][y] = false;
            }
            return false;
        }
    public:
        bool exist(vector<vector<char>>& board, string word) 
        {
            m = board.size();
            n = board[0].size();
            for (int i = 0; i < m; i++) {
                visited.push_back(vector<bool>(n, false));
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if(searchWord(board, word, 0, i, j))
                    {
                        return true;
                    }
                }
            }
            return false;
        }
};

int main()
{
    vector<vector<char>> board(4, vector<char>(4,'a'));
    board[0] = {'a', 'b', 'c', 'e'};
    board[1] = {'s', 'f', 'c', 's'};
    board[2] = {'a', 'd', 'e', 'e'};
    string word = "abcb";
    Sulotion ans;
    if (ans.exist(board, word)) {
        cout<<"true"<<endl;
        return 0;
    }
    cout<<"false"<<endl;
    return 0;
}