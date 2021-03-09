#include <bits/stdc++.h>
using namespace std;

using std::vector;
using std::pair;
vector<int> ccnum;
int res;
void explore(int v,vector<bool> &visited,vector<vector<int> > adj){
visited[v] = true;
for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            explore(*i, visited,adj);
}



int number_of_components(vector<vector<int> > &adj,int n) {

  //write your code here
  vector<bool> visited = {false};
  res = 1;
  for(int i=0;i<n;i++){
     if(!visited[i]){
        explore(i,visited,adj);
        res += 1;}
  }
  return res;
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
  std::cout << number_of_components(adj,n);
}
