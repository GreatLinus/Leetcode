//
// Created by Han on 2021/4/1.
//

#include <vector>
#include<iostream>
#include <string>
#include <iterator>
#include <set>

#ifndef LEETCODE_FINDREPEATNUMBER_3_H
#define LEETCODE_FINDREPEATNUMBER_3_H

using namespace std;

class findRepeatNumber_3{
public:
    int findRepeatNumber(vector<int>& nums) {
        set<int> s ;
        for(vector<int>::iterator it = nums.begin(); it != nums.end();++it){

            int num = *it;
            if(s.find(num) !=  s.end())
                return num;
            s.insert(num);

        }

        return 0;


    }
};


#endif //LEETCODE_FINDREPEATNUMBER_3_H
