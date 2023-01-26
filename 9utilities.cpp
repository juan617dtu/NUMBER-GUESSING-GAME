#include <time.h>
#include <regex>
#include "utilities.h"

std::string l_trim(const std::string& s) {

	return std::regex_replace(s, std::regex("^\\s+"), std::string(""));
}

std::string t_trim(const std::string& s) {

	return std::regex_replace(s, std::regex("^\\s+$"), std::string(""));
}

std::string trim(const std::string& s) {

	return l_trim(t_trim(s));
}

int random_int(int l) {

	srand(time(0));
	int r = rand() % l;
	return r;
}
