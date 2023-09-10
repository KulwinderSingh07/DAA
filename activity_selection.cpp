#include<bits/stdc++.h>
using namespace std;
class activity
{
public:
    int srNo;
    int startTime;
    int endTime;
    activity(int srVal,int startVal,int endVal){
        srNo=srVal;
        startTime=startVal;
        endTime=endVal;
    }
};
bool compareFinishTime(activity first,activity second){
    return first.endTime<second.endTime;
}
int main()
{
     int n;
    cout<<"Enter the total no of activities:";
    cin>>n;
    vector<activity> arr;
    for(int i=0;i<n;i++){
        int start,end;
        cout<<"Enter the Start Time and End Time for item "<<i+1<<":";
        cin>>start>>end;
        activity temp(i+1,start,end);
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end(),compareFinishTime);
    vector<activity>ans_arr;
    for(int i=0;i<n;i++){
        if(!ans_arr.size()){
            ans_arr.push_back(arr[i]);
            continue;
        }
        if(ans_arr.back().endTime<=arr[i].startTime){
            ans_arr.push_back(arr[i]);
        }
    }
    cout<<"SrNo"<<" "<<"Start Time"<<" "<<"End Time"<<endl;
    for(const auto i:ans_arr){
        cout<<i.srNo<<"\t"<<i.startTime<<"\t"<<i.endTime<<endl;
    }


return 0;
}