#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> &combs(
    int size,
    int arrIndx,
    int remSum,
    vector<int> &arr,
    vector<int> &v,
    vector<vector<int>> &V)
{
    if(remSum == 0)
    {
        V.push_back(v);
        return V;
    }
    for(int i=arrIndx; i<size; i++)
    {
        if(i>arrIndx && arr[i]==arr[i-1])  //Since the array has been already sorted
            continue;
        if(arr[i]>remSum)
            break;
        v.push_back(arr[i]);
        combs(size, i+1, remSum-arr[i],arr, v, V);
        v.pop_back();
    }
    return V;
}

int main()
{
    vector<int> arr = {1, 2, 3, 6, 3, 4, 1, 5, 6};
    sort(arr.begin(), arr.end());
    vector<int> v;
    vector<vector<int>> V;
    
    int targetSum = 6;
    vector<vector<int>> rV = combs(9, 0, targetSum, arr, v, V);

    for(auto i=rV.begin(); i!=rV.end(); i++)
    {
        for(auto j=(*i).begin(); j!=(*i).end(); j++)
            cout<<*j<<" ";
        cout<<endl;
    }

    return 0;
}
