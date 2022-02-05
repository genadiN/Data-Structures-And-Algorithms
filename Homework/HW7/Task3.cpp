#include<cstdio>
#include<vector>
#include<map>

using namespace std;

int n,k,arr[500009],ans[500009];
map<int, vector<int>> nums;

void init(){
    scanf("%d %d",&n,&k);

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void solve(){
    fill(ans,ans+n,-1);

    for(int i=n-1;i>=0;i--){
        auto it = nums.upper_bound(arr[i]);
        vector<int>toDel;

        while(it != nums.end() && (*it).first - arr[i] <= k){
            for(int ind : (*it).second){
                ans[ind] = i;
            }

            toDel.push_back((*it).first);
            it++;
        }

        for(auto del:toDel)nums.erase(del);

        nums[arr[i]].push_back(i);
    }
}

void print(){
    printf("%d",ans[0]);
    for(int i=1;i<n;i++){
        printf(" %d",ans[i]);
    }
    printf("\n");
}

int main(){
    init();
    solve();
    print();
}
