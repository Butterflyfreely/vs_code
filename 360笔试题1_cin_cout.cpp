#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main() {
    string input;
    int n=0;
    cin >> n;
    //n++;
    int sum = 0;
    int i = 0;
    //vector<int> dp(n + 1, 0);
    //vector<vector<int>> arr(n+1,vector<int>(2,0));
    for (int i = 0; i < n; i++)
    {
        vector<int> a(2,0);
        cin >> a[0] >> a[1];
                if (a[1] != 1)
                {
                    sum += a[0];  
                }
                else {
                    sum = max(sum + a[0], sum * 2);
                }
    }
    cout << sum << endl;
        
}