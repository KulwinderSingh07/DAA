#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int sr_no;
    int profit;
    int weight;
};
void listDownTheConsideredItems(int i,int j,vector<vector<int>> table,vector<node> arr){
    if(j>0){
         if(table[i][j]==table[i-1][j]){
            listDownTheConsideredItems(i-1,j,table,arr);
        }else{
            cout<<arr[i].sr_no<<"\t\t"<<arr[i].profit<<"\t\t"<<arr[i].weight<<endl;
            listDownTheConsideredItems(i-1,j-arr[i].weight,table,arr);
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the value of total no of items:";
    cin>>n;
    vector<node> arr(n+1);
    for(int i=1;i<n+1;i++){
        arr[i].sr_no=i;
        int profit,weight;
        cout<<"Enter the value of profit and weight:";
        cin>>profit>>weight;
        arr[i].profit=profit;
        arr[i].weight=weight;
    }
    int total_weight;
    cout<<"Enter the value of total weight:";
    cin>>total_weight;
    vector<vector<int>> table(n+1,vector<int>(total_weight+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<total_weight+1;j++){
            if(arr[i].weight>j){
                table[i][j]=table[i-1][j];
            }else{
                table[i][j]=max(table[i-1][j],(arr[i].profit+table[i-1][j-arr[i].weight]));
            }
        }
    }
    int j=total_weight;
    int i=n;
    cout<<"              The considered items are as folowing                 "<<endl;
    cout<<"SrNo"<<"\t\t"<<"Profit"<<"\t\t"<<"Weight"<<endl;
    listDownTheConsideredItems(i,j,table,arr);
    
    

return 0;
}