#include <bits/stdc++.h>

class Solution {
public:
  int minJumps(int arr[], int n) {
    // if the first element of the array is zero then we can't jump any further
    // hence return -1
    if (arr[0] == 0)
      return -1;

    // if the array is only of size 1 or is empty i.e. size 0
    if (n <= 1)
      return 0;

    // jumps is the number of jumps already taken, steps is the number of steps
    // we have remaining that we can take and maxReach is the max index we can
    // reach from the current index
    int jumps = 1, steps = arr[0], maxReach = arr[0];

    // Traverse the array from the first position because we have already
    // processed the zeroth index
    for (int i = 1; i < n; i++) {
      // if we have reached the last index of the array return the number of
      // jumps required to do so
      if (i == n - 1)
        return jumps;

      // Update the maxReach to the to the max index we can reach with the
      // numbers that lie between the previous index where we begun till where
      // we can reach till
      maxReach = std::max(maxReach, i + arr[i]);
      // since we have taken a step to reach the index decrement it
      steps--;
      if (steps == 0) {
        // if we have zero steps remaining that means we have completed a jump
        // so increment the number of jumps
        jumps++;

        // if the maxReach is less than the index that means we have already
        // crossed the index until which we could reach by taking all the
        // possible jumps therefore return -1
        if (i >= maxReach)
          return -1;
        // reinitialize the steps if maxReach hasn't been reached yet
        steps = maxReach - i;
      }
    }
    return -1;
  }
};

int main() {
  int n, i, j;
  std::cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    std::cin >> arr[i];
  Solution obj;
  std::cout << obj.minJumps(arr, n) << std::endl;
  return 0;
}

