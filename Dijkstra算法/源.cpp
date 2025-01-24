#include<iostream>
#include<vector>
using namespace std;
const int MAX = 100;
const int INF = 0x3f3f3f3f;
int S[MAX];
int dis[MAX];
int path[MAX];
void DispAllPath(int S[], int dis[],int path[],int n,int v) {
	for (int i = 0; i < n; i++) {
		vector<int>apath;
		apath.push_back(i);
		int pre = path[i];
		while (pre != v) {
			apath.push_back(pre);
			pre = path[pre];
		}
		cout<<v; //先输出起点v
		for (int k = apath.size() - 1; k >= 0; k--)
			cout << "->" << apath[k];
	}
}
void Dijkstra(int edges[][MAX], int n, int v) 
{
	for (int i = 0; i < n; i++) {
		S[i] = 0;
		dis[i] = edges[v][i];
		if (edges[v][i]!=0&&edges[v][i] < INF) 
		{
			path[i] = v;
		}
		else {
			path[i] = -1;
		}
		S[v] = 1;
		for (int i = 0; i < n - 1; i++)
		{
			int mindis = INF;
			int u = -1;
			//找距离S最近的点
			for (int j = 0; j < n; j++) {
				if (S[j] == 0 && dis[j] < mindis) {
					mindis = dis[j];
					u = j;
				}
			}
			S[u] = 1;
			for (int j = 0; j < n; j++) {
				if (S[j] == 0 && edges[u][j] < INF && dis[u] + edges[u][j] < dis[j])
				{
					dis[j] = dis[u] + edges[u][j];
					path[j] = u;
				}
			}

		}
	}
	DispAllPath(S, dis, path, n, v);
}
int main()
{
}