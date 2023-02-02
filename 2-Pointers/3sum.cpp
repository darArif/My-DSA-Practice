#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> & findTriplets(vector<int> &ar, vector<vector<int>> &V)
{
    for(int i=0; i<ar.size(); i++)
    {
        if(i==0 || ar[i]!=ar[i-1])
            

        {int low = i+1, high = ar.size()-1;

        while(low < high)
        {
            if(ar[low]+ar[high] < -ar[i])
                low++;
            else if(ar[low]+ar[high] > -ar[i])
                high--;
            else
            {
                vector<int> v = {ar[i], ar[low], ar[high]};
                V.push_back(v);
                low++;
                high--;
                while(ar[low]==ar[low-1] && ar[high]==ar[high+1])
                {
                    low++;
                    high--;
                }
                // while(low<high && ar[low]==ar[low+1]) 
                //     low++;
                // while(low<high && ar[high]==ar[high-1])
                //     high--;
                // low++;
                // high--;
            }
        }
        
    } }
    return V;
}

int main()
{
    vector<int> ar = {-2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 3};
    sort(ar.begin(), ar.end());
    vector<vector<int>> V;
    findTriplets(ar, V);
    for(auto i=V.begin(); i!=V.end(); i++)
    {
        for(auto j=(*i).begin(); j!=(*i).end(); j++)
            cout<<*j<<" ";
        cout<<endl;
    }
}