#pragma once

class UnionFind
{
public:
	UnionFind(size_t n) : parent(n, -1) {}
	
	void init(size_t n)
	{
		parent.assign(n, -1);
	}

	int root(int x)
	{
		int x_parent = parent[x];
		if (x_parent < 0)
		{
			return x;
		}
		else
		{
			return parent[x] = root(x_parent);
		}
	}

	bool unite(int x, int y)
	{
		int x_parent = root(x);
		int y_parent = root(y);
		if (x_parent == y_parent)
		{
			return false;
		}
		else if (x_parent < y_parent)
		{
			parent[x_parent] += parent[y_parent];
			parent[y_parent] = x_parent;
			return true;
		}
		else
		{
			parent[y_parent] += parent[x_parent];
			parent[x_parent] = y_parent;
			return true;
		}
	}

	bool same(int x, int y)
	{
		return root(x) == root(y);
	}

	int size(int x)
	{
		return -parent[root(x)];
	}

private:
	// negative(parent): num of members
	// positive(child) : parent index
	std::vector<int> parent;
};

// min value
class UnionFind
{
public:
	UnionFind(size_t n) : parent(n) {}
	
	void setValue(size_t i, int value)
	{
		parent[i] = -value;
	}

	int root(int x)
	{
		int x_parent = parent[x];
		if (x_parent < 0)
		{
			return x;
		}
		else
		{
			return parent[x] = root(x_parent);
		}
	}

	bool unite(int x, int y)
	{
		int x_parent = root(x);
		int y_parent = root(y);
		if (x_parent == y_parent)
		{
			return false;
		}

		int x_minus_value = parent[x_parent];
		int y_minus_value = parent[y_parent];
		if (x_minus_value < y_minus_value)
		{
			parent[x_parent] = y_parent;
			return true;
		}
		else
		{
			parent[y_parent] = x_parent;
			return true;
		}
	}

	bool same(int x, int y)
	{
		return root(x) == root(y);
	}

	int value(int x)
	{
		return -parent[root(x)];
	}

private:
	// negative(parent): min value
	// positive(child) : parent_index
	std::vector<int> parent;
};

#include <vector>
class union_find
{
private:
	std::vector<size_t> parent;
	std::vector<size_t> rank;
public:
	union_find(size_t n) :
		parent(n),
		rank(n)
	{
		for (size_t i = 0; i < n; ++i)
			parent[i] = i;
	}
	size_t find(size_t x)
	{
		if (parent[x] == x)
			return x;
		else
			return parent[x] = find(parent[x]);
	}
	void unite(size_t x, size_t y)
	{
		size_t x_parent = find(x);
		size_t y_parent = find(y);
		if (x_parent == y_parent)
			return;
		if (rank[x] < rank[y])
			parent[x] = y;
		else
		{
			parent[y] = x;
			if (rank[x] == rank[y])
				++rank[x];
		}
	}
	bool is_same(size_t x, size_t y)
	{
		return find(x) == find(y);
	}
};

#include <unordered_map>
template <class TYPE, class TYPE_HASH>
class union_find
{
private:
	std::unordered_map<TYPE, TYPE, TYPE_HASH> parent_;
	std::unordered_map<TYPE, int, TYPE_HASH> loop_;
public:
	TYPE find(TYPE x)
	{
		auto itr = parent_.find(x);
		if (itr == parent_.end())
			return x;
		else
		{
			TYPE parent = itr->second;
			return parent_[x] = find(parent);
		}
	}
	// returns num of loop
	int unite(TYPE x, TYPE y)
	{
		TYPE x_parent = find(x);
		TYPE y_parent = find(y);
		if (x_parent == y_parent)
		{
			return loop_[x_parent] += 1;
		}
		parent_[y_parent] = x_parent;

		int ret = loop_[x_parent] += loop_[y_parent];
		loop_.erase(y_parent);
		return ret;
	}
	bool is_same(TYPE x, TYPE y)
	{
		return find(x) == find(y);
	}
};

class PairHash
{
public:
	size_t operator()(const std::pair<int, int>& obj) const
	{
		return obj.first * 1000 + obj.second;
	}
};
