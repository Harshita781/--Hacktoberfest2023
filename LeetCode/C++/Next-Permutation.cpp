/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void nextPermutation(vector<int> &nums)
{

    int ind1, ind2, i;
    for (i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind1 = i;
            break;
        }
    }
    if (i < 0)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] > nums[ind1])
            {
                ind2 = i;
                break;
            }
        }
        int temp = nums[ind1];
        nums[ind1] = nums[ind2];
        nums[ind2] = temp;

        reverse(nums.begin() + ind1 + 1, nums.end());
    }
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}
int main()
{
    vector<int> nums{1, 2, 3};
    nextPermutation(nums);
    return 0;
}
