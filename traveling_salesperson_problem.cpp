#include<bits/stdc++.h>
using namespace std;
    int visited=1;
int min_distance(vector<vector<int>> arr,int vertex,int n,map<int,bool> visited_check,int visited){
    if(visited_check.size()==n){
        return arr[vertex][0];
    }
    visited_check[vertex]=true;
    visited++;
    int min_dis=INT_MAX;
    int result;
    for(int i=0;i<n;i++){
        if(visited_check[i]==false){
            int temp=arr[vertex][i]+min_distance(arr,i,n,visited_check,visited);
            min_dis=min(min_dis,temp);
            cout<<min_dis<<" "<<vertex<<" "<<i<<" "<<temp<<endl;
        }
    }
    return min_dis;

}
int main()
{
    int n;
    cout<<"Enter the number of vertices:";
    cin>>n;
    vector<vector<int>> adjacency_matrix(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"Enter the distance cost from "<<i+1<<" to "<<j+1<<":";
            cin>>adjacency_matrix[i][j];
        }
    }
        map<int,bool> visited_check;
    cout<<min_distance(adjacency_matrix,0,n,visited_check,0);
return 0;
}