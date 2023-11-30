#include<bits/stdc++.h>
using namespace std;
pair<int,float> caluclateUpperLowerBound(int totalWeight,bool selection,int index,int n,vector<pair<int,int>> arr){
    int remainingWeight=totalWeight;
    int upper_Bound=0;
    float lower_Bound=0;
    for(int i=0;(i<n && remainingWeight!=0);i++){
        if(selection==false && i==index){
            continue;
        }
        if(remainingWeight>=arr[i].second){
            remainingWeight-=arr[i].second;
            upper_Bound+=arr[i].first;
            lower_Bound+=arr[i].first;
        }else{
            float weight=(float)arr[i].first/arr[i].second;
            float profit=(float)weight*remainingWeight;
            remainingWeight=0;
            lower_Bound+=profit;
        }
    }
    return {upper_Bound,lower_Bound};
}
void caluclate_profit(int index,int uBound,float lBound,vector<pair<int,int>> arr,int TotalWeight){
    if(index==n){
        return;
    }
    pair<int,float> selectionProfits=caluclateUpperLowerBound(TotalWeight,true,index,n,arr);
    pair<int,float> unselectedProfits=caluclateUpperLowerBound(TotalWeight,false,index,n,arr);
    

}
int main()
{
    int n;
    vector<pair<int,int>> arr;
    vector<int> chosen(n,false);
    int TotalWeight;
    int index=0;
    pair<int,int> firstPhaseProfit=caluclateUpperLowerBound(TotalWeight,true,-1,n,arr);
    caluclate_profit(index,firstPhaseProfit.first,firstPhaseProfit.second,arr,TotalWeight)
return 0;
}