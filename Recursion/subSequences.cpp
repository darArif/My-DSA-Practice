/*Printing All the non-empty 2^n - 1 subsequences of an array using Tree Recursion*/

#include<iostream>
using namespace std;

/*Fxn for printing subsequences*/
template<class T>
void print(T sub[], int size)
{
    for(int i=0; i<size; i++)
        cout<<sub[i];
    cout<<endl;
}

/**
 * function for determining subsequences
 * ci represents current index of the original array ar
 * cssi represents current index of the changing subsequence array sub
 * 
**/
template<class T>
void subSqnc(int n, T ar[], int ci, T sub[], int cssi)
{
    if(ci==n && cssi != 0) //For including empty subsequence as well, remove cssi != 0 condition
    {

        print<T>(sub, cssi);
        return;
    }
    else if(ci==n && cssi == 0) //For including empty subsequence as well, do not include this else if statement
        return;

    sub[cssi] = ar[ci];

    subSqnc(n, ar, ci+1, sub, cssi+1);
    subSqnc(n, ar, ci+1, sub, cssi);
}


int main()
{
    char ar[4] = {'a', 'b', 'c', 'd'};

    char sub[4];


    subSqnc<char>(4, ar, 0, sub, 0);

    return 0;
}

