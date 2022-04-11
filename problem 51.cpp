// // Question link :- https://leetcode.com/problems/n-queens/

// #include<bits/stdc++.h>
// using namespace std;

// class Solution 
// {
// public:
//   void display(vector<vector<int>> ans)
//   {
//     for (auto it : ans)
//     {
//       for (auto itr : it)
//         cout << itr << " ";
//       cout << endl;
//     }
//   }
//   bool isItSafe(vector<vector<int>>& board, int row, int col)
//   {
//     // Looking at the upward direction 
//     int r = row - 1;
//     int c = col;
//     while (r >= 0)
//     {
//       if (board[r][c])
//         return false;
//       r--;
//     }

//     // Looking at the left direction
//     r = row;
//     c = col - 1;
//     while (c >= 0)
//     {
//       if (board[r][c])
//         return false;
//       c--;
//     }

//     // Looking a the left diagonal and upward direction
//     r = row - 1;
//     c = col - 1;
//     while (r >= 0 && c >= 0)
//     {
//       if (board[r][c])
//         return false;
//       r--;
//       c--;
//     }

//     // Looking at the right diagonal and upward direction 

//     r = row - 1;
//     c = col + 1;
//     while (r >= 0 && c <= board[0].size() - 1)
//     {
//       if (board[r][c])
//         return false;
//       r--;
//       c++;
//     }
//     return true;
//   }
//   void utilSolveQueen(vector<vector<int>> &board, int row, int col, int tq, int qpsf)
//   {
//     if (tq == qpsf)
//     {
//       display(board);
//       return;
//     }

//     if (col == board[0].size())
//     {
//       row++;
//       col = 0;
//     }

//     if (row == board.size())
//       return;

//     if (isItSafe(board, row, col))
//     {
//       board[row][col] = 1;
//       utilSolveQueen(board, row, col + 1, tq, qpsf + 1);
//       board[row][col] = 0;
//     }
//     utilSolveQueen(board, row, col + 1, tq, qpsf);
//   }

//   void solveNQueens(int n) {
//     vector<vector<int>> ans(n, vector<int>(n, 0));
//     display(ans);
//     utilSolveQueen(ans, n, n, n, 0);
//   }
// };


// Question link :- https://leetcode.com/problems/n-queens/
// OPTIMISED SOLUTION
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  void solve(int col, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& upperDiogonal, vector<int>& lowerDiagonal, int n)
  {
    if (col == n)
    {
      ans.push_back(board);
      return;
    }

    for (int row = 0;row < n;row++)
    {
      if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiogonal[n - 1 + col - row] == 0)
      {
        board[row][col] = 'Q';
        leftRow[row] = 1;
        lowerDiagonal[row + col] = 1;
        upperDiogonal[n - 1 + col - row] = 1;
        solve(col + 1, board, ans, leftRow, upperDiogonal, lowerDiagonal, n);
        board[row][col] = '.';
        leftRow[row] = 0;
        lowerDiagonal[row + col] = 0;
        upperDiogonal[n - 1 + col - row] = 0;
      }
    }
  }
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    // string initialiser class
    string s(n, '.');
    for (int i = 0;i < n;i++)
      board[i] = s;
    vector<int> leftRow(n, 0), upperDiogonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    solve(0, board, ans, leftRow, upperDiogonal, lowerDiagonal, n);
  }
};


// BRUTEFORCE APPROACH
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isSafe(int row, int col, vector<string> board, int n)
  {
    // checking in the left upper arrow direction
    int r = row;
    int c = col;
    while (row >= 0 && col >= 0)
    {
      if (board[row][col] == 'Q')
        return false;
      row--;
      col--;
    }

    // checking in the left direction
    row = r;
    col = c;
    while (col >= 0)
    {
      if (board[row][col] == 'Q')
        return false;
      col--;
    }

    // checking in the left down arrow direction
    row = r;
    col = c;
    while (row <= n && col >= 0)
    {
      if (board[row][col] == 'Q')
        return false;
      row++;
      col--;
    }
    return true;
  }

  void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n)
  {
    if (col == n)
    {
      ans.push_back(board);
      return;
    }

    for (int row = 0;row < n;row++)
    {
      if (isSafe(row, col, board, n))
      {
        board[row][col] = 'Q';
        solve(col + 1, board, ans, n);
        board[row][col] = '.';
      }
    }
  }

  vector<vector<string>> solveNQueens(int n)
  {
    vector<vector<string>> ans;
    vector<string> board(n);
    // string initialiser class
    string s(n, '.');
    for (int i = 0;i < n;i++)
      board[i] = s;
    solve(0, board, ans, n);
  }
};