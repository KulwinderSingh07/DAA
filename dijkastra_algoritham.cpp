#include<bits/stdc++.h>
using namespace std;
class  Table
{
    public:
    int sr_no;
    int known=0;
    int dist_val=INT_MAX;
    int prev_val=0;
    Table(int sr_val){
        sr_no=sr_val;
    }   
};
int find_min_index(int row,int no_vertexes,vector<vector<int>> arr,vector<Table> tab){
  int min_value=INT_MIN;
  int min_index=-1;
  for(int i=0;i<no_vertexes;i++){
    if(tab[i].known!=0){
    int temp=min_value;
    min_value=min(arr[row][i],min_value);
    if(temp!=min_value){
      min_index=i;
    }
    }
  }
  return min_index;
}
int main()
{
  int no_vertexes,no_edges;
  cout<<"Enter the no of vertexes:";
  cin>>no_vertexes;
  cout<<"Enter the no of edges:";
  cin>>no_edges;
  vector<vector<int>> adjacency_matrix(no_vertexes,vector<int>(no_vertexes,0));
  for(int i=0;i<no_edges;i++){
    int ver_from,ver_to,edge_value;
    cout<<"Enter the value of from, to and edge weight:";
    cin>>ver_from>>ver_to>>edge_value;
    adjacency_matrix[ver_from-1][ver_to-1]=edge_value;
  }
  // for(int i=0;i<no_vertexes;i++){
  //   for(int j=0;j<no_vertexes;j++){
  //      cout<<adjacency_matrix[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  vector<Table> arr;
  for(int i=0;i<no_vertexes;i++){
    Table temp(i+1);
    arr.push_back(temp);
  }

  int known_count=0;
  pair<int,int> min_index={-1,-1};

  while (known_count<no_vertexes)
  {
    if(known_count==0){
    arr[0].known=1;
    arr[0].dist_val=0;
    arr[0].prev_val=0;
    for(int i=0;i<no_vertexes;i++){
    if(adjacency_matrix[0][i]!=0){
      int temp=min_index.second;
      min_index.second=min(min_index.second,adjacency_matrix[0][i]);
      if(min_index.second!=temp){
        min_index.first=i;
      }
      arr[i].dist_val=adjacency_matrix[0][i];
      arr[i].prev_val=1;
    }
  }
  known_count++;
    }
    else{
      arr[min_index.first].known=1;
      known_count++;
      for(int i=0;i<no_vertexes;i++){
      if(adjacency_matrix[min_index.first][i]!=0){
      int temp=min_index.second;
      min_index.second=min(min_index.second,adjacency_matrix[min_index.first][i]);
      if(min_index.second!=temp){
        min_index.first=i;
      }
      arr[i].dist_val=adjacency_matrix[min_index.first][i];
      arr[i].prev_val=min_index.first;
    }
    }
  }
  }
  for(int i=0;i<no_vertexes;i++){
    cout<<arr[i].sr_no<<" "<<arr[i].dist_val<<" "<<arr[i].prev_val<<endl;
  }


  



return 0;
}