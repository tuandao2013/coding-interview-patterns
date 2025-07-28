#ifndef TWO_POINTERS_H
#define TWO_POINTERS_H

#include "libs.h"
#include <set>

class TwoPointers
{
public:
    /* QUESTION: PAIR SUM - SORTED
    Given an array of integers sorted in ascending order and a target value, return the indexes of any pair of numbers in the array that sum to the target.
    The order of the indexes in the result doesn't matter.if no pair is found, return an empty array.
    */
    std::vector<int> pairSumBruteForce(std::vector<int> lst, int target)
    {
        std::vector<int> res;
        int n = lst.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (lst[i] + lst[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }

    std::vector<int> pairSumSorted(std::vector<int> lst, int target)
    {
        std::vector<int> res;
        int left = 0;
        int right = lst.size() - 1;
        while (left < right)
        {
            int sum = lst[left] + lst[right];
            if (sum == target)
            {
                res.push_back(left);
                res.push_back(right);
                return res;
            }
            else if (sum < target)
            {
                left += 1;
            }
            else
            {
                right -= 1;
            }
        }
        return res;
    }

    /* QUESTION: TRIPLET SUM
    Given an array of integers, return al triplets [a, b, c] such that a + b + c = 0. The solution must not
    contain duplicate triplets. if no such triplet are found, return an empty array.
    */
    std::vector<std::vector<int>> tripletSumBruteForce(std::vector<int> lst)
    {
        std::vector<std::vector<int>> result;
        std::set<std::vector<int>> triplets;
        int n = lst.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (lst[i] + lst[j] + lst[k] == 0)
                    {
                        std::vector<int> triplet = {lst[i], lst[j], lst[k]};
                        std::sort(triplet.begin(), triplet.end());
                        triplets.insert(triplet);
                    }
                }
            }
        }

        for (auto triplet : triplets)
        {
            result.push_back(triplet);
        }
        return result;
    }

    std::vector<std::vector<int>> tripletSumSorted(std::vector<int> lst)
    {
        std::vector<std::vector<int>> result;
        std::sort(lst.begin(), lst.end());
        for (auto i = lst.begin(); i != lst.end(); i++)
        {
            if (*i > 0) // lst only contains possitive numbers cannot sum to 0
            {
                break;
            }
            if (i != lst.begin() && *i == *(i - 1))
            {
                continue;
            }
            std::vector<int> subArr(i + 1, lst.end());
            std::vector<std::vector<int>> allPairsSum = pairSumSortedAllPairs(subArr, -(*i));
            if (!allPairsSum.empty())
            {
                for (auto pair : allPairsSum)
                {
                    pair.insert(pair.begin(), *i);
                    result.push_back(pair);
                }
            }
        }

        return result;
    }

    std::vector<std::vector<int>> pairSumSortedAllPairs(std::vector<int> lst, int target)
    {
        std::vector<std::vector<int>> res;
        int left = 0;
        int right = lst.size() - 1;
        while (left < right)
        {
            int sum = lst[left] + lst[right];
            if (sum == target)
            {
                std::vector<int> pair = {lst[left], lst[right]};
                res.push_back(pair);
                left += 1;
                while (left < right && lst[left] == lst[left - 1])
                {
                    left += 1;
                }
            }
            else if (sum < target)
            {
                left += 1;
            }
            else
            {
                right -= 1;
            }
        }
        return res;
    }

    /* QUESTION: IS PALINDROME VALID:
    Given a string, determine if it's a palindrome after removing all non-alphanumeric characters.
    A character is alphanumeric if it's either a letter or a number.
    */
    bool isPalindromeValid(std::string str)
    {
        int left = 0;
        int right = str.length() - 1;
        while (left < right)
        {
            while (left < right && isalnum(str[left]) == 0)
            {
                left += 1;
            }
            while (left < right && isalnum(str[right]) == 0)
            {
                right -= 1;
            }
            if (str[left] != str[right])
            {
                return false;
            }
            left += 1;
            right -= 1;
        }

        return true;
    }

    /* QUESTION: LARGEST CONTAINER
    You are given an array of numbers, each representing the height of a vertical line on a graph. A container can be formed with any pair of these lines,
    along with the x-axis of the graph. Return the amount of water which the largest container can hold.

    amount of water = min(height[i], height[j]) * (j -i)
    */
    int largestContainerBruteForce(std::vector<int> heights)
    {
        int n = heights.size();
        int maxWater = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int water = std::min(heights[i], heights[j]) * (j - i);
                maxWater = std::max(maxWater, water);
            }
        }

        return maxWater;
    }

    int largestContainer(std::vector<int> heights)
    {
        int maxWater = 0;
        int i = 0, j = heights.size() - 1;
        while (i < j)
        {
            int water = std::min(heights[i], heights[j]) * (j - i);
            maxWater = std::max(maxWater, water);
            if (heights[i] < heights[j])
            {
                i += 1;
            }
            else if (heights[i] > heights[j])
            {
                j -= 1;
            }

            else
            {
                i += 1;
                j -= 1;
            }
        }
        return maxWater;
    }
};

#endif