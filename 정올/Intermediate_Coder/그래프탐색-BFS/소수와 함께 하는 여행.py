#include<bits/stdc++.h>
using namespace std;

int src, dest;
bool visit[10000];
bool prime[10000];

struct Node {
    int x, d;
    Node() {}
    Node(int x, int d) : x(x), d(d) {}
};

void make_prime_sieve() {
    for (int i=2; i<10000; i++) prime[i] = true;
    for (int i = 2; i*i < 10000; i++) {
        if (!prime[i]) continue;
        for (int j=2*i; j<10000; j+=i) prime[j] = false;
    }
}

int get_num(char s[]) {
    int num = 0;
    int p = 1;
    for (int i = 3; i >= 0; i--) {
        num += (s[i] - '0') * p;
        p *= 10;
    }
    return num;
}

void bfs() {
    queue<Node> que;
    que.push(Node(src, 0));
    visit[src] = 1;

    while (!que.empty()) {
        Node node = que.front(); que.pop();

        int u = node.x;
        int udist = node.d;

        if (u == dest) {
            printf("%d\n", udist);
            break;
        }

        char s[5];
        sprintf(s, "%d", u);  // s = u;
        for (int i = 0; i < 4; i++) {
            char t = s[i];
            for (int j = (i == 0); j < 10; j++) {
                if (s[i]-'0' == j) continue;
                s[i] = j+'0';
                int v = get_num(s);
                if (!prime[v] || visit[v]) continue;
                visit[v] = 1;
                que.push(Node(v, udist + 1));
            }
            s[i] = t;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin>>src>>dest;
    make_prime_sieve();
    bfs();

    return 0;
}
