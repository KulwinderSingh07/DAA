// Fractionla knapsack using greedy Time Complexity-O(nlog(n))
#include<bits/stdc++.h>
using namespace std;
class question{
    public:
    int srno;
    int profit;
    int weight;
    float profitRatioWeight;
    question(int sr_val,int val,int wei_val){
        srno=sr_val;
        profit=val;
        weight=wei_val;
        profitRatioWeight=float(profit)/weight;

    }
};
bool compare_profit(question first,question second){
    return first.profit>second.profit;
}
bool compare_weight(question first,question second){
    return first.weight<second.weight;
}
bool compare_profitUponWeightRatio(question first,question second){
    return first.profitRatioWeight>second.profitRatioWeight;
}
int main()
{
    int n;
    cout<<"Enter the total no of items:";
    cin>>n;
    int total_weight;
    cout<<"Enter total weight:";
    cin>>total_weight;
    vector<question> arr;
    for(int i=0;i<n;i++){
        int weight,profit;
        cout<<"Enter the weight and profit for item "<<i+1<<":";
        cin>>weight>>profit;
        question temp(i+1,profit,weight);
        arr.push_back(temp);
    }
    int strategy;
    cout<<"Enter value of strategy:"<<endl;
    cout<<"Choose 1 2 3:";
    cin>>strategy;
    vector<question> ans_arr;

    float total_profit=0;
    switch (strategy)
    {
    case 1:{
    // if(strategy=='1'){
    sort(arr.begin(),arr.end(),compare_profit);
    int i=0;
    int reamingi_weight=total_weight;
    while (reamingi_weight!=0 && i<n)
    {
        if(arr[i].weight<=reamingi_weight){
            reamingi_weight-=arr[i].weight;
            total_profit+=arr[i].profit;
        }else{
           float temp=float(arr[i].profit*reamingi_weight)/float(arr[i].weight);
            reamingi_weight=0;
            cout<<temp<<endl;
            total_profit=temp+float(total_profit);
        }
            ans_arr.push_back(arr[i]);
            i++;
    }
    break;
    }

    case 2:{
    int reamingi_weight=total_weight;
    int i=0;
    sort(arr.begin(),arr.end(),compare_weight);
    while (reamingi_weight!=0 && i<n)
    {
        if(arr[i].weight<=reamingi_weight){
            reamingi_weight-=arr[i].weight;
            total_profit+=arr[i].profit;
        }else{
            float temp=float(arr[i].profit*reamingi_weight)/float(arr[i].weight);
            reamingi_weight=0;
            cout<<temp<<endl;
            total_profit=temp+float(total_profit);
        }
            ans_arr.push_back(arr[i]);
            i++;
    }
    break;
    }
    case 3:{
    int reamingi_weight=total_weight;
    int i=0;
    sort(arr.begin(),arr.end(),compare_profitUponWeightRatio);
    while (reamingi_weight!=0 && i<n)
    {
        if(arr[i].weight<=reamingi_weight){
            reamingi_weight-=arr[i].weight;
            total_profit+=arr[i].profit;
        }else{
            float temp=float(arr[i].profit*reamingi_weight)/float(arr[i].weight);
            reamingi_weight=0;
            cout<<temp<<endl;
            total_profit=temp+float(total_profit);
        }
            ans_arr.push_back(arr[i]);
            i++;
    }
    break;
    }
    }
    
    cout<<"Total Profit:"<<total_profit<<endl;
    cout<<"Object ID"<<" "<<"Profit"<<" "<<"Weight"<<" "<<"Ratio"<<endl;

    for(int i=0;i<ans_arr.size();i++){
        cout<<ans_arr[i].srno<<"\t"<<ans_arr[i].profit<<"\t"<<ans_arr[i].weight<<"\t"<<ans_arr[i].profitRatioWeight<<endl;
    }


return 0;
}