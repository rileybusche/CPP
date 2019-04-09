#include "split.hpp"
using namespace std;

void Split(vector<string> & tokens, string & line, string & delimeter) {
	tokens.clear();
	size_t pos;
	while ((pos = line.find(delimeter)) != string::npos) {
		tokens.push_back(line.substr(0, pos));
		line.erase(0, pos + delimeter.length());
	}
	if (line.length() > 0) {
		tokens.push_back(line);
	}
}