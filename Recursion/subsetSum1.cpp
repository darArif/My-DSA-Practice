/*Printing the sums of subsets of an integer array in increasing order*/

#include<bits/stdc++.h>
using namespace std;

void subSets(int size, int indx, int sum,vector<int> &arr, vector<int> &v)
{
    if(indx >= size)
    {
        v.push_back(sum);
        return;
    }

    //Picking arr[indx]
    subSets(size, indx+1, sum+arr[indx], arr, v);

    //Not picking arr[indx]
    subSets(size, indx+1, sum, arr, v);
}

int main()
{
    vector<int> arr = {4, 1, 3, 2, 8, 6};

    vector<int> v;

    subSets(6, 0, 0, arr, v);

    sort(v.begin(), v.end());

    for(auto i=v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";

    return 0;
}