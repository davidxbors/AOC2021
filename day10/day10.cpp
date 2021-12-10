#include "../common.h"

int main (void)
{
	std::cout << "AOC2021 Day 10 **\n";

	std::ifstream input_file("data/day10");
	u8 input;
	u64 score = 0;
	std::string line;
	std::vector<u64> line_scores;
	
	while (std::getline(input_file, line)) {
		std::istringstream iss(line);
		std::stack<u8> brackets;
		bool incomplete = true;
		while (iss >> input) {
			if (input == '(' || input == '[' || input == '{' ||
			    input == '<')
				brackets.push(input);
			else {
				if (input == ')' && brackets.top() != '(') {
					incomplete = false;
					score += 3;
					break;
				}
				if (input == ']' && brackets.top() != '[') {
					incomplete = false;
					score += 57;
					break;
				}
				if (input == '}' && brackets.top() != '{') {
					incomplete = false;
					score += 1197;
					break;
				}
				if (input == '>' && brackets.top() != '<') {
					incomplete = false;
					score += 25137;
					break;
				}
				else brackets.pop();
			}

		}
		if (!brackets.empty() && incomplete) {
			u64 line_score = 0;
			const auto calc_score = [&](u64 char_score) {
				return line_score * 5 + char_score;
			};
			while (!brackets.empty()) {
				if (brackets.top() == '(')
					line_score = calc_score(1);
				if (brackets.top() == '[')
					line_score = calc_score(2);
				if (brackets.top() == '{')
					line_score = calc_score(3);
				if (brackets.top() == '<')
					line_score = calc_score(4);
				brackets.pop();
			}
			line_scores.push_back(line_score);
		}
	}
	std::cout << "Part 1 => " << score << "\n";
	std::nth_element(line_scores.begin(), (line_scores.begin() + line_scores.size()/2), line_scores.end());
	std::cout << "Part 2 => " << line_scores[line_scores.size()/2] << "\n";
	return 0;
}
