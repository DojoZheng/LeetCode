//
//  main.cpp
//  -01TwoSum
//
//  Created by Dojo on 17/2/22.
//  Copyright © 2017年 Dojo. All rights reserved.
//

//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//Example:
//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    long len = nums.size();
    vector<int> result;
    for(int i = 0; i < len; i++){
        int value = target - nums[i];
        for(int j = i + 1; j < len; j++){
            if(nums[j] == value){
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}

vector<int> twoSumMap(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
    //unordered_map VS map
    //unordered_map: 1. need more memory 2. faster
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < numbers.size(); i++) {
        int numberToFind = target - numbers[i];
        
        //if numberToFind is found in map, return them
        if (hash.find(numberToFind) != hash.end()) {
            result.push_back(hash[numberToFind]);
            result.push_back(i);
            return result;
        }
        
        //number was not found. Put it in the map.
        hash[numbers[i]] = i;
    }
    return result;
}

//vector<int> twoSumSort(vector<int> &numbers, int target){
//    
//}

int main(int argc, const char * argv[]) {
    
    return 0;
}
