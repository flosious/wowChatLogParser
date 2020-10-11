#include "logfiles_t.hpp"

logfiles_t::logfiles_t(int argc, char ** argv)
{
	logfilenames_p.clear();
	for (int i=1;i<argc;i++)
		logfilenames_p.push_back(argv[i]);
}

vector<std::__cxx11::string> logfiles_t::logfilenames()
{
	return logfilenames_p;
}

bool logfiles_t::parse()
{
	items_p.clear();
	for (auto& filename:logfilenames_p)
	{
		string contents = tools::file::load_file_to_string(filename);
		vector<string> lines = tools::str::get_strings_between_delimiter(contents,"\n");
		for (auto& line: lines)
		{
			item item_p(tools::str::remove_linebreakers_from_string(line));
			if (item_p.parsed()) items_p.insert(item_p);
		}
	}
	return true;
}

set<item> logfiles_t::items()
{
	if (items_p.size()>0) 
		return items_p;
	
	parse();
	return items_p;
}

vector<item> logfiles_t::items_vec()
{
	if (items().size()==0) 
		return {};
	
	vector<item> items_vec_p(items_p.begin(),items_p.end());
	return items_vec_p;
}

set<std::__cxx11::string> logfiles_t::zones()
{
	set<string> zones_p;
	for (item it:items())
	{
		zones_p.insert(it.zone());
	}
	return zones_p;
}

set<std::__cxx11::string> logfiles_t::owners()
{
	set<string> owners_p;
	for (item it:items())
	{
		owners_p.insert(it.owner());
	}
	return owners_p;
}

vector<item> logfiles_t::items(std::__cxx11::string zone_, std::__cxx11::string owner_)
{
	vector<item> items_;
	for (auto it:items())
	{
		if (owner_ != "" && it.owner() != owner_) continue;
		if (zone_ != "" && it.zone() != zone_) continue;
		items_.push_back(it);
	}
	return items_;
}

// map<std::__cxx11::string, std::__cxx11::string> logfiles_t::date_to_item_name(string item_name_, std::__cxx11::string zone_, std::__cxx11::string owner_)
// {
// 	map<string,string> date_to_name;
// 	
// 	for (auto& it:items(zone_,owner_))
// 	{
// 		date_to_name[it.date()]=it.name();
// 	}
// 	return date_to_item_name()
// }
