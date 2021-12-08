#include "../common.h"

void solve_part1 (std::string filepath)
{
	std::ifstream input_file(filepath);
	std::string input, skip;
	u64 appearances = 0;
	while (std::getline(input_file, skip, '|')) {
		for (u8 i = 0; i < 4; ++i) {
			input_file >> input;
			switch (input.length()) {
			case 2: 
			case 3: 
			case 4: 
			case 7: appearances += 1; break;
			}
		}
	}
	std::cout << "Part 1 => " << appearances << "\n";
}

u64 solve_line_part2 (std::istream &input_file)
{
	std::array <std::bitset<7>, 10> digits;
	std::array <std::bitset<7>, 10> patterns;
	std::array <unsigned char, 1 << 7> mapping;
	std::string input;
	const auto set_pattern = [&](std::bitset<7> pattern, u8 digit) {
		digits[digit] = pattern;
		mapping[pattern.to_ullong()] = digit;
	};
	
	for (auto &pattern : patterns) {
		input_file >> input;
		for (char c : input) pattern[c - 'a'] = true;
	}
	/* set basic patterns */
	for (auto pattern : patterns) {
		switch (pattern.count()) {
		case 2: set_pattern(pattern, 1); break; /* 1 */
		case 3: set_pattern(pattern, 7); break;	/* 7 */
		case 4: set_pattern(pattern, 4); break;	/* 4 */
		case 7: set_pattern(pattern, 8); break;	/* 8 */
		}
	}
	/* set medium patterns */
	for (auto pattern : patterns) {
		if (pattern.count() == 6) {
			if ((pattern & digits[4]) == digits[4])
				set_pattern(pattern, 9);
			else if ((pattern & digits[1]) == digits[1])
				set_pattern(pattern, 0);
			else
				set_pattern(pattern, 6);
		}
	}
	/* set hard patterns */
	for (auto pattern : patterns) {
		if (pattern.count() == 5) {
			if ((pattern & digits[1]) == digits[1])
				set_pattern(pattern, 3);
			else if ((digits[6] & pattern) == pattern)
				set_pattern(pattern, 5);
			else
				set_pattern(pattern, 2);
		}
	}
	/* calc number, now that we mapped all digits */
	input_file.ignore(3);
	u64 num = 0;
	for (u8 i = 0; i < 4; ++i) {
		input_file >> input;
		std::bitset<7> pattern;
		for (char c : input) pattern[c - 'a'] = true;
		u8 digit = mapping[pattern.to_ullong()];
		num *= 10;
		num += digit;
	}
	return num;
}

void solve_part2 (std::string filepath)
{
	std::ifstream input_file(filepath);
	u64 sum = 0;
	while (!input_file.eof())
		sum += solve_line_part2(input_file);
	std::cout << "Part 2 => " << sum << "\n";
}

int main (void)
{
	std::cout << "AOC2021 Day 8 **" << std::endl;
	solve_part1("data/day8");
	solve_part2("data/day8");
	return 0;
}
