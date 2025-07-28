#ifndef HASHMAPS_H
#define HASHMAPS_H

#include "libs.h"
#include <unordered_map>

class Hashmaps
{
public:
    /*QUESTION: PAIR SUM UNSORTED
    Given an array of integers, return the indexes of any two numbers that add up to a target.
    The order of the indexes in the result doesn't matter. if no pair is found, return an empty array.
    */
    std::vector<int> pairSumUnsortedTwoPass(std::vector<int> lst, int target)
    {
        std::vector<int> result;
        std::unordered_map<int, int> numMap;
        int n = lst.size();
        for (int i = 0; i < n; i++)
        {
            numMap[lst[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            int complement = target - numMap[i];
            if (numMap.count(complement) != 0 && numMap[complement] != i)
            {
                result.push_back(i);
                result.push_back(numMap[complement]);
                return result;
            }
        }
        return result;
    }

    std::vector<int> pairSumUnsorted(std::vector<int> lst, int target)
    {
        std::vector<int> result;
        std::unordered_map<int, int> numMap;
        int n = lst.size();
        for (int i = 0; i < n; i++)
        {
            int complement = target - lst[i];
            if (numMap.count(complement) != 0)
            {
                result.push_back(numMap[complement]);
                result.push_back(i);
                return result;
            }
            numMap[lst[i]] = i;
        }
        return result;
    }
};

#endif