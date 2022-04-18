#include "IPFilter.h"

IPFilter::IPFilter(const std::filesystem::path& file_data_patch) {
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

IPFilter::~IPFilter() {
	for (auto elem : all_IPElem) {
		elem.~IPElem();
	}
}

std::vector<std::string> IPFilter::split(const std::string& str, char d) {
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

void IPFilter::sort_greater() {
	std::sort(all_IPElem.begin(), all_IPElem.end(), std::greater<IPElem>());
}

void IPFilter::print_all_elem() {
	for (auto elem : all_IPElem) {
		std::cout << elem << "\n";
	}
}

void IPFilter::any_filter(int part) {
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
