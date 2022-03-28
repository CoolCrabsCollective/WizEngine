//
// Created by Alexander Winter on 2022-02-10.
//

#ifndef GAMETEMPLATE_STRINGUTIL_H
#define GAMETEMPLATE_STRINGUTIL_H

#include <string>
#include <algorithm>
#include <cctype>
#include <locale>

namespace wiz {
	inline bool ends_with(const std::string& value, const std::string& ending) {
		if(ending.size() > value.size())
			return false;

		return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
	}

	inline std::vector<std::string> split(const std::string& string, char delim) {
		std::vector<std::string> vec;

		std::stringstream ss(string);
		std::string word;

		while(std::getline(ss, word, delim)) {
			vec.push_back(word);
		}
		return vec;
	}

	// trim from start (in place)
	inline void ltrim(std::string& s) {
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
			return !std::isspace(ch);
		}));
	}

	// trim from end (in place)
	inline void rtrim(std::string& s) {
		s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
			return !std::isspace(ch);
		}).base(), s.end());
	}

	// trim from both ends (in place)
	inline void trim(std::string& s) {
		ltrim(s);
		rtrim(s);
	}

	// trim from start (copying)
	inline std::string ltrim_copy(std::string s) {
		ltrim(s);
		return s;
	}

	// trim from end (copying)
	inline std::string rtrim_copy(std::string s) {
		rtrim(s);
		return s;
	}

	// trim from both ends (copying)
	inline std::string trim_copy(std::string s) {
		trim(s);
		return s;
	}
}



#endif //GAMETEMPLATE_STRINGUTIL_H
