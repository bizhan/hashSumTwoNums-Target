#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//Note: unorder_map is container store elements in no particular order.
//      It is similar to map, but it uses a hash table to store elements
//      for faster access to element
//Note: This algorithm stores <targetSum - arr[x], x> in unordered_map
//      Thing about this, you store value of what will match with current
//      element and index of that element.
//Note: Created a non const vector, sorted it passed to search as const array


class PairWithTargetSum {
public:
  static pair<int, int> search(const vector<int> &arr, int targetSum) {
    unordered_map<int,int> nums;
    for(int i =0; i< arr.size(); i++){
      if (nums.find(targetSum - arr[i]) != nums.end()){
        return make_pair(nums[targetSum - arr[i]],i);
      }
      else nums[targetSum - arr[i]] = i;
    }
  }
};

int main() {
  std::cout << "Hello World!\n";
  int targetSum = 6;
  vector<int> arr = {1, 2, 3, 4, 5};
  sort(arr.begin(), arr.end());
  auto result = PairWithTargetSum::search(arr, targetSum);
  cout<<result.first<<","<<result.second<<endl;
}