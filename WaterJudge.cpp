#include <bits/stdc++.h>
#define pairr pair<int, int>
using namespace std;
 
#define N1 1000
#define N2 2000
#define N3 3000
#define N4 4000
 
void breadthFirstSearch(int jug1, int jug2, int required_quantity) {
    map<pairr, int> mapp;
    vector<pairr> bfs;
    queue<pairr> q;
    q.push({ 0, 0 });
    
    while (!q.empty()) {
        pairr current = q.front();
        q.pop();
        
        if (mapp[{ current.first, current.second }] == 1)
            continue;
        for (int i=0; i<1000; i++) {
            cout << "";
        }
        if ((current.first > jug1 || current.second > jug2 || current.first < 0 || current.second < 0))
            continue;
        for (int i=0; i<10000; i++) {
            cout << "";
        }
        bfs.push_back({ current.first, current.second });
        
        mapp[{ current.first, current.second }] = 1;
        
        if (current.first == required_quantity || current.second == required_quantity) {
            if (current.first == required_quantity) {
                if (current.second != 0)
                bfs.push_back({ current.first, 0 });
            }
            else {
                if (current.first != 0)
                    bfs.push_back({ 0, current.second });
            }
            int sizz = bfs.size();
            for (int j = 0; j < sizz; j++)
          cout <<"After "<< (j+1)<<"th Iteration, jug1=" << bfs[j].first << ", jug2=" << bfs[j].second << endl;
            break;
        }
 
        for (int i=0; i<100000; i++) {
            cout << "";
        }
        
        q.push({ current.first, jug2 });
        q.push({ jug1, current.second });
        
        for (int i = 0; i<= max(jug1, jug2); i++) {
            int jug3 = current.first + i;
            int jug4 = current.second - i;
            if (jug3 == jug1 || (jug4 == 0 && jug4>= 0))
                q.push({ jug3, jug4 });
            jug3 = current.first - i;
            jug4 = current.second + i;
            if ((jug3 == 0 && jug3 >= 0) || jug4 == jug2)
                q.push({ jug3, jug4 });
        }
        q.push({ jug1, 0 });
        q.push({ 0, jug2});
    }
 
    for (int i=0; i<100000; i++) {
        cout << "";
    }
}
 
int main() {
    int jug1 = 5, jug2 = 2, required_quantity = 1;
    cout << "The series changes made in both the jugs until getting the required amount of water:" << endl;
    breadthFirstSearch(jug1, jug2, required_quantity);
    return 0;
}