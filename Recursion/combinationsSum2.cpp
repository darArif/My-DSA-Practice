#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> &combs(
    int size,
    int arrIndx,
    int combIndx,
    int remSum,
    vector<int> &arr,
    vector<int> &v,
    vector<vector<int>> &V,
    int map[])
{
    map[arr[arrIndx]] = 1;
    if(remSum == 0)
    {
        V.push_back(v);
        return V;
    }
    if(arrIndx >= size || remSum < 0)
        return V;

    v.push_back(arr[arrIndx]);


    combs(size, arrIndx+1, combIndx+1, remSum-arr[arrIndx], arr, v, V, map);

    v.pop_back();

    v.push_back(arr[arrIndx+1]);

    
        if(map[arr[arrIndx+1]] == 0)
            combs(size, arrIndx+1, combIndx, remSum-arr[arrIndx+1], arr, v, V, map);
    

    return V;
}

int main()
{
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    sort(arr.begin(), arr.end());
    vector<int> v;
    vector<vector<int>> V;
    int map[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int targetSum = 8;
    vector<vector<int>> rV = combs(7, 0, 0, targetSum, arr, v, V, map);

    for(auto i=rV.begin(); i!=rV.end(); i++)
    {
        for(auto j=(*i).begin(); j!=(*i).end(); j++)
            cout<<*j<<" ";
        cout<<endl;
    }

    return 0;
}
