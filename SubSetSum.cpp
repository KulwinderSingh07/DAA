#include<bits/stdc++.h>
using namespace std;
void caluclate_subsets(vector<int> arr,vector<int> output,vector<vector<int>>& ans,int index,int sum,int target){
    
    if(index==arr.size()){
    if(sum==target){
        ans.push_back(output);
        return;
    }
    return;
    }
    if(sum>target){
        return;
    }

    sum+=arr[index];
    output.push_back(arr[index]);
    caluclate_subsets(arr,output,ans,index+1,sum,target);
    sum-=arr[index];
    output.pop_back();
    caluclate_subsets(arr,output,ans,index+1,sum,target);


}
int main()
{
    vector<int> arr={1,2,4,3,5};
    int target;
    cout<<"Enter the target sum:";
    cin>>target;
    vector<int> output;
    vector<vector<int>> ans;
    caluclate_subsets(arr,output,ans,0,0,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
return 0;
}