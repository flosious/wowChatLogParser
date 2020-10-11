
#ifndef logfiles_t_hpp

#define logfiles_t_hpp

#include<string>
#include<fstream>
#include<regex>
#include<vector>
#include<iostream>
#include"tools.hpp"
#include<list>
#include<set>
#include "item.hpp"

using namespace std;

class logfiles_t
{
private:
	vector<string> logfilenames_p;
	set<item> items_p;
public:
	/// will forcefully (re)parse all the items/lines from the logfiles
	bool parse();
	logfiles_t(int argc, char ** argv);
	/// names of the logfiles
	vector<string> logfilenames();
	/// returns all successfully parsed items in the logfiles
	vector<item> items_vec();
	/// returns all successfully parsed items in the logfiles
	set<item> items();
	/// returns all owners found in the parsed logfiles
	set<string> owners();
	/// returns all zones found in the parsed logfiles
	set<string> zones();
	/// returns items for a specific zone and/or owner
	vector<item> items(string zone_, string owner_);
	/// returns date->itenname for a specific zone and/or owner
// 	map<string,string> date_to_item_count(sting item_name_, string zone_, string owner_);
};

#endif // logfiles_t_hpp
