/*Printing Subsequences of an array using recursion and vectors*/

#include<bits/stdc++.h>
using namespace std;

template<class T>
void printSubs(vector<T> &subs)
{
    for(auto i=subs.begin(); i!=subs.end(); i++)
        cout<<*i;
    cout<<endl;
}

template<class T>
void subSeq(int size, T arr[], int indx, vector<T> &subs)
{
    if(indx==size) //including empty subsequences as well
    {
        printSubs<T>(subs);
        return;
    }

    subs.push_back(arr[indx]);

    subSeq(size, arr, indx+1, subs);
    
    subs.pop_back();

    subSeq(size, arr, indx+1, subs);
}

int main()
{
    char arr[4] = {'a', 'b', 'c', 'd'};

    vector<char> subs;

    subSeq<char>(4, arr, 0, subs);

    return 0;
}