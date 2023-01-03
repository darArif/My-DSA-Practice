/* *
 * Printing all the unique combinations of non-zero number of elements of an array(repitition allowed) 
 * summing to a given targetSum
 * */

#include<bits/stdc++.h>
using namespace std;

/*This recursive function returns the vector V of the vectors v(combinations summing to the given targetSum)*/
vector<vector<int>> &combs(int indx,
                           int size,
                           int remSum, 
                           int arr[], 
                           vector<int> &v, 
                           vector<vector<int>> &V)
{
    if(remSum==0)
    {
        V.push_back(v);
        return V;
    }
    
    if(indx>=size || remSum<0)
        return V;

    v.push_back(arr[indx]);

    combs(indx, size, remSum-arr[indx], arr, v, V);

    v.pop_back();

    combs(indx+1, size, remSum, arr, v, V);

    return V;
}

int main()
{
    int arr[] = {2, 3, 6, 1};

    vector<int> v;

    vector<vector<int>> V;

    int targetSum = 7;

    vector<vector<int>> rV = combs(0, 4, targetSum, arr, v, V); // rV represents the returned vector of vectors

    for(auto i=rV.begin(); i!=rV.end(); i++)
    {
        for(auto j=(*i).begin(); j!=(*i).end(); j++)
            cout<<*j<<" ";
        cout<<endl;
    }

    return 0;
}
