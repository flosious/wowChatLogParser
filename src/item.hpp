
#ifndef item_hpp

#define item_hpp

#include<string>
#include<fstream>
#include<regex>
#include<vector>
#include<iostream>
#include"tools.hpp"
#include<list>
#include<set>

using namespace std;

class item
{
private:
	string owner_p="Xtra";
	string zone_p="Southbreak Shore";
	string year_p="2020";
	string line;
	string name_p;
	string hour_p;
	string day_p;
	string month_p;
	string min_p;
	string sec_p;
	string msec_p;
	
	bool parsed_p=false;
	bool parse();
	bool checked=false;
public:
	void to_screen();
	bool parsed();
	string zone();
	string name();
	string year();
	string month();
	string day();
	string hour();
	string min();
	string sec();
	string msec();
	string owner();
	string date();
	item();
	item(string line_p);
// 	static void remove_double_entries(vector<item>& items_p);
// 	static vector<item> items(int argc, char ** argv);
// 	static vector<item> items(vector<string> filenames);
// 	static vector<item> items(string filename);
	
	bool operator==(item& i);
	bool const operator<(const item& i) const;
};

#endif // item_hpp
