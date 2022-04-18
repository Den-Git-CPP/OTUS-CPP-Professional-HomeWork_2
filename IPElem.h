#pragma once
#include <iostream>
#include <ostream>
#include <vector>
#include <tuple>
class IPElem {
public:
	IPElem();
	IPElem(int n1, int n2, int n3, int n4, std::string field2, std::string field3);

	~IPElem() {};
	int _n_1 {};
	int _n_2 {};
	int _n_3 {};
	int _n_4 {};

	friend inline  bool operator<(const IPElem& lhs, const IPElem& rhs) {
		return	std::tie(lhs._n_1, lhs._n_2, lhs._n_3, lhs._n_4) <
			std::tie(rhs._n_1, rhs._n_2, rhs._n_3, rhs._n_4);
	}
	friend inline  bool operator>(const IPElem& lhs, const IPElem& rhs) {
		return	std::tie(lhs._n_1, lhs._n_2, lhs._n_3, lhs._n_4) >
			std::tie(rhs._n_1, rhs._n_2, rhs._n_3, rhs._n_4);
	}
	friend std::ostream& operator<<(std::ostream& os, const IPElem& elem) {
		return os << elem._n_1 << "."
			<< elem._n_2 << "."
			<< elem._n_3 << "."
			<< elem._n_4;
	}
private:
	std::string _field2 {};
	std::string _field3 {};
};
