
#ifndef statistics_hpp

#define statistics_hpp

#include"item.hpp"
#include<map>
#include <set>
#include<time.h>

using namespace std;

class statistics
{
private:
	vector<item> items_p;
public:
	
	statistics(vector<item> items_s);
	/// count vs date; intervall=day | hour | month; zones/name="" --> all zones/names; date: "YYYY-MM-DD HH-MM-SS.MSSS"
	map<string, int> date_to_count(string item_name="", string time_period="");
	/// similar to date_to_count but divided by total_count within the intervall
	map<string, double> date_to_count_relative(string item_name="", string time_period="");
	set<string> zones();
	set<string> owners();
	set<string> item_names();
};

#endif // statistics_hpp

