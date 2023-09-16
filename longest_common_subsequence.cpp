#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    string direction;
    int data;
};
int main()
{
    string str1;
    string str2;
    cout<<"Enter the value of string one:";
    cin>>str1;
    cout<<"Enter the value of string two:";
    cin>>str2;
    vector<vector<node>> check(str1.length()+1,vector<node>(str2.length()+1));
    for(int i=1;i<str1.length()+1;i++){
        for(int j=1;j<str2.length()+1;j++){
            if(str1[i-1]==str2[j-1]){
                check[i][j].data=1+check[i-1][j-1].data;
                check[i][j].direction="diagonal";
            }else{
                check[i][j].data=max(check[i-1][j].data,check[i][j-1].data);
                if(check[i][j].data==check[i-1][j].data){
                    check[i][j].direction="up";
                }else{
                    check[i][j].direction="left";
                }
            }
        }
    }
    cout<<check[str1.length()][str2.length()].data<<endl;
    int i=str1.length();
    int j=str2.length();
    string result;
    while(i!=0 || j!=0){
        if(check[i][j].direction=="diagonal"){
            result=str1[i]+result;
            i-=1;
            j-=1;
        }
        else if(check[i][j].direction=="up"){
            i-=1;
        }
        else{
            j-=1;
        }
        }
        cout<<result<<endl;
return 0;
}