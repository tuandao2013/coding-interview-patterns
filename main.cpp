#include <iostream>
#include "test/test.h"

using namespace std;

static std::string pairSumTestcases = "./test/testcases/two-pointers/pair-sum-testcases.txt";
static std::string tripletSumTestcases = "./test/testcases/two-pointers/triplet-sum-testcases.txt";
static std::string isPalindromeTestcases = "./test/testcases/two-pointers/is-palindrome-testcases.txt";
static std::string isLargestContainerTestcases = "./test/testcases/two-pointers/largest-container-testcases.txt";
static std::string pairSumUnsortedTwoPassTestcases = "./test/testcases/hashmaps/pair-sum-unsorted-testcases.txt";
static std::string verifySudokuBoardTestcase = "./test/testcases/hashsets/verify-sudoku-board-testcases.txt";
static std::string zeroStripingTestcase = "./test/testcases/hashsets/zero-striping-testcases.txt";
static std::string linkedListReversalTestcase = "./test/testcases/linked-list/reverse-linked-list.txt";
static std::string linkedListRemoveKthLastNodeTestcase = "./test/testcases/linked-list/remove-kth-last-node.txt";

int main()
{
    Test test;
    // test.TestPairSumBruteForce(pairSumTestcases);
    // test.TestPairSumTwoPointers(pairSumTestcases);
    // test.testTripletSumSorted(tripletSumTestcases);
    // test.testIsPalindromeValid(isPalindromeTestcases);
    // test.testLargestContainerBruteForce(isLargestContainerTestcases);
    // test.testLargestContainerOptimized(isLargestContainerTestcases);
    // test.testPairSumUnsortedTwoPass(pairSumUnsortedTwoPassTestcases);
    // test.testPairSumUnsorted(pairSumUnsortedTwoPassTestcases);
    // test.testVerifySudokuBoard(verifySudokuBoardTestcase);
    // test.testZeroStripingHashsets(zeroStripingTestcase);
    // test.testZeroStripingInPlace(zeroStripingTestcase);
    // test.testLinkedListReversal(linkedListReversalTestcase);
    // test.testLinkedListReversalRecursive(linkedListReversalTestcase);
    test.testLinkedListRemoveKthLastNode(linkedListRemoveKthLastNodeTestcase, 2);

    return 0;
}