//
//  main.cpp
//  -15ThreeSum
//
//  Created by Dojo on 17/2/22.
//  Copyright © 2017年 Dojo. All rights reserved.
//



//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
//Note: The solution set must not contain duplicate triplets.
//
//For example, given array S = [-1, 0, 1, 2, -1, -4],
//
//A solution set is:
// [
// [-1, 0, 1],
// [-1, -1, 2]
// ]

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ret;
    int size = (int)nums.size();
    
    if (size < 3) return ret;
    
    //sort
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < size - 2; i++) {
        int j = i + 1;
        int k = size - 1;
        while (j < k) {
            if (nums[i] + nums[j] + nums[k] < 0) {
                j++;
            } else if(nums[i] + nums[j] + nums[k] > 0){
                k--;
            } else {
                ret.push_back({nums[i], nums[j], nums[k]});
                ++j;
                --k;
                //avoid duplication
                while (nums[j] == nums[j - 1]) j++;
                while (nums[k] == nums[k + 1]) k--;
            }
        }
        while (nums[i] == nums[i + 1] && i < size - 2) i++;
    }
    return ret;
}

int main(int argc, const char * argv[]) {


    return 0;
}
