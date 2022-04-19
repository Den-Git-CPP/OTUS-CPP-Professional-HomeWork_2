
#include <iostream>
#include "IPFilter.h"

int main() {
	IPFilter* IP_Filter_1 = nullptr;
	IP_Filter_1 = new IPFilter("ip_filter.tsv");
	IP_Filter_1->sort_greater();
	IP_Filter_1->print_all_elem();
	IP_Filter_1->subsequent_filter(1);
	IP_Filter_1->subsequent_filter(46, 70);
	IP_Filter_1->any_filter(46);
	
	delete IP_Filter_1;
}

