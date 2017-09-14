/*
Given a sorted array, two integers k and x, find the k closest elements to x 
in the array. The result should also be sorted in ascending order. If there is 
a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104
 */

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - 1;

        // Find the element <= x
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > x) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        while (k > 0) {
            if (right < 0) {
                ++left;
                --k;
            } else if (left >= arr.size()) {
                --right;
                --k;
            } else if (abs(arr[right] - x) > abs(arr[left] - x)) {
                ++left;
                --k;
            } else {
                --right;
                --k;
            }
        }

        vector<int> res;
        for (int i = right + 1; i < left; ++i) {
            res.push_back(arr[i]);
        }

        return res;
    }
};
