#include"statistics.hpp"

statistics::statistics(vector<item> items_s)
{
	items_p = items_s;
	return;
}

set<std::__cxx11::string> statistics::zones()
{
	set<string> zones_p;
	for (auto& item:items_p)
	{
		zones_p.insert(item.zone());
	}
	return zones_p;
}

set<std::__cxx11::string> statistics::owners()
{
	set<string> owners_p;
	for (auto& item:items_p)
	{
		owners_p.insert(item.owner());
	}
	return owners_p;
}

set<std::__cxx11::string> statistics::item_names()
{
	set<string> item_names_p;
	for (auto& item:items_p)
	{
		item_names_p.insert(item.name());
	}
	return item_names_p;
}

map<std::__cxx11::string, double> statistics::date_to_count_relative(std::__cxx11::string item_name, std::__cxx11::string time_period)
{
	map<string,double> date_to_count_relative_p;
	map<string,int> date_to_count_r = date_to_count(item_name, time_period);
	map<string,int> date_to_TOTAL = date_to_count("", time_period);
	double item_count;
	double total_count;
	for (auto& d_to_total:date_to_TOTAL)
	{
		item_count = date_to_count_r[d_to_total.first];
		total_count = d_to_total.second;
		date_to_count_relative_p[d_to_total.first]=item_count/total_count;
	}
	return date_to_count_relative_p;
}

map<std::__cxx11::string, int> statistics::date_to_count(std::__cxx11::string item_name, std::__cxx11::string time_period)
{
	map<string,int> date_to_count_p;
	string date;
	for (auto& item:items_p)
	{
		if (item_name!="" && item.name()!=item_name) continue;
// 		if (zone!="" && item.zone()!=zone) continue;
// 		if (owner!="" && item.owner()!=owner) continue;
// 		if (date!="" && item.date().find(date)==string::npos) continue;
// 		tools::time::string_to_time_t(item.date())
// 		tm loot_tm = tools::time::string_time_to_tm_structure(item.date());
// 		cout <<"wday:" <<  loot_tm.tm_wday << "\t"  << item.date() << endl;
		
		if (time_period=="hour")
			date = item.year() + "-" + item.month() + "-" + item.day() + " " + item.hour();
		else if (time_period=="day")
			date = item.year() + "-" + item.month() + "-" + item.day();
		else if (time_period=="month")
			date = item.year() + "-" + item.month();
		else if (time_period=="year")
			date = item.year();
// 		else if (time_period=="wday") // week day
// 			date = item.year();
		else
			date = "all";
		
		if (date_to_count_p.find(date)==date_to_count_p.end())
			date_to_count_p[date]=1;
		else
			date_to_count_p[date]++;
	}
	return date_to_count_p;
}
