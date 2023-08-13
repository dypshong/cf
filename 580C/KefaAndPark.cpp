#include <iostream>
#include <vector>


struct Node {
	int id;
	int visited;
	int cat;
	int parent;
	int togo;
	std::vector<Node*> neighbors;
	std::vector<Node*> children;
};

void dfs(Node *node, int parent, int cons, int max_cons, int m) {
	node->parent = parent;
	node->visited = 1;

	if (node->cat) {
		cons++; 
		max_cons = std::max(max_cons, cons);
	} else {
		cons = 0;
	}

	node->togo = max_cons <= m ? 1 : 0;

	for (auto child : node->neighbors) {
		if (!child->visited) {
			node->children.push_back(child);
			dfs(child, node->id, cons, max_cons, m);
		}
	}

}

int main()
{
	int n, m;
	std::cin >> n >> m;

	std::vector<Node> nodes(n+1);
	std::vector<int> cats(n+1);

	for (int i = 1; i <= n; ++i) {
		std::cin >> cats[i];
	}

	for (int i = 1; i <= n; ++i) {
		nodes[i].id = i;
		nodes[i].visited = 0;
		nodes[i].togo = 1;
		nodes[i].cat = cats[i];
	}
	nodes[0].cat = 0;

	for (int k = 0; k < n - 1; ++k) {
		int i, j;
		std::cin >> i >> j;
		nodes[i].neighbors.push_back(&nodes[j]);
		nodes[j].neighbors.push_back(&nodes[i]);
	}

	dfs(&nodes[1], 0, 0, 0, m);

	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (nodes[i].children.size() == 0 && nodes[i].togo) {
			++sum;
		}
	}

	std::cout << sum << "\n";

	return 0;
}
