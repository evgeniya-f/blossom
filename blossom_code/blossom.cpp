#include "blossom.h"



const int MAXN = 10; // максимально возможное число вершин во входном графе


//нахождение ближайшего предка
int lca(int a, int b, std::vector<int>& base, std::vector<int>& match, std::vector<int>& p) {
	std::vector<bool> used;
	used.resize(base.size(), false);
	// поднимаемся от вершины a до корня, помечая все чётные вершины
	for (;;) {
		a = base[a];
		used[a] = true;
		if (match[a] == -1)  break; // дошли до корня
		a = p[match[a]];
	}
	// поднимаемся от вершины b, пока не найдём помеченную вершину
	for (;;) {
		b = base[b];
		if (used[b])  return b;
		b = p[match[b]];
	}
}
//обозначение доп. пути 
void mark_path(int v, int b, int children, std::vector<int>& base, std::vector<int>& match, std::vector<int>& p, std::vector<bool>& blossom) {
	while (base[v] != b) {
		blossom[base[v]] = blossom[base[match[v]]] = true;
		p[v] = children;
		children = match[v];
		v = p[match[v]];
	}
}

//поиск доп. пути из свободной вершины root и возвращает последнюю вершину этого пути, либо -1, если ув. путь не найден
int find_path(int root, std::vector<std::vector<int>> &g, std::vector<int> &match, std::vector<int>& p) {
	p.clear();
	p.resize(g.size(), -1);

	std::vector<bool> used;
	used.resize(g.size(), false);
	std::vector<bool> blossom;
	std::vector<int> q;
	q.resize(g.size(), 0);
	std::vector<int> base;

	for (int i = 0; i < g.size(); i++)
		base.push_back(i);

	//обход в ширину
	used[root] = true;
	int qh = 0, qt = 0;
	q[qt++] = root;
	while (qh < qt) {
		int v = q[qh++];
		for (size_t i = 0; i < g[v].size(); i++) {
			int to = g[v][i];
			if (base[v] == base[to] || match[v] == to)  continue;
			if (to == root || match[to] != -1 && p[match[to]] != -1) {
				int curbase = lca(v, to, base, match, p);
				
				blossom.clear();
				blossom.resize(g.size(), false);

				mark_path(v, curbase, to, base, match, p, blossom);
				mark_path(to, curbase, v, base, match, p, blossom);
				for (int i = 0; i < g.size(); i++)
					if (blossom[base[i]]) {
						base[i] = curbase;
						if (!used[i]) {
							used[i] = true;
							q[qt++] = i;
						}
					}
			}
			else if (p[to] == -1) {
				p[to] = v;
				if (match[to] == -1)
					return to;
				to = match[to];
				used[to] = true;
				q[qt++] = to;
			}
		}
	}
	return -1;
}

int get_match(std::vector<std::vector<int>>& g, std::vector<int>& match) {

	match.clear();
	match.resize(g.size(), -1);
	std::vector<int> p;
	p.resize(g.size(), -1);

	//запуск поиска пути из каждой вертев графа, проставление паросочетания
	for (int i = 0; i < g.size(); i++) {
		if (match[i] == -1) {
			int v = find_path(i, g, match, p);
			while (v != -1) {
				int pv = p[v], ppv = match[pv];
				match[v] = pv, match[pv] = v;
				v = ppv;
			}
		}
	}
	return 0;
}

void print_match(std::vector<int>& a) {
	for (int i = 0; i < a.size(); i++) {
		if (i < a[i]) {
			std::cout << i << '-' << a[i] << "\n";
		}
	}
}
