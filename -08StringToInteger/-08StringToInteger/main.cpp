//
//  main.cpp
//  -08StringToInteger
//
//  Created by Dojo on 17/2/22.
//  Copyright © 2017年 Dojo. All rights reserved.
//

#include <iostream>
using namespace std;

enum Status{kValid = 0, kInValid};
int g_nStatus = kValid;

enum Status {kInvalid = 0, kValid};
int g_nStatus = kValid;

int myAtoi(string str){
    g_nStatus = kInvalid;
    
    //judge empty
    if(str.empty()) return 0;
    
    //judge space
    int index = 0;
    while(str[index] == ' ' && str[index] != '\0') index++;
    
    //judge '+' '-'
    int indicator = 1;
    if(str[index] == '+') index++;
    else if(str[index] == '-'){
        indicator = -1;
        index++;
    }
    
    //transfer
    long result = 0;
    while(str[index] >= '0' && str[index] <= '9'){
        result = result * 10 + str[index++] - '0';
        if(result * indicator < INT_MIN) return INT_MIN;
        if(result * indicator > INT_MAX) return INT_MAX;
    }
    
    if(str[index] == '\0') g_nStatus = kValid;
    return (int)result * indicator;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
