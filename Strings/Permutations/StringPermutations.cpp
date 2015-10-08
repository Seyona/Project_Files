/*
	Out puts all permutations, but repeats some permutations more than once....
*/

#include<iostream>
#include<string>

void permutation(std::string prefix, std::string str) {
	int n = str.size();
	if (n == 0) {
		std::cout << prefix << std::endl ;
	}
	else {
		for (int i = 0; i < n; i++) {
			permutation(prefix + str[i], str.substr(0, i) + str.substr(i + 1, n));
		}
	}
}


void permutation(std::string str) {
	permutation("", str);
}

int main() {
	permutation("tree");
}