#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

void printIntArr(const std::vector<int> &arr)
{
    if (arr.empty())
    {
        std::cout << "[]\n";
        return;
    }

    std::cout << "[";
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[n - 1] << "]";
}

void printArrArr(const std::vector<std::vector<int>> &arr)
{
    if (arr.empty())
    {
        std::cout << "[]\n";
        return;
    }

    std::cout << "[";
    for (auto a : arr)
    {
        printIntArr(a);
    }
    std::cout << "]";
}

void drawSudokuBoard(const std::vector<std::vector<int>> &board)
{
    for (int row = 0; row < 9; ++row)
    {
        if (row % 3 == 0 && row != 0)
        {
            std::cout << "------+-------+------\n";
        }
        for (int col = 0; col < 9; ++col)
        {
            if (col % 3 == 0 && col != 0)
            {
                std::cout << "| ";
            }
            if (board[row][col] == 0)
            {
                std::cout << "_ ";
            }
            else
            {
                std::cout << board[row][col] << ' ';
            }
        }
        std::cout << '\n';
    }
}

void printMatrix(const std::vector<std::vector<int>> &matrix)
{
    int maxWidth = 0;

    // Find the maximum number width
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            int width = (val == 0) ? 1 : std::to_string(std::abs(val)).size();
            if (val < 0)
                width++; // account for minus sign
            maxWidth = std::max(maxWidth, width);
        }
    }

    // Print matrix with alignment
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            std::cout << std::setw(maxWidth + 1) << val;
        }
        std::cout << '\n';
    }
}

std::vector<std::vector<int>> readArraysFromFile(const std::string &filename)
{
    std::vector<std::vector<int>> arrays;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error: Cannot open file '" << filename << "'\n";
        return arrays;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::vector<int> row;
        int num;
        while (iss >> num)
        {
            row.push_back(num);
        }
        if (!row.empty())
        {
            arrays.push_back(row);
        }
    }

    file.close();
    return arrays;
}

std::string stripQuotes(const std::string &line)
{
    if (line.length() >= 2 && line.front() == '"' && line.back() == '"')
    {
        return line.substr(1, line.length() - 2); // Remove the first and last char
    }
    return line; // Return as-is if not quoted
}

std::vector<std::string> readStringsFromFile(const std::string &filename)
{
    std::vector<std::string> strings;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error: Cannot open file '" << filename << "'\n";
        return strings;
    }

    std::string line;
    while (std::getline(file, line))
    {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end()); // handle Windows line endings
        if (!line.empty())
        {
            strings.push_back(stripQuotes(line));
        }
    }

    file.close();
    return strings;
}

template <typename T>
bool arrayContains(std::vector<T> arr, T ele)
{
    return std::count(arr.begin(), arr.end(), ele) != 0;
}

#endif