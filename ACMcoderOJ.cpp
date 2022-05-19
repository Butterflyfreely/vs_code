#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main() {

    string input;
    int n;
    cin>>n;
    int sum=0;
    vector<int> dp(n+1,0);
    while (getline(cin, input)) {
        if (input.size() > 0) {
            stringstream stringin(input);
            int num;
            vector<int> a;
            while (stringin >> num) {
                a.push_back(num);
            }
            sum+=a[0];

        }
    }
    cout<<sum<<endl;

}

// #include<iostream>
// #include<sstream>
// #include<string>
// #include<vector>

// using namespace std;

// void shuru(vector<int>& a)
// {
//   string input;
//   while(getline(cin,input))
//   {
//     stringstream string_input(input);
//     int num;
//     if(input.size()>0)
//     {
//       while(string_input>>num)
//       {
//         a.push_back(num);
//       }
//     }   
//   }
// }

// void shuchu(vector<int>& a)
// {
//     cout<<"shurishujuwei:  "<<endl;
//     for(int i=0;i<a.size();i++)
//     {
//         cout<<a[i]<<" "<<endl;
//     }
// }


// int main()
// {
//   vector<int> a;
//   cout<<"qingshuru: "<<endl;
//   shuru(a);
//   cout<<"shuchu: "<<endl;  
//   shuchu(a);

//   return 0;
// }