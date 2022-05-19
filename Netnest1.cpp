#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

struct Team
{
    string name;
    int point;
    int goals_for;
    int goals_against;
};
struct Match
{
    string name0;
    string name1;
    int gaols_for_name0;
    int gaols_for_name1;
};
Team team[6];
Match match[3];
unordered_map<string, int> map;

void shuru_team(unordered_map<string, int>& map)
{
    for (int i = 0; i <6; i++)
    {
        string a;
        int b=0;
        cin >> a;
        team[i].name = a;
        map[a] = i;
        cin >> b;
        team[i].point = b;
        cin >> b;
        team[i].goals_for = b;
        cin >> b;
        team[i].goals_against = b;    
    }    
    //cout << team[0].name;
}
void shuru_match()
{
    for (int i=0;i<3;i++)
    {
        int b; string a;
        cin >> a;
        match[i].name0 = a;
        cin >> a;
        match[i].name1 = a;
        cin >> b;
        match[i].gaols_for_name0 = b;
        cin >> b;
        match[i].gaols_for_name1 = b;
    }

}


void jifen(unordered_map<string, int> map)
{
    for (int i = 0; i < 3; i++)
    {
        //team[i]
        if (match[i].gaols_for_name0> match[i].gaols_for_name1)
        {
            int k;
            k = map[match[i].name0];
            team[k].point += 3;
            team[k].goals_for+= match[i].gaols_for_name0;
            team[k].goals_against+= match[i].gaols_for_name1;
            k = map[match[i].name1];
            team[k].goals_against+= match[i].gaols_for_name0;
        }
        else if (match[i].gaols_for_name0 == match[i].gaols_for_name1)
        {
            int k;
            k = map[match[i].name0];
            team[k].point += 1;
            team[k].goals_for+= match[i].gaols_for_name1;
            team[k].goals_against+= match[i].gaols_for_name1;
            k = map[match[i].name1];
            team[k].point += 1;
            team[k].goals_for+= match[i].gaols_for_name1;
            team[k].goals_against+= match[i].gaols_for_name1;

        } 
        else
        {
            int k;            
            k = map[match[i].name1];
            team[k].point += 3;
            team[k].goals_for+= match[i].gaols_for_name1;
            team[k].goals_against += match[i].gaols_for_name0;
            k = map[match[i].name0];
            team[k].goals_for += match[i].gaols_for_name0;
            team[k].goals_against += match[i].gaols_for_name1;
            
        }
    }
}

void rank_team()
{
    int i, j;

    for (i = 0; i < 6; i++)    {
        for (j = 0; j < 6 - i - 1; j++)        {
            if (team[j].point< team[j+1].point)            {
                Team temp;
                temp = team[j + 1];
                team[j + 1] = team[j];
                team[j] = temp;   
            }
            else if (team[j].point ==team[j + 1].point)            {
                if ((team[j].goals_for- team[j].goals_against)<(team[j+1].goals_for - team[j+1].goals_against))                {
                    Team temp;
                    temp = team[j + 1];
                    team[j + 1] = team[j];
                    team[j] = temp;
                }
                else if ((team[j].goals_for - team[j].goals_against)==(team[j + 1].goals_for - team[j + 1].goals_against)&& team[j].goals_for< team[j+1].goals_for) {
                    Team temp;
                    temp = team[j + 1];
                    team[j + 1] = team[j];
                    team[j] = temp;
                }
                else if ((team[j].goals_for - team[j].goals_against) == (team[j + 1].goals_for - team[j + 1].goals_against) && team[j].goals_for == team[j + 1].goals_for) {

                }
            }
        }
    }
}

void shuchu()
{
    for (int i = 0; i < 6; i++)    {
        cout << team[i].name << " " << team[i].point << " " << team[i].goals_for << " " << team[i].goals_against << endl;
    }
    cout << "END" << endl;
}
int main(){
    int T=1;
    while (cin >> T)    {        
        while (T--)        {             
            shuru_team(map);
            shuru_match();
            jifen(map);
            rank_team();
            shuchu();
        }
    }
    system("pause");
}