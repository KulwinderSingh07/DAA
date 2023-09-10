#include<bits/stdc++.h>
using namespace std;
class Job
{    
public:
int id;
int deadline;
int profit;
    Job(int idval,int deadval,int profitval){
        id=idval;
        deadline=deadval;
        profit=profitval;
    }
};
bool compareprofit(Job first,Job second){
    return first.profit>second.profit;
}
int main()
{
    vector<Job> arr;
    int n;
    cout<<"Enter the value of no of jobs :";
    cin>>n;
    for(int i=0;i<n;i++){
        int deadline,profit;
        cout<<"Enter the value of deadline and profit:";
        cin>>deadline>>profit;
        Job temp(i+1,deadline,profit);
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end(),compareprofit);
    int maxJobSlots=INT_MIN;
    for(const auto i:arr){
        maxJobSlots=max(i.deadline,maxJobSlots);
    }
    // cout<<maxJobSlots<<endl;
    vector<int> slotStatuaArr(maxJobSlots+1,-1);
    int countJobs=0;
    int profit=0;
    for(int i=0;i<n;i++){
        for(int j=arr[i].deadline;j>0;j--){
            if(slotStatuaArr[j]==-1){
                slotStatuaArr[j]=1;
                countJobs++;
                profit+=arr[i].profit;
                break;
            }
        }
    }
    cout<<"Count of Jobs:"<<countJobs<<endl;
    cout<<"Total Profit is:"<<profit<<endl;


return 0;
}