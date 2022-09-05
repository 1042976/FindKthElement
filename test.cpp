//
// Created by Xiaodong Liu on 9/5/22.
//
#include <unordered_map>
#include "gtest/gtest.h"
#include "main.c"
using namespace std;
class FindKthTest: public ::testing::Test{
protected:
    void SetUp() override{
        n = 10;
        int tmp[10] = {1,2,32,1,4,7,-1,-100,2,0};
        for(int i = 0; i < n; ++i){
            arr[i] = tmp[i];
        }
    }
    int n;
    int arr[10];
};

TEST_F(FindKthTest, FindKthSmallest){
    int k = 5;
    int* res = getKthSmallest(arr, n, k);
    unordered_map<int, int> hashMap;
    unordered_map<int, int> expectedHashMap = {
            {-1, 1},
            {1,2},
            {0,1},
            {-100,1}
    };
    for(int i = 0; i < k; ++i){
        ++hashMap[res[i]];
    }
    EXPECT_EQ(hashMap, expectedHashMap);
}

TEST_F(FindKthTest, FindKthLargest){
    int k = 6;
    int* res = getKthLargest(arr, n, k);
    unordered_map<int, int> hashMap;
    unordered_map<int, int> expectedHashMap = {
            {32, 1},
            {7,1},
            {4,1},
            {2,2},
            {1,1}
    };
    for(int i = 0; i < k; ++i){
        ++hashMap[res[i]];
    }
    EXPECT_EQ(hashMap, expectedHashMap);
}