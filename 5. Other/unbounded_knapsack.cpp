//This Function is used to find maximum profit if we have a given maximum weight to be lifted.
//w is maximum weight to be lifted.

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector <int> prev(w+1,0);
    vector <int> curr(w+1,0);
    
    for(int i  = 0 ; i < n ; i++ ){
        for(int j = 0 ; j <= w ; j++){
            if(i==0){
                if(j>=weight[0]) curr[j] =profit[0]+curr[j-weight[0]];
                else curr[j] = 0;
            }else{
                int take = 0;
                if(j>=weight[i]) take = profit[i] + curr[j-weight[i]];
                int not_take = prev[j];
                curr[j] = max(take,not_take);
            }
        }
        prev = curr;
    }
    return curr[w];
}
