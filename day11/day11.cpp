#include "../common.hpp"
#include "../commonio.hpp"

u32 flashes = 0;

std::vector<std::vector<u32>> parse_input (std::string filepath)
{
	std::ifstream input_file(filepath);
	std::vector<std::vector<u32>> octos;
	std::string line;
	while (std::getline(input_file, line)) {
		std::istringstream iss(line);
		std::vector<u8> octo_line((std::istream_iterator<u8>(iss)), std::istream_iterator<u8>());
		octos.push_back(convert_vchar_v<u32>(octo_line));
	}
	return octos;
}

void flash (std::vector<std::vector<u32>> &octos, sz i, sz j)
{
	if (octos[i][j] < 10)
		return;
	octos[i][j] = 0;
	flashes++;
	const auto look_to = [&](sz i, sz j) {
		if (!octos[i][j])
			return;
		octos[i][j]++;
		flash(octos, i, j);
	};
	bool ok1 = false, ok2 = false;
	bool ok3 = false, ok4 = false;
	if (i != 0) {
		look_to(i - 1, j);
		ok1 = true;
	}
	if (j != 0) {
		look_to(i, j - 1);
		ok2 = true;
	}
	if (ok1 && ok2)
		look_to(i - 1, j - 1);
	if (i != (octos[0].size() - 1)) {
		ok3 = true;
		look_to(i + 1, j);
	}
	if (j != (octos[0].size() - 1)) {
		ok4 = true;
		look_to(i, j + 1);
	}
	if (ok3 && ok4)
		look_to(i + 1, j + 1);
	if (ok1 && ok4)
		look_to(i - 1, j + 1);
	if (ok2 && ok3)
		look_to(i + 1, j - 1);
}

u32 solve (std::vector<std::vector<u32>> octos, u32 arg1=0)
{
	const auto step = [&]() {
		for (auto &line : octos)
			for (auto &el : line)
				el += 1;
		for (sz i = 0; i < octos.size(); ++i)
			for (sz j = 0; j < octos[0].size(); ++j)
				if (octos[i][j] > 9)
					flash(octos, i, j);
	};
	const auto all_flashed = [&]() {
		for (auto line : octos)
			for (auto el : line)
				if (el != 0)
					return false;
		return true;
	};

	if (arg1 > 0) {
		flashes = 0;
		u32 nod = arg1;
	
		while (nod) {
			--nod;
			step();
		}

		return flashes;
	}

	u32 nod = 0;
	while (!all_flashed()) {
		nod++;
		step();
	}
	return nod;
}

int main (void)
{
	std::cout << "AOC2021 Day 11 **\n";
	std::vector<std::vector<u32>> octos = parse_input("data/day11");
	std::cout << "Part 1 => " << solve(octos, 100) << "\n";
	std::cout << "Part 2 => " << solve(octos) << "\n";
	return 0;
}
