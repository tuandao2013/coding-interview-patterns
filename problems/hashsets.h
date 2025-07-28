#ifndef HASHSETS_H
#define HASHSETS_H

#include "libs.h"
#include <unordered_set>

class Hashsets
{
public:
    /* QUESTION: VERIFY SUDOKU BOARD
Given a partially completed 9x9 Sudoku board, determine if the current state of the board adheres to the rules of the game:
    + Each row and column must contain unique numbers between 1 and 9, or be empty (represented as 0).
    + Each of the nine 3x3 subgrids that compose the grid must contain unique numbers between 1 and 9
    , or be empty.
Note: You are asked to determine whether the current state of the board is valid given these rules, not whether the board
is solvable.
*/
    bool verifySudokuBoard(std::vector<std::vector<int>> board) /* *Time Complexity: O(n^2) because iterate through each cell twice if n is the number of rows and columns
                                                                    In this case it is O(1) since the number of rows and columns is fixed at 9 */
    {
        std::vector<std::unordered_set<int>> rowSets;
        std::vector<std::unordered_set<int>> colSets;
        std::vector<std::vector<std::unordered_set<int>>> subgridSets;

        for (int i = 0; i < 9; i++)
        {
            rowSets.push_back(std::unordered_set<int>());
            colSets.push_back(std::unordered_set<int>());
        }
        for (int i = 0; i < 3; i++)
        {
            std::vector<std::unordered_set<int>> s;
            for (int j = 0; j < 3; j++)
            {
                s.push_back(std::unordered_set<int>());
            }
            subgridSets.push_back(s);
        }
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                int num = board[row][col];
                if (num == 0)
                {
                    continue;
                }
                if (rowSets[row].count(num) != 0)
                {
                    return false;
                }
                if (colSets[col].count(num) != 0)
                {
                    return false;
                }
                rowSets[row].insert(num);
                colSets[col].insert(num);
                subgridSets[row / 3][col / 3].insert(num);
            }
        }
        return true;
    }

    /* QUESTION: ZERO STRIPING
    For each zero in an mxn matrix, set its entire row and column to zero in place.
    */
    void zeroStrippingHashSets(std::vector<std::vector<int>> &matrix) // matrix m X n
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return;
        }
        int m = matrix.size();    // number of rows
        int n = matrix[0].size(); // number of columns
        std::unordered_set<int> zeroRows;
        std::unordered_set<int> zeroCols;

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (matrix[row][col] == 0)
                {
                    zeroRows.insert(row);
                    zeroCols.insert(col);
                }
            }
        }

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (zeroRows.count(row) != 0 || zeroCols.count(col) != 0)
                {
                    matrix[row][col] = 0;
                }
            }
        }
    }

    void zeroStrippingInplace(std::vector<std::vector<int>> &matrix) // matrix m X n
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return;
        }
        int m = matrix.size();    // number of rows
        int n = matrix[0].size(); // number of columns
        bool firstRowHasZero = false;
        bool firstColHasZero = false;

        for (int col = 0; col < n; col++)
        {
            if (matrix[0][col] == 0)
            {
                firstRowHasZero = true;
                break;
            }
        }

        for (int row = 0; row < m; row++)
        {
            if (matrix[row][0] == 0)
            {
                firstColHasZero = true;
                break;
            }
        }

        for (int row = 1; row < m; row++)
        {
            for (int col = 1; col < n; col++)
            {
                if (matrix[row][col] == 0)
                {
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }

        for (int row = 1; row < m; row++)
        {
            for (int col = 1; col < n; col++)
            {
                if (matrix[row][0] == 0 || matrix[0][col] == 0)
                {
                    matrix[row][col] = 0;
                }
            }
        }

        if (firstColHasZero)
        {
            for (int col = 0; col < n; col++)
            {
                matrix[0][col] = 0;
            }
        }

        if (firstRowHasZero)
        {
            for (int row = 0; row < m; row++)
            {
                matrix[row][0] = 0;
            }
        }
    }
};

#endif