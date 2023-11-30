#include<bits/stdc++.h>
using namespace std;
void print_order(int x[]){
    for(int i=0;i<5;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

void solve(int index,int arr[],int target,int sum,int x[]){
    if(index==5){
        if(sum==target){
            print_order(x);
        }
        return;
    }
    if(sum>target){
        return;
    }
    x[index]=1;
   sum+=arr[index];
   solve(index+1,arr,target,sum,x);
   sum-=arr[index];
    x[index]=0;
   solve(index+1,arr,target,sum,x);

}
int main()
{
    int target=6;
    int x[5]={0,0,0,0,0};
    int arr[5]={1,2,5,2,1};
    int sum=0;
    // vector<int []> ans;
    solve(0,arr,target,sum,x);

return 0;
}