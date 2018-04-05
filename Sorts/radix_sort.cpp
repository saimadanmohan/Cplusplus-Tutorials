#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void sortByMod(vector<int>& arr,int div){
    vector<int> count(10,0);
    vector<int> temp(arr.size());
    for(int i = 0;i<arr.size();i++){
        int mod = (arr[i]/div)%10;
        count[mod]++;
    }
    for(int i = 1;i<count.size();i++)
        count[i] += count[i-1];
    
    for(int i = arr.size() - 1;i>=0;i--){
        int mod = (arr[i]/div)%10;
        int pos = count[mod]-1;
        temp[pos] = arr[i];
        count[mod]--;
    }
    arr.clear();
    arr.insert(arr.end(),temp.begin(),temp.end());
}

void radixSort(vector<int>& arr){
    int maxVal = arr[0];
    for(int i = 0;i<arr.size();i++){
        maxVal = max(maxVal,arr[i]);
    }
    
    for(int div = 1;maxVal/div > 0 ; div *= 10){
        sortByMod(arr,div);
    }
}

int main() {
    int n;
    cin>>n;
    if(n){
        vector<int> arr(n);
        for(int i = 0;i<n;i++)
            cin>>arr[i];
        radixSort(arr);
        cout<<"[";
        for(int i = 0;i<n;i++){
            if(i != n-1)
                cout<<arr[i]<<",";
            else
                cout<<arr[i]<<"]";
        }
        cout<<endl;
    }
    return 0;
}
