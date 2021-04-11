//
// Created by Han on 2021/4/2.
//

#ifndef LEETCODE_FINDNUMBERIN2DMATRIX_H
#define LEETCODE_FINDNUMBERIN2DMATRIX_H

#endif //LEETCODE_FINDNUMBERIN2DMATRIX_H

class findNumberIn2DMatrix {

    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        int end_row = matrix.size() - 1, begin_row = 0;
        for (vector<vector<int>>::reverse_iterator it = matrix.rbegin(); it != matrix.rend(); it++) {
            vector<int> n = *it;
            if (n[0] > target)
                end_row--;
        }

        for (vector<vector<int>>::iterator it = matrix.begin(); it != matrix.end(); it++) {
            vector<int> n = *it;
            if (n[matrix.size() - 1] < target)
                begin_row++;
        }

        for (int i = begin_row; i <= end_row; i++) {
            if (findNumberInArray(matrix[i], target)) {
                return true;
            }
        }

        return false;

    }

public:
    bool findNumberInArray(vector<int> &matrix, int target) {
        int pre = 0;
        int post = matrix.size()-1;

        while (pre < post) {
            int mid = (pre + post) / 2;
            if (matrix[mid] == target) {
                return true;
            }
            if (matrix[mid] > target) {
                post = mid - 1;
            } else {
                pre = mid + 1;
            }
        }

        return false;
    }
};