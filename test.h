#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

#include"IPElem.h"

class IPFilter_Test {
public:
	IPFilter_Test();
	IPFilter_Test(const std::string& file_data_patch);
	~IPFilter_Test();
	void sort_greater();
	void print_all_elem();
	template<typename... Args>
	void subsequent_filter(Args... args);
	void any_filter(int part);
	size_t size(){return all_IPElem.size();}
	std::vector<IPElem> all_IPElem;
	std::vector<std::string> split(const std::string& str, char d);
};

template<typename ...Args>
inline void IPFilter_Test::subsequent_filter(Args ...args) {
	
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

IPFilter_Test::IPFilter_Test(const std::string& file_data_patch) {
	std::ifstream infile;
	infile.open(file_data_patch);

	if (!infile) {
		std::cout << "Can't open data file : " << file_data_patch << "\n";
		exit(EXIT_FAILURE);
	}
	std::string ip_line;

	while (std::getline(infile, ip_line)) {
		std::vector<std::string> v_split_line {split(ip_line,'\t')};
		std::vector<std::string> v_split_ip {split(v_split_line.at(0),'.')};

		if (v_split_ip.size() != 4) {
			throw std::invalid_argument("Invalid IP address");
		}

		int ip0 {std::stoi(v_split_ip.at(0))};
		int ip1 {std::stoi(v_split_ip.at(1))};
		int ip2 {std::stoi(v_split_ip.at(2))};
		int ip3 {std::stoi(v_split_ip.at(3))};
		if (ip0 < 0 || ip0 > 255 ||
			ip1 < 0 || ip1 > 255 ||
			ip2 < 0 || ip2 > 255 ||
			ip3 < 0 || ip3 > 255) {
			throw std::invalid_argument("Invalid IP parts. Parts must be 0 to 255");
		}

		try {
			IPElem* ptr_ip_elem = new IPElem(ip0, ip1, ip2, ip3,
											 v_split_line.at(1),
											 v_split_line.at(2)
			);
			all_IPElem.push_back(*ptr_ip_elem);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << "\t Function::load_data\n";
		}
	}
	infile.close();
}

IPFilter_Test::~IPFilter_Test() {
	for (auto elem : all_IPElem) {
		elem.~IPElem();
	}
}

std::vector<std::string> IPFilter_Test::split(const std::string& str, char d) {
	std::vector<std::string> r;
	std::string::size_type start = 0;
	std::string::size_type stop = str.find_first_of(d);
	while (stop != std::string::npos) {
		r.push_back(str.substr(start, stop - start));
		start = stop + 1;
		stop = str.find_first_of(d, start);
	}
	r.push_back(str.substr(start));
	return r;
}

void IPFilter_Test::sort_greater() {
	std::sort(all_IPElem.begin(), all_IPElem.end(), std::greater<IPElem>());
}

void IPFilter_Test::print_all_elem() {
	for (auto elem : all_IPElem) {
			std::cout<<elem << "\n";
	}
}

void IPFilter_Test::any_filter(int part) {
	for_each(all_IPElem.begin(), all_IPElem.end(),
			 [part](IPElem elem) {
				 if ((elem._n_1 == part) ||
					 (elem._n_2 == part) ||
					 (elem._n_3 == part) ||
					 (elem._n_4 == part)) {
					 std::cout << elem << "\n";
				 };
			 });
}
