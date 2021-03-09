#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using std::vector;
using std::pair;

bool reach(vector<vector<int> > &adj,int s,int d){
if(s == d) return true;
vector<bool> visited = {false};
queue<int> q;
visited[s] = true;
q.push(s);
while(!q.empty()){
s = q.front();
q.pop();
for(auto i=adj[s].begin();i!=adj[s].end();i++){
  if(*i == d) return true;
  if (!visited[*i])
            {
                visited[*i] = true;
                q.push(*i);
            }
}
}
or for(auto i:adj[s]){
  if(i == d) return true;
  if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
}
}
return false;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
