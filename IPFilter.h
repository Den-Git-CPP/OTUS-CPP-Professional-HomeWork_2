#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <string>
#include <stdexcept>
#include <algorithm>

#include"IPElem.h"

class IPFilter {
public:
	IPFilter();
	IPFilter(const std::filesystem::path& file_data_patch);
	~IPFilter();
	void sort_greater();
	void print_all_elem();
	template<typename... Args>
	void subsequent_filter(Args... args);
	void any_filter(int part);
private:
	std::vector<IPElem> all_IPElem;
	std::vector<std::string> split(const std::string& str, char d);
};

template<typename ...Args>
inline void IPFilter::subsequent_filter(Args ...args) {
	std::vector<int> v_parts {args...};
	switch (v_parts.size()) {
		case 1:
			for_each(all_IPElem.begin(), all_IPElem.end(),
					 [=](const IPElem& elem) {
						 if (elem._n_1 == v_parts.at(0)) {
							 std::cout << elem << "\n";
						 };
					 });
			break;
		case 2:
			for_each(all_IPElem.begin(), all_IPElem.end(),
					 [=](const IPElem& elem) {
						 if ((elem._n_1 == v_parts.at(0)) &&
							 (elem._n_2 == v_parts.at(1))) {
							 std::cout << elem << "\n";
						 };
					 });
			break;
		case 3:
			for_each(all_IPElem.begin(), all_IPElem.end(),
					 [=](const IPElem& elem) {
						 if ((elem._n_1 == v_parts.at(0)) &&
							 (elem._n_2 == v_parts.at(1)) &&
							 (elem._n_2 == v_parts.at(2))) {
							 std::cout << elem << "\n";
						 };
					 });
			break;
		case 4:
			for_each(all_IPElem.begin(), all_IPElem.end(),
					 [=](const IPElem& elem) {
						 if ((elem._n_1 == v_parts.at(0)) &&
							 (elem._n_2 == v_parts.at(1)) &&
							 (elem._n_2 == v_parts.at(2)) &&
							 (elem._n_2 == v_parts.at(3))) {
							 std::cout << elem << "\n";
						 };
					 });
			break;

		default:
			std::cout << "Invalid IP parts." << v_parts.size() << "\n";
			std::cout << "\n\n";
			break;
	}
}
