/*Printing Any One Subsequence(having sum equal to k) of an array using recursion and vectors*/

#include<bits/stdc++.h>
using namespace std;

template<class T>
void printSubs(vector<T> &subs)
{
    for(auto i=subs.begin(); i!=subs.end(); i++)
        cout<<*i<<" ";
    cout<<endl;
}

template<class T>
bool subSeq(int size, T arr[], int indx, vector<T> &subs, int givenSum)
{
    static int sum = 0;

    if(indx==size) //including empty subsequences as well
    {
        if(sum == givenSum)
        {
            printSubs<T>(subs);
            return true;
            
        }
        return false;
    }

    subs.push_back(arr[indx]);
    sum += arr[indx];

    if( subSeq(size, arr, indx+1, subs, givenSum)==true )
        return true;
    
    subs.pop_back();
    sum -= arr[indx];

    if( subSeq(size, arr, indx+1, subs, givenSum)==true )
        return true;

    return false;
}

int main()
{
    int arr[10] = {-10, -7, -6, -3, -1, 0, 2, 4, 8, 9};

    vector<int> subs;

    subSeq<int>(10, arr, 0, subs, 5);

    return 0;
}