#include <iostream>
#include <vector>
#include <queue>
using namespace std;



// class Solution {
// public:
//     void merge(int* A,int m,int* B,int n) {
//         int p1=n-1,p2=0,p=0;
        
//         for(int i=n;i<m+n;i++)
//         {
//             A[i]=A[i-n];
//         }
        
//         while(1)
//         {
//             if(A[p1]>=B[p2])
//             {
//                 A[p]=B[p2];
//                 p2++;
//                 p++;
//             }
//             else 
//             {
//                 A[p]=A[p1];
//                 p1++;
//                 p++;
//             }
            
//             if(p1==m+n-1&&p2==n-1)break;
//         }
        
        
//     }
// };

void aaa(int* a)
{
    cout<<a[2];
}

int main() {

    //vector<int> vec={5,7,7,8,8,10};
    int A[]={4,5,6},B[]={1,2,3};
    
    aaa(A);

    //Solution s1;
    //s1.merge(A,3,B,3);

    system("pause"); 
    return 0;
}


