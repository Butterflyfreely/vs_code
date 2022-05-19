#include <bits/stdc++.h>

using namespace std;
int main(){
    int nGrp;
    cin>>nGrp;
    while (nGrp--){
        int cntLine=6;
        unordered_map<string,vector<int>> country_mp;
        while (cntLine--){
            string name;
            cin>>name;
            // int points,inP,outP;
            // >>points>>inP>>outP;
            vector<int> pp(3);
            for (auto& i:pp)
                cin>>i;
            country_mp[name]=pp;
        }
        cntLine=3;
        while (cntLine--){
            string nameA,nameB;
            cin>>nameA>>nameB;
            int pointA,pointB;
            cin>>pointA>>pointB;
            auto itA=country_mp.find(nameA);
            auto itB=country_mp.find(nameB);
            //itA and itB shouldn't be nullptr
            itA->second[1]+=pointA;
            itA->second[2]+=pointB;
            itB->second[1]+=pointB;
            itB->second[2]+=pointA;
            if (pointA>pointB){
                itA->second[0]+=3;
            }else if (pointA == pointB){
                itA->second[0]+=1;
                itB->second[0]+=1;
            }else{
                itB->second[0]+=3;
            }
        }
        //0 1 2 3
        //idx p inp outp
        vector<vector<int>> data(6,vector<int>(4,0));
        string idx2name[6];
        int idx=0;
        for (auto grpPair:country_mp){
            string name=grpPair.first;
            idx2name[idx]=name;
            data[idx][0]=idx;
            data[idx][1]=grpPair.second[0];
            data[idx][2]=grpPair.second[1];
            data[idx][3]=grpPair.second[2];
            idx++;
        }
        sort(data.begin(),data.end(),[idx2name](vector<int>&a,vector<int>&b){
            if (a[1]==b[1]){
                int cleanPa=a[2]-a[3],cleanPb=b[2]-b[3];
                if (cleanPa==cleanPb){
                    return idx2name[a[0]]<idx2name[b[0]];
                }
                return cleanPa>cleanPb;
            }
            return a[1]>b[1];
        });
        for (auto& iv:data){
            cout<<idx2name[iv[0]]
                <<" "<<iv[1]
                <<" "<<iv[2]
                <<" "<<iv[3]
                <<endl;
        }
        cout<<"END"<<endl;
    }
 
    system("pause");

    return 0;
}
