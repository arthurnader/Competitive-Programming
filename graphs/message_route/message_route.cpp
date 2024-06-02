#include<bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define print(a)       for(auto x : a) cout << x << " "; cout << endl

using namespace std;

class graph{

    int V;
    list<int> *l;

public:

    graph(int N){
        this->V = N;
        this->l = new list<int>[V];
    }

    void add_edge(int v1, int v2, bool undirected = true){

        l[v1].push_back(v2);
        if (undirected){
            l[v2].push_back(v1);
        }
    }

    int bfs(int src, int dst){

        vector<int> distances(this->V, -1);
        queue<int> q;

        q.push(src);
        distances[src] = 1;

        while(!q.empty()){

            int current = q.front();
            q.pop();

            for (auto ngb: l[current]){

                if (distances[ngb] == -1){
                   distances[ngb] = distances[current] + 1;
                   q.push(ngb);
                }
            }
        }

        return distances[dst];

    }
};



int main(){

#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif

    int n;
    cin >> n;

    int v1, v2;

    graph g(n);

    while(cin >> v1){
        cin >> v2;

        g.add_edge(v1-1, v2-1);
    }

    int res = g.bfs(0, n-1);
    cout << res;

    return 0;
}
