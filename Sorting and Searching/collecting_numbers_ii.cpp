#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n, m;
    cin>>n>>m;
    cout<<endl;
    vector<int> arr(n);
    vector<int> main;
    vector<bool> tracker(n, false);
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        arr[num - 1] = i;
        main.push_back(num);
    }

    int ans = 1;
    for(int i = 1; i<n ; i++){
        if(arr[i - 1] > arr[i]){
            tracker[i] = true;
            ans++;
        }
    }

    while(m--){
        int pos[2];
        int a,b;
        cin>>a>>b;
        pos[0] = main[a-1] - 1; 
        pos[1] = main[b-1] - 1;
        swap(main[a-1], main[b-1]);
        swap(arr[pos[0]], arr[pos[1]]);
        
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                int posA = pos[j];
                if ((posA + i) != 0 && (posA + i) < n)
                {
                    if (arr[posA + i - 1] > arr[posA + i] && !tracker[posA + i])
                    {
                        ans++;
                        tracker[posA + i] = 1;
                    }
                    else if (arr[posA + i - 1] < arr[posA + i] && tracker[posA + i])
                    {
                        ans--;
                        tracker[posA + i] = 0;
                    }
                }
            }
            
        }
        cout<<ans<<endl;
    }
    return 0;
}