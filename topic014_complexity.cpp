/*
 * Topic 14: Time & Space Complexity Analysis (Big-O Notation)
 * Problem Set 14: Pair Sum Analysis (Brute Force vs Two-Pointer)
 * 
 * Requirements:
 * 1. Implement Brute Force pair search: O(N^2) Time | O(1) Space.
 * 2. Implement Two-Pointer pair search with std::sort: O(N log N) Time | O(1) Space.
 * 3. Demonstrate both functions on test vectors in main().
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool hasPairBruteForce(const vector<int>& arr, int target);
bool hasPairTwoPointer(vector<int> arr, int target);

int main()
{
    vector<int> arr = {10, 15, 3, 7};
    int target = 17;

    if(hasPairBruteForce(arr, target))
        cout << "hasPairBruteForce" << endl;
    
    if(hasPairTwoPointer(arr, target))
        cout << "hasPairTwoPointer" << endl;

    return 0;
}

bool hasPairBruteForce(const vector<int>& arr, int target)  // has Time Complexity: O(N^2), Space Complexity: O(1)
{
    for(int i=0; i<arr.size()-1; ++i)
    {
        for (int j=i+1; j<arr.size(); ++j)
        {
            if(arr[i] + arr[j] == target)
                return true;
        }
    }
    return false;
}

bool hasPairTwoPointer(vector<int> arr, int target)     // has Time Complexity: O(N log N), Space Complexity: O(1)
{
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == target)
            return true;
        else if (sum < target)
            left++;
        else
            right--;
    }

    return false;
}