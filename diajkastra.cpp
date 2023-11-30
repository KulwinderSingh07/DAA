#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    bool vis;
    int dis;
    int parent;
    Node(){
        vis=false;
        dis=INT_MAX;
        parent=-1;
    }
};
int findMinVal(Node arr[],int n)
{
    int min_dis=INT_MAX;
    int index;
    for(int i=0;i<n;i++){
        if(!arr[i].vis && arr[i].dis<min_dis){
            min_dis=arr[i].dis;
            index=i;
        }
    }
    return index;
}
int main()
{
    int n;
    cout<<"Enter the number of Nodes:";
    cin>>n;
    Node arr[n];
    int edges[n][n]={{0,2,0,1,0,0,0},
                     {0,0,0,3,10,0,0},
                     {4,0,0,0,0,5,0},
                     {0,0,2,0,2,8,4},
                     {0,0,0,0,0,0,6},
                     {0,0,0,0,0,0,0},
                     {0,0,0,0,0,1,0}};

    int count=0;
    arr[0].parent=-1;
    arr[0].dis=0;
    while(count!=n){
        int min_index=findMinVal(arr,n);
        count++;
        arr[min_index].vis=true;
        for(int i=0;i<n;i++){
            if(edges[min_index][i]==0) continue;
            if(!arr[i].vis && (edges[min_index][i]+arr[min_index].dis<arr[i].dis)){
                arr[i].dis=edges[min_index][i]+arr[min_index].dis;
                arr[i].parent=min_index;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<i<<" "<<arr[i].vis<<" "<<arr[i].dis<<" "<<arr[i].parent<<endl;
    }



return 0;
}