
#include<iostream>
// #include"parser.hpp"
#include"statistics.hpp"
#include "item.hpp"
#include "logfiles_t.hpp"

using namespace std;

int main( int    argc, char **argv )
{
	if (argc<1) return 0;
	logfiles_t logfiles(argc, argv);
	cout << logfiles.items().size() << endl;
	statistics stats(logfiles.items("",""));
	
// 	map<string,double> date_to_count/* = stats.date_to_count()*/;
// 	date_to_count = ;
	for (auto& date:stats.date_to_count_relative("Golden Pearl","hour"))
	{
		cout << date.first << "\t" << date.second << endl;
	}
	return 0;
}
