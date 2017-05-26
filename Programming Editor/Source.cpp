#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

struct Edge
{
	int connecting;
	int time;
};

struct DfsRet
{
	int time_to_visit_all; // not including returning time
	int time_to_visit_deepest;

	void operator&=(const DfsRet& rhs)
	{
		time_to_visit_all += rhs.time_to_visit_all;
		time_to_visit_deepest = max(time_to_visit_deepest,
		                            rhs.time_to_visit_deepest);
	}

	DfsRet operator+(int rhs)
	{
		time_to_visit_all += rhs;
		time_to_visit_deepest += rhs;
		return *this;
	}
};

int N;
vector<vector<Edge>> g;
vector<bool> visited;

DfsRet dfs(int index)
{
	visited[index] = true;

	DfsRet ret{};
	for (auto edge : g[index])
	{
		if (!visited[edge.connecting] && g[edge.connecting].size() > 1)
		{
			ret &= dfs(edge.connecting) + edge.time;
		}
	}
	return ret;
}

int main()
{
	while (true)
	{
		cin >> N;
		if (N == 0)
		{
			return 0;
		}

		g = vector<vector<Edge>>(N + 1);
		visited = vector<bool>(N + 1);
		for (int i = 0; i < N - 1; ++i)
		{
			int a, b, t;
			cin >> a >> b >> t;
			g[a].push_back(Edge{ b, t });
			g[b].push_back(Edge{ a, t });
		}

		DfsRet ret = dfs(1);
		cout << ret.time_to_visit_all*2 - ret.time_to_visit_deepest << endl;
	}
}
