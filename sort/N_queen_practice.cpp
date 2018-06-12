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
        for (int r = 0; r < 4; r++)
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
    if(col >= 4)
        return true;
    for(int row = 0; row < 4; row++)
    {
        //for 0th col
        if(!col)
        {
            arr[row][col] = 1;
            if(solveUtil(arr, col + 1))
                return true;
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

            if(solveUtil(arr, col + 1))
                    return true;
            
            arr[row][col] = 0;  // backtracking
        }

        
    }
    //std::cout << col << std::endl;
    //std::cout << std::endl;
    //    printSolution(arr);
    return false;
}

bool solveNQ(arr2D &board)
{
    for(int row = 0; row < 4; row++)
    {
        board.push_back(std::vector<int>());
        for(int col = 0; col < 4; col++)
            board[row].push_back(0);
    }

   // printSolution(board);
    return solveUtil(board, 0);
}


int main()
{

    arr2D board;
    if(solveNQ(board))
        printSolution(board);
    
    return 0;
}