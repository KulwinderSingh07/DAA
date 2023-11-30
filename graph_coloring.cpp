#include<bits/stdc++.h>
using namespace std;
int arr[4][4]={{0,1,0,1},
                   {1,0,1,1},
                   {0,1,0,1},
                   {1,1,1,0}};
bool isSafe(int index,char chosenColor,char coloredVer[],int n){
    for(int i=0;i<n;i++){
        if(arr[index][i]==1 && coloredVer[i]==chosenColor){
            return false;
        }
    }
    return true;
}
void print_colors(char colorVer[],int n){
    for(int i=0;i<n;i++){
        cout<<i<<"->"<<colorVer[i]<<endl;
    }
    cout<<endl;
}
bool colorGrpah(int index,int n,char color[],char colorVer[]){
    if(index==n){
        print_colors(colorVer,n);
        return true;
    }
    for(int i=0;i<3;i++){
        if(isSafe(index,color[i],colorVer,n)){
            colorVer[index]=color[i];
            if(colorGrpah(index+1,n,color,colorVer)){
                return true;
            }
            colorVer[index]='t';
        }
    }
            return false;
}
int main()
{
    // int n;
    // cin>>n;
    int n=4;
    int arr[n][n]={{0,1,0,1},
                   {1,0,1,1},
                   {0,1,0,1},
                   {1,1,1,0}};
    char coloredVer[n]={'t','t','t','t'};

    char color[3]={'b','r','y'};
    colorGrpah(0,n,color,coloredVer);
return 0;
}