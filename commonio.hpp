#include <fstream>
#include <iostream>

/* prints a new line */
void print (void)
{
	std::cout << "\n";
}

/* prints std::vector */
template <typename T>
void print (std::vector<T> v)
{
	for (auto el : v)
		std::cout << el << " ";
	print();
}

/* prints std::vector<std::vector<>> */
template <typename T>
void print (std::vector<std::vector<T>> tdv)
{
	for (auto line : tdv) {
		print(line);
	}
}

/* writes to a file a new line */
void write (std::ofstream &file)
{
	file << "\n";
}

/* writes to a file std::vector */
template <typename T>
void write (std::ofstream &file, std::vector<T> v)
{
	for (auto el : v)
		file << el;
	write(file);
}

/* writes to a file std::vector<std::vector> */
template <typename T>
void write (std::ofstream &file, std::vector<std::vector<T>> tdv)
{
	for (auto line : tdv)
		write(file, line);
}
