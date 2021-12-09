#include "../common.h"

std::vector<std::vector<u8>> parse_input (std::string filepath)
{
	std::ifstream input_file(filepath);
	std::vector<std::vector<u8>> caves;
	std::string line;
	while (std::getline(input_file,line)) {
		std::istringstream iss(line);
		std::vector<u8> cave((std::istream_iterator<u8>(iss)), std::istream_iterator<u8>());
		caves.push_back(cave);
	}
	return caves;
}

u32 solve_part_1 (std::vector<std::vector<u8>> caves)
{
	u32 result = 0;
	for (u8 i = 0; i < caves.size(); ++i) {
		for (u8 j = 0; j < caves[0].size(); ++j) {
			bool ok = true;
			if (i != 0 && caves[i][j] >= caves[i-1][j])
				ok = false;
			if (i != caves.size()-1 && caves[i][j] >= caves[i+1][j])
				ok = false;
			if (j != 0 && caves[i][j] >= caves[i][j-1])
				ok = false;
			if (j != caves[0].size()-1 && caves[i][j] >= caves[i][j+1])
				ok = false;
			if (ok) {
				result += static_cast<int>(caves[i][j] - 47); /* substract 48 to convert to int, add 1 because that's required by the challenge */
			}
		}
	}
	return result;
}

u32 boundary_fill (std::vector<std::vector<bool>> &visited, std::vector<std::vector<u8>> caves, u32 i, u32 j)
{
	u32 size = 0;
	if (static_cast<int>(caves[i][j] - 48) != 9) {
		size += 1;
		visited[i][j] = true;
		if (i != (caves.size() - 1) && !visited[i+1][j])
			size += boundary_fill(visited, caves, i+1, j);
		if (i != 0 && !visited[i-1][j])
			size += boundary_fill(visited, caves, i-1, j);
		if (j != (caves[0].size() - 1) && !visited[i][j+1])
			size += boundary_fill(visited, caves, i, j+1);
		if (j != 0 && !visited[i][j-1])
			size += boundary_fill(visited, caves, i, j-1);
	}
	return size;
}

u32 solve_part_2 (std::vector<std::vector<u8>> caves)
{
	std::vector<std::vector<bool>> visited(caves.size(), std::vector<bool>(caves[0].size()));
	std::multiset<u32, std::greater<u32>> basins;
	for (u8 i = 0; i < caves.size(); ++i) {
		for (u8 j = 0; j < caves[0].size(); ++j)
			basins.insert(boundary_fill(visited, caves, i, j));
	}
	std::multiset<u32>::iterator it = basins.begin();
	return *(it) * *(++it) * *(++it);
}

int main (void)
{
	std::cout << "AOC2021 Day 9\n";
	/* read input */
	std::vector<std::vector<u8>> caves;
	caves = parse_input("data/day9");
	
	std::cout << "Part 1 => " << solve_part_1(caves) << "\n";
	std::cout << "Part 2 => " << solve_part_2(caves) << "\n";
	return 0;
}
