#include "q1.h"
#include <iostream>
#include <gtest/gtest.h>
#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;

vector<int> Solution::twoSum(vector<int>& nums, int target) {
    int desirable;
    vector<int> result;
    unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numMap.contains(complement)) { 
            return {numMap[complement], i};
        }
        numMap[nums[i]]=i;
    }
    return result;
}

int main(int argc, char **argv) {
    // CUSTOM INPUT: CUSTOM VALUES
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution sol;
    vector<int> output = sol.twoSum(nums, target);

    // Print the output
    std::cout << "Output: ";
    for (int idx : output) {
        std::cout << idx << " ";
    }
    std::cout << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}

// Test case 1: Basic case with a valid solution
TEST(TwoSumTest, BasicTest1) {
    Solution sol;
    std::vector<int> nums1 = {2, 7, 11, 15};
    std::vector<int> result1 = sol.twoSum(nums1, 9);
    ASSERT_EQ(result1.size(), 2);   // Expect exactly 2 elements in the result
    EXPECT_EQ(result1[0], 0);       // The first index should be 0
    EXPECT_EQ(result1[1], 1);       // The second index should be 1
}

// Test case 2: Another valid case with different numbers
TEST(TwoSumTest, BasicTest2) {
    Solution sol;
    std::vector<int> nums2 = {3, 2, 4};
    std::vector<int> result2 = sol.twoSum(nums2, 6);
    ASSERT_EQ(result2.size(), 2);
    EXPECT_EQ(result2[0], 1);       // The first index should be 1
    EXPECT_EQ(result2[1], 2);       // The second index should be 2
}

// Test case 3: Yet another case
TEST(TwoSumTest, BasicTest3) {
    Solution sol;
    std::vector<int> nums3 = {3, 3};
    std::vector<int> result3 = sol.twoSum(nums3, 6);
    ASSERT_EQ(result3.size(), 2);
    EXPECT_EQ(result3[0], 0);       // The first index should be 0
    EXPECT_EQ(result3[1], 1);       // The second index should be 1
}