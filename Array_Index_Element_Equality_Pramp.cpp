#include <iostream>
#include <vector>

using namespace std;

int indexEqualsValueSearch2(const vector<int> &a,int low,int high){
  if(low > high)
    return -1;
  int mid = low + (high-low)/2;
  if(a[mid] == mid){
    int index = indexEqualsValueSearch2(a,low,mid-1);
    if(index == -1)
      return mid;
    else {
      return index;
    }
  }else if(a[mid] > mid){
    high = mid - 1;
  }else{
    low = mid + 1;
  }
  int index = indexEqualsValueSearch2(a,low,high);
  return index;
} 


int indexEqualsValueSearch(const vector<int> &arr) 
{
  int low = 0;
  int high = arr.size() - 1;
  while(low <= high){
    int mid = low+(high-low)/2;
    if(arr[mid] < mid)
      low = mid + 1;
    else if(arr[mid] == mid && (low == 0 || arr[low-1]<low-1))
      return mid;
    else
      high = mid - 1;
  }
  return -1;
  //return indexEqualsValueSearch2(arr,0,arr.size()-1);
}

int main() {
  //log^2(N)
  return 0;
}