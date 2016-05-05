#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define DESC(i, n) for(int i = n-1; i >= 0; i--)
#define MAX 10000
using namespace std;

int tempo = 0;
int d[MAX], f[MAX], low[MAX];
int raiz;
void dfs(int v){
	vis[v] = 1;
	int nf = 0;
	bool any = false;
	d[v] = low[v] = tempo++;
	for(int u : adj[v]){
		if(!vis[u]) {
			dfs(u);
			nf++;
			if(low[u] >= d[v]) any = true;
			low[v] = min(low[u], low[v]);
			if(low[u] > d[v]); // (v, u) é uma ponte
		}
		else{
			low[v] = min(low[v], d[u]);
		}
	}
	if((v == raiz && nf >= 2) || (v != raiz && any)); // v é articulação
}

int dist[MAX];
void spfa(int start){
	REP(i, MAX) dist[i] = (int)1e9;
	dist[start] = 0;
	queue<int> q;
	q.push(start);
	int nafila[MAX];
	while(!q.empty()){
		u = q.front(); q.pop();

		for(pair<int, int> v : adj[u]){
			// v.second stands for the weight
			if(dist[u] + v.second > dist[v]){
				dist[v] = dist[u] + v.second;
				if(!nafila[v.first]) {q.push(v); nafila[v.first] = true;}
			}
		}

	}

}

int main(){
	return 0;
}