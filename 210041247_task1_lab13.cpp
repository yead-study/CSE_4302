#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<fstream>
#include<map>
#include<sstream>
#include<numeric>
using namespace std;


string vowelremover(string input)
{
    for(int ch = 0; ch < input.length(); ch++ )
    {
        if(input[ch] == 'a' || input[ch] == 'e' || input[ch] == 'i' || input[ch] == 'o' || input[ch] == 'u')
        {
            string str= "3";
            input.replace(ch,1,str);
        }
    }
    return input;
}
int main()
{
    ifstream pfile;
    pfile.open("player.txt");
    if(!pfile)
    {
        cout << "error opening";
        return -1;
    }
    vector<pair<string,int>>v;
    vector<pair<int,string>>v2;
    vector<pair<string,int>>v4;
    //map<string,int> pmap;
    while(!pfile.eof())
    {
        string line;
        getline(pfile,line);
        istringstream iss1(line);
        string player_name;
        string player_score;
        int int_score;
        getline(iss1,player_name,',');
        getline(iss1,player_score);
        pair<string,int> playerpair;
        int_score = stoi(player_score);
        playerpair.first = player_name;
        playerpair.second = int_score;
        v.push_back(playerpair);
        v4.push_back(playerpair);
        pair<int,string> scorepair;
        scorepair.first = int_score;
        scorepair.second = player_name;
        v2.push_back(scorepair);
    }
    pfile.close();
    stable_sort(v.begin(),v.end());
    cout << "Task 1: \n";
    for(auto p:v)
    {
        string tempstring = vowelremover(p.first);
        p.first = tempstring;
        cout << p.first << " " << p.second << endl;
    }
    stable_sort(v2.begin(),v2.end());
    cout << "\nTask 2: \n";
    cout << "\nSorted first 5 in descending: " << endl;
    reverse(v2.begin(),v2.end());
    int adfasdfasf = 0;
    for(auto p:v2)
    {
        adfasdfasf++;
        if(adfasdfasf> 5)
        {
            break;
        }

        cout << p.second << " " << p.first << endl;
    }
    cout << "\nTask 3: \n";
    cout << "\nAfter reversing the container\n";
    reverse(v4.begin(),v4.end());
    for(auto p:v4)
    {
        cout << p.first << " " << p.second << endl;
    }
    cout << "\nTask 4: \n";
    cout << "\nPlayers with score greater than 200:  ";
    int x = 200;
    vector<int> scorevector2;
    for(auto p:v)
    {
        scorevector2.push_back(p.second);
    }
    int c = count_if(scorevector2.begin(),scorevector2.end(),[x](int value){
        return value > x;
    });
    cout << c << endl;
    cout << "\nTask 5: \n";
    cout << "\nPlayer with score: ";
    x= 234;
    c = count_if(scorevector2.begin(),scorevector2.end(),[x](int value){
        return value == x;
    });
    cout << c << endl;
    cout << "\nTask 6: \n";
    vector<pair<string,int>>v3(v.begin(),v.end());
     
    if(v == v3)
    {
        cout << "Equal\n";
    }
    else
    {
        cout << "Not equal\n";
    }
    cout<< "\nTask 7: After merge: \n";
    v.insert(v.end(),v4.begin(),v4.end());
    for(auto p:v)
    {
        cout << p.first << " " << p.second << endl;
    }
    vector<int> scorevector;
    for(auto p:v)
    {
        scorevector.push_back(p.second);
    }
    cout << "\n Task 8: \n"; 
    int sum = 0;
    sum = accumulate(scorevector.begin(),scorevector.end(),sum);
    cout << "Sum: " << sum << endl;
    return 0;
}