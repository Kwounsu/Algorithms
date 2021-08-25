#include<bits/stdc++.h>
using namespace std;

struct data{int X,Y,step;};
int A, B, ex, ey, cx, cy, s, transferable_vol, a, b;
queue<data> q;

/* 최적화: 모든 케이스가 4가지로 정해짐.
 * 0: A empty, 1: A full, 2: B empty, 3: B full
 */
bool visited[4][100001];

int bfs(){
    q.push({0,0,0});
    while (!q.empty()){
        cx = q.front().X;
        cy = q.front().Y;
        s  = q.front().step;
        if (cx==ex && cy==ey)
            return s;
        q.pop();

        // Empty A
        if (!visited[0][cy]) {
            visited[0][cy] = true;
            q.push({0,cy,s+1});
        }
        // Fill A
        if (!visited[1][cy]) {
            visited[1][cy] = true;
            q.push({A,cy,s+1});
        }
        // Empty B
        if (!visited[2][cx]) {
            visited[2][cx] = true;
            q.push({cx,0,s+1});
        }
        // Fill B
        if (!visited[3][cx]) {
            visited[3][cx] = true;
            q.push({cx,B,s+1});
        }
        // Move A to B
        if (cx+cy <= B){
            if (!visited[0][cx+cy]) {
                visited[0][cx+cy] = true;
                q.push({0,cx+cy,s+1});
            }
        }else if (!visited[3][cx-(B-cy)]){
            visited[3][cx-(B-cy)] = true;
            q.push({cx-(B-cy),B,s+1});
        }
        // Move B to A
        if (cx+cy <= A){
            if (!visited[2][cx+cy]) {
                visited[2][cx+cy] = true;
                q.push({cx+cy,0,s+1});
            }
        }else if (!visited[1][cy-(A-cx)]){
            visited[1][cy-(A-cx)] = true;
            q.push({A,cy-(A-cx),s+1});
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    cin>>A>>B>>ex>>ey;
    cout<<bfs();
    return 0;
}
