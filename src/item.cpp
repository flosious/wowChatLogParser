#include"item.hpp"


item::item()
{
	return;
}

item::item(std::__cxx11::string line_p)
{
	line = line_p;
}

void item::to_screen()
{
	cout <<  year() <<"-"<<month()<<"-"<<day()<<" "
			<< hour() <<":"<<min()<<":"<<sec() << "\t"
			<< zone() << "\t" << name() 
			<<endl  ;	
}

bool item::parse()
{
	checked = true;
	if (line.find("You receive loot")==string::npos) return false;
	smatch match;
	// 10/1 22:56:05.734  You receive loot: Winter Squid.
	
	regex reg_year_owner_zone ("^([0-9]{1,2})/([0-9]{1,2}) ([0-9]{2}):([0-9]{2}):([0-9]{2})\\.([0-9]{3}).*\\(([0-9]{4}),([a-zA-Z0-9]+),([a-zA-Z0-9\\s]+)\\): You receive loot: ([a-zA-Z0-9\\s]+)\\."); 
	if (regex_search(line,match,reg_year_owner_zone)) 
	{
		month_p = 	match[1];
		day_p = 		match[2];
		hour_p = 		match[3];
		min_p = 		match[4];
		sec_p = 		match[5];
		msec_p = 		match[6];
		year_p =			match[7];
		owner_p =			match[8];
		zone_p =			match[9];
		name_p = 		match[10];
		parsed_p=true;
// 		cout << "reg_year_owner_zone\t" << line << endl;
		return parsed_p;
	}
	regex reg_owner_zone ("^([0-9]{1,2})/([0-9]{1,2}) ([0-9]{2}):([0-9]{2}):([0-9]{2})\\.([0-9]{3}).*\\(([a-zA-Z0-9]+),([a-zA-Z0-9\\s]+)\\): You receive loot: ([a-zA-Z0-9\\s]+)\\."); 
	if (regex_search(line,match,reg_owner_zone)) 
	{
		month_p = 	match[1];
		day_p = 		match[2];
		hour_p = 		match[3];
		min_p = 		match[4];
		sec_p = 		match[5];
		msec_p = 		match[6];
		owner_p =			match[7];
		zone_p =			match[8];
		name_p = 		match[9];
		parsed_p=true;
// 		cout << "reg_owner_zone\t" << line << endl;
		return parsed_p;
	}
	regex reg_zone ("^([0-9]{1,2})/([0-9]{1,2}) ([0-9]{2}):([0-9]{2}):([0-9]{2})\\.([0-9]{3}).*SubZone\\(([a-zA-Z0-9\\s]+)\\): You receive loot: ([a-zA-Z0-9\\s]+)\\."); 
	if (regex_search(line,match,reg_zone)) 
	{
		month_p = 	match[1];
		day_p = 		match[2];
		hour_p = 		match[3];
		min_p = 		match[4];
		sec_p = 		match[5];
		msec_p = 		match[6];
		zone_p =			match[7];
		name_p = 		match[8];
		parsed_p=true;
		return parsed_p;
	}
	regex reg ("^([0-9]{1,2})/([0-9]{1,2}) ([0-9]{2}):([0-9]{2}):([0-9]{2})\\.([0-9]{3}).*You receive loot: ([a-zA-Z0-9\\s]+)\\."); 
	if (regex_search(line,match,reg)) 
	{
		month_p = 	match[1];
		day_p = 		match[2];
		hour_p = 		match[3];
		min_p = 		match[4];
		sec_p = 		match[5];
		msec_p = 		match[6];
		name_p = 		match[7];
		parsed_p=true;
		return parsed_p;
	}
	
	regex test ("^([0-9]{1,2})/([0-9]{1,2})"); 
// 	if (regex_search(line,match,test))
// 	{
// 		cout << "TEST successfull" << endl;
// 	}
		
	return parsed_p;
}

 string item::date() 
{
	return year()+"-"+month()+"-"+day()+" "+hour()+":"+min()+":"+sec()+"."+msec();
}

 string item::owner() 
{
	if (!checked) parse();
	return owner_p;
}

 string item::zone() 
{
	if (!checked) parse();
	return zone_p;
}
 string item::name() 
{
	if (!checked) parse();
	return name_p;
}
 string item::year() 
{
	return year_p;
}
 string item::month() 
{
	if (!checked) parse();
	return month_p;
}
 string item::day() 
{
	if (!checked) parse();
	return day_p;
}
 string item::hour() 
{
	if (!checked) parse();
	return hour_p;
}
 string item::min() 
{
	if (!checked) parse();
	return min_p;
}
 string item::sec() 
{
	if (!checked) parse();
	return sec_p;
}
 string item::msec() 
{
	if (!checked) parse();
	return msec_p;
}




bool item::parsed()
{
	if (checked) return parsed_p;
	return parse();
}

// vector<item> item::items(int argc, char ** argv)
// {
// 	vector<string> filenames;
// 	for (int i=1;i<argc;i++)
// 		filenames.push_back(argv[i]);
// 	return items(filenames);
// }

// vector<item> item::items(vector<string> filenames)
// {
// vector<item> items_p;	
// 	if (items_p.size()>0) return items_p;
// 	vector<item> items_;
// 	for (auto& filename : filenames)
// 	{
// 		items_ = item::items(filename);
// 		items_p.insert(items_p.end(),items_.begin(),items_.end());
// 	}
// 	item::remove_double_entries(items_p);
// 	return items_p;
// }

// vector<item> item::items(string filename)
// {
// // 	vector<string> lines = tools::file:load_file_to_vector_string(filename);
// 	string contents = tools::file::load_file_to_string(filename);
// 	vector<string> lines = tools::str::get_strings_between_delimiter(contents,"\n");
// 	vector<item> items_p;
// 	for (auto& line: lines)
// 	{
// 		item item_p(tools::str::remove_linebreakers_from_string(line));
// 		if (item_p.parsed()) items_p.push_back(item_p);
// 	}
// 	remove_double_entries(items_p);
// 	return items_p;
// }

bool item::operator==( item& i)
{
	if (i.zone()!=zone()) return false;
	if (i.owner()!=owner()) return false;
    if (i.name()!=name()) return false;
	if (i.msec()!=msec()) return false;
	if (i.sec()!=sec()) return false;
	if (i.min()!=min()) return false;
	if (i.hour()!=hour()) return false;
	if (i.day()!=day()) return false;
	if (i.month()!=month()) return false;
	if (i.year()!=year()) return false;
	return true;
}

const bool item::operator<(const item& i) const
{
	if (i.zone_p<zone_p) return true;
	if (i.owner_p<owner_p) return true;
    if (i.name_p<name_p) return true;
	if (i.msec_p<msec_p) return true;
	if (i.sec_p<sec_p) return true;
	if (i.min_p<min_p) return true;
	if (i.hour_p<hour_p) return true;
	if (i.day_p<day_p) return true;
	if (i.month_p<month_p) return true;
	if (i.year_p<year_p) return true;
	return false;
}



// void item::remove_double_entries(vector<item>& items_p)
// {
// 	set<int> rm_idx;
// 	// record double entries
// 	for (int i=0;i<items_p.size();i++ )
// 	{
// 		if (rm_idx.find(i)!=rm_idx.end()) continue;
// 		for (int j=i+1;j<items_p.size();j++ )
// 		{
// 			if (rm_idx.find(j)!=rm_idx.end()) continue;
// 			if (i.name()!=j.name()) continue;
// 			if (i.msec()!=j.msec()) continue;
// 			if (i.sec()!=j.sec()) continue;
// 			if (i.min()!=j.min()) continue;
// 			if (i.hour()!=j.hour()) continue;
// 			if (i.day()!=j.day()) continue;
// 			if (i.month()!=j.month()) continue;
// 			if (i.year()!=j.year()) continue;
// 			// double entry found, delete the one without zone
// 			if (j.zone().length()==0) rm_idx.insert(i);
// 			else rm_idx.insert(j);
// 			break;
// 		}
// 	}
// 	
// 	for (set<int>::reverse_iterator rm=rm_idx.rbegin(); rm!=rm_idx.rend(); ++rm)
// 	{
// 		items_p.erase(items_p.begin()+*rm);
// 	}
// }
