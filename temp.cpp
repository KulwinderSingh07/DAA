#include<bits/stdc++.h>
using namespace std;
void temp_fund(int arr[][4]){
    arr[2][2]=3;
}
int main()
{
    // int n=10;
    // int arr[n];
    // memset(arr,-1,sizeof(arr));
    // temp_fund(arr);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<endl;
    // }
    int arr[4][4]={-1};
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            arr[i][j]=-1;
        }
        cout<<endl;
    }
    temp_fund(arr);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}