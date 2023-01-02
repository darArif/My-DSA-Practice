/*Printing Subsequences having sum equal to k) of an array using recursion and vectors*/

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
void subSeq(int size, T arr[], int indx, vector<T> &subs, int givenSum)
{
    static int sum = 0;

    if(indx==size) //including empty subsequences as well
    {
        if(sum == givenSum)
        {
            printSubs<T>(subs);
            
        }
        return;
    }

    subs.push_back(arr[indx]);
    sum += arr[indx];

    subSeq(size, arr, indx+1, subs, givenSum);
    
    subs.pop_back();
    sum -= arr[indx];

    subSeq(size, arr, indx+1, subs, givenSum);
}

int main()
{
    int arr[10] = {-10, -7, -6, -3, -1, 0, 2, 4, 8, 9};

    vector<int> subs;

    subSeq<int>(10, arr, 0, subs, 5);

    return 0;
}