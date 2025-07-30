#ifndef TEST_H
#define TEST_H
#include "../problems/problems.h"
#include "../utils/utils.h"

class Test
{
public:
    // PAIR SUM PROBLEM
    void TestPairSumBruteForce(std::string testcaseFile)
    {
        std::cout << "\nTest Pair Sum Brute Force:\n";
        std::vector<std::vector<int>> testcases = readArraysFromFile(testcaseFile);
        int n = testcases.size();
        std::vector<int> targets = {5, 5, 5, 2, -5};
        for (int i = 0; i < n; i++)
        {
            std::cout << "Test case " << i + 1 << ": ";
            printIntArr(testcases[i]);
            std::cout << "\nTarget: " << targets[i] << "\n";

            std::vector<int> result = twoPointers.pairSumBruteForce(testcases[i], targets[i]);
            std::cout << "Result: ";
            printIntArr(result);
            std::cout << "\n____________________________\n";
        }
    }
    void TestPairSumTwoPointers(std::string testcaseFile)
    {
        std::cout << "\nTest Pair Sum Two Pointer:\n";
        std::vector<std::vector<int>> testcases = readArraysFromFile(testcaseFile);
        int n = testcases.size();
        std::vector<int> targets = {5, 5, 5, 2, -5};
        for (int i = 0; i < n; i++)
        {
            std::cout << "Test case " << i + 1 << ": ";
            printIntArr(testcases[i]);
            std::cout << "\nTarget: " << targets[i] << "\n";

            std::vector<int> result = twoPointers.pairSumSorted(testcases[i], targets[i]);
            std::cout << "Result: ";
            printIntArr(result);
            std::cout << "\n____________________________\n";
        }
    }

    // TRIPLET SUM PROBLEM
    void testTripletSumBruteForce(std::string testcaseFile)
    {
        std::cout << "\nTest Triplet Sum Brute Force:\n";
        std::vector<std::vector<int>> testcases = readArraysFromFile(testcaseFile);
        int n = testcases.size();
        for (int i = 0; i < n; i++)
        {
            std::cout << "Test case " << i + 1 << ": ";
            printIntArr(testcases[i]);

            std::vector<std::vector<int>> result = twoPointers.tripletSumBruteForce(testcases[i]);
            std::cout << "\nResult: ";
            printArrArr(result);
            std::cout << "\n____________________________\n";
        }
    }

    void testTripletSumSorted(std::string testcaseFile)
    {
        std::cout << "\nTest Triplet Sum Sorted:\n";
        std::vector<std::vector<int>> testcases = readArraysFromFile(testcaseFile);
        int n = testcases.size();
        for (int i = 0; i < n; i++)
        {
            std::cout << "Test case " << i + 1 << ": ";
            printIntArr(testcases[i]);

            std::vector<std::vector<int>> result = twoPointers.tripletSumSorted(testcases[i]);
            std::cout << "\nResult: ";
            printArrArr(result);
            std::cout << "\n____________________________\n";
        }
    }

    void testIsPalindromeValid(std::string testcaseFile)
    {
        std::cout << "\nTest Is Palindrome Valid:\n";
        std::vector<std::string> testcases = readStringsFromFile(testcaseFile);
        int n = testcases.size();
        for (int i = 0; i < n; i++)
        {
            std::cout << "Test case " << i + 1 << ": ";
            std::cout << testcases[i];

            bool result = twoPointers.isPalindromeValid(testcases[i]);
            std::cout << "\nResult: " << result;
            std::cout << "\n____________________________\n";
        }
    }

    void testLargestContainerBruteForce(std::string testcaseFile)
    {
        std::cout << "\nTest Largest Container Brute Force:\n";
        std::vector<std::vector<int>> testcases = readArraysFromFile(testcaseFile);
        int n = testcases.size();
        for (int i = 0; i < n; i++)
        {
            std::cout << "Test case " << i + 1 << ": ";
            printIntArr(testcases[i]);

            int result = twoPointers.largestContainerBruteForce(testcases[i]);
            std::cout << "\nResult: " << result;
            std::cout << "\n____________________________\n";
        }
    }

    void testLargestContainerOptimized(std::string testcaseFile)
    {
        std::cout << "\nTest Largest Container Optimized:\n";
        std::vector<std::vector<int>> testcases = readArraysFromFile(testcaseFile);
        int n = testcases.size();
        for (int i = 0; i < n; i++)
        {
            std::cout << "Test case " << i + 1 << ": ";
            printIntArr(testcases[i]);

            int result = twoPointers.largestContainer(testcases[i]);
            std::cout << "\nResult: " << result;
            std::cout << "\n____________________________\n";
        }
    }

    void testPairSumUnsortedTwoPass(std::string testcaseFile)
    {
        std::cout << "\nTest Pair Sum Unsorted Two Pass:\n";
        std::vector<std::vector<int>> testcases = readArraysFromFile(testcaseFile);
        int n = testcases.size();
        std::vector<int> targets = {3};
        for (int i = 0; i < n; i++)
        {
            std::cout << "Test case " << i + 1 << ": ";
            printIntArr(testcases[i]);

            std::vector<int> result = hashmaps.pairSumUnsortedTwoPass(testcases[i], targets[i]);
            std::cout << "\nResult: ";
            printIntArr(result);
            std::cout << "\n____________________________\n";
        }
    }

    void testPairSumUnsorted(std::string testcaseFile)
    {
        std::cout << "\nTest Pair Sum Unsorted:\n";
        std::vector<std::vector<int>> testcases = readArraysFromFile(testcaseFile);
        int n = testcases.size();
        std::vector<int> targets = {3};
        for (int i = 0; i < n; i++)
        {
            std::cout << "Test case " << i + 1 << ": ";
            printIntArr(testcases[i]);

            std::vector<int> result = hashmaps.pairSumUnsorted(testcases[i], targets[i]);
            std::cout << "\nResult: ";
            printIntArr(result);
            std::cout << "\n____________________________\n";
        }
    }

    void testVerifySudokuBoard(std::string testcaseFile)
    {
        std::cout << "\nTest Verify Sudoku Board Naive:\n";
        std::vector<std::vector<int>> testcase = readArraysFromFile(testcaseFile);
        std::cout << "Test case " << ":\n";
        drawSudokuBoard(testcase);

        bool result = hashsets.verifySudokuBoard(testcase);
        std::cout << "\nResult: ";
        if (result == true)
        {
            std::cout << "VALID";
        }
        else
        {
            std::cout << "INVALID";
        }
        std::cout << "\n____________________________\n";
    }

    void testZeroStripingHashsets(std::string testcaseFile)
    {
        std::cout << "\nTest Zero Striping Hashsets:\n";
        std::vector<std::vector<int>> testcase = readArraysFromFile(testcaseFile);
        std::cout << "Test case:\n";
        printMatrix(testcase);
        std::cout << "\n";
        hashsets.zeroStrippingHashSets(testcase);
        std::cout << "\nResult:\n";
        printMatrix(testcase);
        std::cout << "\n____________________________\n";
    }

    void testZeroStripingInPlace(std::string testcaseFile)
    {
        std::cout << "\nTest Zero Striping Hashsets:\n";
        std::vector<std::vector<int>> testcase = readArraysFromFile(testcaseFile);
        std::cout << "Test case:\n";
        printMatrix(testcase);
        std::cout << "\n";
        hashsets.zeroStrippingInplace(testcase);
        std::cout << "\nResult:\n";
        printMatrix(testcase);
        std::cout << "\n____________________________\n";
    }

    void testLinkedListReversal(std::string testcaseFile)
    {
        std::cout << "\nTest Linked List Reversal:\n";
        ListNode *head = linkedList.createSinglyLinkedList(testcaseFile);
        std::cout << "Test case: ";
        linkedList.printSinglyLinkedList(head);
        std::cout << "Result: ";
        linkedList.printSinglyLinkedList(linkedList.linkedListReversal(head));
        std::cout << "____________________________\n";
    }

    void testLinkedListReversalRecursive(std::string testcaseFile)
    {
        std::cout << "\nTest Linked List Reversal Recursive:\n";
        ListNode *head = linkedList.createSinglyLinkedList(testcaseFile);
        std::cout << "Test case: ";
        linkedList.printSinglyLinkedList(head);
        std::cout << "Result: ";
        linkedList.printSinglyLinkedList(linkedList.linkedListReversalRecursive(head));
        std::cout << "____________________________\n";
    }

    void testLinkedListRemoveKthLastNode(std::string testcaseFile, int k)
    {
        std::cout << "\nTest Linked List Remove Kth Last Node:\n";
        ListNode *head = linkedList.createSinglyLinkedList(testcaseFile);
        std::cout << "Test case: ";
        linkedList.printSinglyLinkedList(head);
        std::cout << "Result: ";
        linkedList.printSinglyLinkedList(linkedList.removeKthLastNode(head, k));
        std::cout << "____________________________\n";
    }

private:
    TwoPointers twoPointers;
    Hashmaps hashmaps;
    Hashsets hashsets;
    LinkedListProblems linkedList;
};

#endif