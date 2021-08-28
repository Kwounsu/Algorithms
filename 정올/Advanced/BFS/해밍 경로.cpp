#include<bits/stdc++.h>
using namespace std;
#define ULL unsigned long long

int N, K, M, J, c, s;
vector<bitset<30>> bits;
queue<int> q;
stack<int> output;
int pre[100010];
bool visited[100010];

void print_route(int p){
	while (p > 0){
		output.push(p);
		p = pre[p];
	}
	while(!output.empty()){
		cout<<output.top()<<' ';
		output.pop();
	}
	cout<<'\n';
}

int hamming(int a, int b){
	int val = __builtin_popcount(bits[a].to_ulong()^bits[b].to_ulong());
    cout<<a<<','<<b<<"'s h: "<<val<<'\n';
    return val;
}

void bfs(){
	q.push(0);
	pre[0] = -1;
	visited[0] = true;
	while(!q.empty()){
		c = q.front(); q.pop();
		if (visited[c]) continue;
		visited[c] = true;
		for (int i=1; i<N; i++){
			if (i==c || hamming(c,i)!=1) continue;
			pre[i] = c;
			q.push(i);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>N>>K;
	bits.resize(N);
	for(int i=0; i<N; i++)
		cin>>bits[i];

	bfs();

	cin>>M;
	for(int i=0; i<M; i++){
		cin>>J;
		if (!visited[J]) cout<<-1<<'\n';
		else print_route(J);
	}

	return 0;
}
