#include "../common.hpp"
#include "../commonio.hpp"

using graph = std::map<std::string, std::vector<std::string>>;

graph parse_input (std::string filepath)
{
	std::ifstream input_file(filepath);
	std::string line;
	graph g;
	
	while (std::getline(input_file, line)) {
		std::istringstream iss(line);
		std::string a, b;
		std::getline(iss, a, '-');
		std::getline(iss, b);
		
		g[a].push_back(b);
		g[b].push_back(a);
	}
	return g;
}

u64 paths = 0;

void path (graph g, std::string node, std::vector<std::string> cpath, bool twice=true)
{
	cpath.push_back(node);
	for (auto adj_node : g[node]) {
		if (adj_node == "end") {
			paths++;
		}
		else if (std::all_of(adj_node.begin(), adj_node.end(), [](unsigned char c){ return std::isupper(c); })) {
			path(g, adj_node, cpath, twice);
		}
		else if (!contains(cpath, adj_node)) {
			path(g, adj_node, cpath, twice);
		}
		else if ((contains(cpath, adj_node) == 1) && !twice && adj_node != "start") {
			path(g, adj_node, cpath);
		}
	}
}

void solve ()
{
	graph g;
	g = parse_input("data/day12");
	
	std::map<std::string, s32> visited;
	for (auto e : g)
		visited[e.first] = 0;
	
	path (g, "start", std::vector<std::string>());
	std::cout << "Part 1 => " << paths << "\n";
	
	paths = 0;
	path (g, "start", std::vector<std::string>(), false);
	std::cout << "Part 2 => " << paths << "\n";
}

int main (void)
{
	std::cout << "AOC2021 Day 12 **\n";
	solve();
	return 0;
}
