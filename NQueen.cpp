#include<bits/stdc++.h>
using namespace std;
    void save(vector<vector<int>> board,vector<vector<string>>&ans,int n){
        vector<string> temp;
        for(int i=0;i<n;i++){
            string str;
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    str.push_back('Q');
                }else{
                    str.push_back('.');
                }
            }
            temp.push_back(str);
            // str.clear();
        }
        ans.push_back(temp);
        // temp.clear();
    }
    bool isSafe(vector<vector<int>> board,int n,int i,int j,map<int,int> &colum_checker,map<int,int> &left_diagonal_checker,map<int,int>&right_diagonal_checker){
        if(colum_checker[j]==1){
            return false;
        }
        if(left_diagonal_checker[n-1+j-i]==1){
            return false;
        }
        if(right_diagonal_checker[i+j]==1){
            return false;
        }
        return true;

    }
    void solve(vector<vector<int>>& board,int n,int index,vector<vector<string>>& ans,map<int,int> &colum_checker,map<int,int> &left_diagonal_checker,map<int,int>&right_diagonal_checker){
        if(index==n){
            save(board,ans,n);
            return;            
            }
            for(int j=0;j<n;j++){
                if(isSafe(board,n,index,j,colum_checker,left_diagonal_checker,right_diagonal_checker)){
                board[index][j]=1;
                colum_checker[j]=1;
                left_diagonal_checker[n-1+j-index]=1;
                right_diagonal_checker[index+j]=1;
                solve(board,n,index+1,ans,colum_checker,left_diagonal_checker,right_diagonal_checker);
                board[index][j]=0;
                colum_checker[j]=0;
                left_diagonal_checker[n-1+j-index]=0;
                right_diagonal_checker[index+j]=0;
                }
            }
    }
    vector<vector<string>> solveNQueens(int n) {
        int index=0;
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<vector<string>> ans;
        map<int,int> colum_checker;
        map<int,int> left_diagonal_checker;
        map<int,int> right_diagonal_checker;
        solve(board,n,index,ans,colum_checker,left_diagonal_checker,right_diagonal_checker);
        return ans;
    }

int main()
{
    int n;
    cin>>n;
    vector<vector<string>> ans=solveNQueens(n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

return 0;
}