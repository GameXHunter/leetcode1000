#include <functional> // °üº¬ std::hash
#include<string>
#include<iostream>


int main_test_hash()
{
	std::hash<std::string> hasher;
	size_t h1 = hasher("hello");
	size_t h2 = hasher("hello");

	std::cout << h1 << ", " << h2 << std::endl;
	return 0;
}