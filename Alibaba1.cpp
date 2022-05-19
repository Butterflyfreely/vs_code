// 本题为考试多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <cstdio>

using namespace std;

struct Mes{
    int year;
    int month;
    int day;
    string Ifo;
};
Mes mes[10000];

//添加记录
void Add()
{
    // isExsist(year,month,day,ifo)
    // {
    //     for(int i=0;i<mes.size();i++)
    //     {
    //         if()
    //     }
    // }
    for(int i=0;i<4;i++)
    {
        int a=0,b=0,c=0;
        string d="";
        cin>>a;
        if(2022<=a&&a<=9999)
        {
            mes[i].year=a;
        }        
        else{
            cout<<"error"<<endl;
        }

        cin>>b;
        if(1<=b&&b<=12)
        {
            mes[i].month=b;
        }
        else{
            cout<<"error"<<endl;
        }

        cin>>c;
        if(b==2&&1<=c&&c<=28||1<=c&&b%2==0&&c<=30&&b!=2||1<=c&&b%2==1&&c<=31)
        {
            mes[i].day=c;
        }      
        else{
            cout<<"error"<<endl;
        }

        cin>>d;
        mes[i].Ifo=d;

        cout<<"done"<<endl;

    }
}

//查询信息数量
int Ifo_num()
{
    for(int i=0;i<10000;i++)
    {
        if()
    }
}

//查询信息日期
string Ifo_date()
{
    
}



int main(){
    //freopen("1.in","r",stdin);
    int sele=0;
    int N=0;
    cin>>N;
    
    while(N--)
    {
        cin>>sele;
        switch(sele)
        {
            case 1:
            Add();
            case 2:
            Ifo_num();
            case 3:
            Ifo_date();                
        }
    }
    
    
    
    // int n,ans = 0;
    // cin >> n;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         int x; scanf("%d",&x);
    //         ans += x;
    //     }
    // }
    // cout << ans << endl;
    return 0;
}