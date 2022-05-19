#include<iostream>
//#include<string>  
#include<queue>
#include<vector>
#include<unordered_map>

using namespace std;
int aaa=0;

void QuickSort(int R[], int lo, int hi)
{
    int i = lo, j = hi;
    int temp;
    if (i < j)
    {
        temp = R[i];
        while (i != j)
        {
            while (j > i && R[j] > temp)j--;
            R[i] = R[j];
            while (i < j && R[i] < temp)i++;
            R[j] = R[i];
        }
        R[i] = temp;
        aaa++;
        QuickSort(R, lo, i - 1);
        QuickSort(R, i+1, hi);
    }
}


int main()
{
    //solution s1;
    int R[]={25,34,7,32,24,48,11};
    int lo = 0, hi =sizeof(R)/sizeof(R[0])-1;
    QuickSort(R,lo,hi );
    cout << aaa<<" ";
    // for (int k = 0; k <= hi; k++)
    // {
    //     cout << aaa<<R[k]<<" ";
    // } 

    system("pause");
    return 0; 
}

