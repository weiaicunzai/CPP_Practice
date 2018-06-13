//practice for 4 queen problem

#include<vector>
#include<iostream>

typedef std::vector<std::vector<int>> arr2D;

void printSolution(const arr2D& arr)
{
    for(auto row : arr)
    {
        for(auto col : row)
            std::cout << col << " ";
        std::cout << std::endl;
    }
    

}

bool checkConflict(arr2D arr, int col, int row)
{
    //if first column, no conflict
    if(!col) return true;
    for (int c = 0; c < col; c++)
    {
        for (int r = 0; r < arr.size(); r++)
        {
            //if we found the queen in
            // c th column
            if (arr[r][c])
            {
                if (r == row)
                    return false;
                if (r + col - c == row)
                    return false;
                if (r - col + c == row)
                    return false;
            }
        }
    }
    return true;
}

void solveUtil(arr2D &arr, int col)
{
    if(col >= arr.size())
    {
        printSolution(arr);
        std::cout << std::endl;
        return;
    }

    for(int row = 0; row < arr.size(); row++)
    {
            // for col != 0
            // we iterate through the first
            //(col - 1) cols, find 1 and its
            //row, col
            
            if(!checkConflict(arr, col, row)) continue;
            arr[row][col] = 1;
            solveUtil(arr, col + 1);
            arr[row][col] = 0;  // backtracking
    }
    return;
}

void solveNQ(arr2D &board, int N)
{
    for(int row = 0; row < N; row++)
    {
        board.push_back(std::vector<int>());
        for(int col = 0; col < N; col++)
            board[row].push_back(0);
    }

    solveUtil(board, 0);
    return;
}

int main()
{
    arr2D board;
    int N = 5;
    solveNQ(board, N);
    
    return 0;
}