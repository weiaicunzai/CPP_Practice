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

bool solveUtil(arr2D &arr, int col)
{
    if(col >= arr.size())
    {
        printSolution(arr);
        std::cout << std::endl;
        return true;
    }

    bool res = false;
    for(int row = 0; row < arr.size(); row++)
    {
        //for 0th col
        if(!col)
        {
            arr[row][col] = 1;
            res = solveUtil(arr, col + 1) || res;
            arr[row][col] = 0; // backtracking
        }
        else
        {
            // for col != 0
            // we iterate through the first
            //(col - 1) cols, find 1 and its
            //row, col
            
            if(!checkConflict(arr, col, row)) continue;
            arr[row][col] = 1;

            res = solveUtil(arr, col + 1) || res;
            
            arr[row][col] = 0;  // backtracking
        }

        
    }
    return res;
}

bool solveNQ(arr2D &board, int N)
{
    for(int row = 0; row < N; row++)
    {
        board.push_back(std::vector<int>());
        for(int col = 0; col < N; col++)
            board[row].push_back(0);
    }

   // printSolution(board);
    return solveUtil(board, 0);
}


int main()
{

    arr2D board;
    int N = 4;
    if(!solveNQ(board, N))
        std::cout << "No solutions"  << std::endl;
    
    return 0;
}