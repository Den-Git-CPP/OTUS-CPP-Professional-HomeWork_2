#include <gtest/gtest.h>
#include "test.h"

TEST(IPFilter_Test, Initialization)
{	IPFilter_Test ipf("ip_filter.tsv");
  size_t size_IPFilter_Test=ipf.size();
	ASSERT_EQ(size_IPFilter_Test, 1000);
}

TEST(IPFilter_Test, Sort_Greater)
{	IPFilter_Test ipf("ip_filter.tsv");
  ipf.sort_greater();
  EXPECT_EQ(ipf.all_IPElem[0],IPElem(222,173,235,246," "," ")); 
  EXPECT_EQ(ipf.all_IPElem[1],IPElem(222,130,177,64," "," ")); 
  EXPECT_EQ(ipf.all_IPElem[2],IPElem(222,82,198,61," "," "));
  EXPECT_EQ(ipf.all_IPElem[ipf.all_IPElem.size()-3],IPElem(1,70,44,170," "," "));
  EXPECT_EQ(ipf.all_IPElem[ipf.all_IPElem.size()-2],IPElem(1,29,168,152," "," "));
  EXPECT_EQ(ipf.all_IPElem[ipf.all_IPElem.size()-1],IPElem(1,1,234,8," "," "));
}

TEST(IPFilter_Test, Subsequent_filter_1)
{ IPFilter_Test ipf("ip_filter.tsv");
  ipf.sort_greater();
  /*ip = filter(1)
    // 1.231.69.33
	  // 1.87.203.225
	  // 1.70.44.170
	  // 1.29.168.152
	  // 1.1.234.8;
  */
  std::stringstream buffer,strm;
  strm<<"1.231.69.33\n"
	    <<"1.87.203.225\n"
	    <<"1.70.44.170\n"
    	<<"1.29.168.152\n"
	    <<"1.1.234.8\n";
  std::streambuf *sbuf =std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());
	ipf.subsequent_filter(1);//cout filter(1)
  std::cout.rdbuf(sbuf);
	ASSERT_EQ(buffer.str(), strm.str());
}

TEST(IPFilter_Test, Subsequent_filter_46_70)
{ IPFilter_Test ipf("ip_filter.tsv");
  ipf.sort_greater();
  /* ip = filter(46, 70)
    // 46.70.225.39
    // 46.70.147.26
    // 46.70.113.73
    // 46.70.29.76
	*/
  std::stringstream buffer,strm;
  strm<<"46.70.225.39\n"
	    <<"46.70.147.26\n"
	    <<"46.70.113.73\n"
    	<<"46.70.29.76\n";
	std::streambuf *sbuf =std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());
	ipf.subsequent_filter(46,70);//cout filter(1)
  std::cout.rdbuf(sbuf);

	ASSERT_EQ(buffer.str(), strm.str());
}

TEST(IPFilter_Test, Any_Filter_46)
{ IPFilter_Test ipf("ip_filter.tsv");
  ipf.sort_greater();
 /*ip = filter(1)
  // 186.204.34.46
  // 186.46.222.194
  // 185.46.87.231
  // 185.46.86.132
  // 185.46.86.131
  // 185.46.86.131
  // 185.46.86.22
  // 185.46.85.204
  // 185.46.85.78
  // 68.46.218.208
  // 46.251.197.23
  // 46.223.254.56
  // 46.223.254.56
  // 46.182.19.219
  // 46.161.63.66
  // 46.161.61.51
  // 46.161.60.92
  // 46.161.60.35
  // 46.161.58.202
  // 46.161.56.241
  // 46.161.56.203
  // 46.161.56.174
  // 46.161.56.106
  // 46.161.56.106
  // 46.101.163.119
  // 46.101.127.145
  // 46.70.225.39
  // 46.70.147.26
  // 46.70.113.73
  // 46.70.29.76
  // 46.55.46.98
  // 46.49.43.85
  // 39.46.86.85
  // 5.189.203.46
*/
  std::stringstream buffer,strm;
  strm<<"186.204.34.46\n"
      <<"186.46.222.194\n"
      <<"185.46.87.231\n"
      <<"185.46.86.132\n"
      <<"185.46.86.131\n"
      <<"185.46.86.131\n"
      <<"185.46.86.22\n"
      <<"185.46.85.204\n"
      <<"185.46.85.78\n"
      <<"68.46.218.208\n"
      <<"46.251.197.23\n"
      <<"46.223.254.56\n"
      <<"46.223.254.56\n"
      <<"46.182.19.219\n"
      <<"46.161.63.66\n"
      <<"46.161.61.51\n"
      <<"46.161.60.92\n"
      <<"46.161.60.35\n"
      <<"46.161.58.202\n"
      <<"46.161.56.241\n"
      <<"46.161.56.203\n"
      <<"46.161.56.174\n"
      <<"46.161.56.106\n"
      <<"46.161.56.106\n"
      <<"46.101.163.119\n"
      <<"46.101.127.145\n"
      <<"46.70.225.39\n"
      <<"46.70.147.26\n"
      <<"46.70.113.73\n"
      <<"46.70.29.76\n"
      <<"46.55.46.98\n"
      <<"46.49.43.85\n"
      <<"39.46.86.85\n"
      <<"5.189.203.46\n";
	std::streambuf *sbuf =std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());
	ipf.any_filter(46);//cout any_filter(46)
  std::cout.rdbuf(sbuf);

	ASSERT_EQ(buffer.str(), strm.str());
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}

