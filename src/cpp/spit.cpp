#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <map>
#include <sstream>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

#define SPITFILE "Spitfile"
#define ENTRY_PARTS 2

namespace po = boost::program_options;
namespace fs = boost::filesystem;
using namespace std;

bool has_entries();

int main(int argc, char const *argv[])
{
	const string initialPath(fs::current_path().string());
	map<string,string> entries;
	regex entry(R"(^([_a-z0-9.]+)\s+(.+)$)",regex_constants::icase);

	po::options_description clOptions("Allowed Options");
	clOptions.add_options()
		("help,h","Show help")
		("initialize,i","Initialize")
		("bare,b","Create bare initialization")
		("list,l","List entries")
		("keys,k","List keys only")
		("values,v","List values only")
	;

	po::variables_map varMap;
	po::store(po::parse_command_line(argc,argv,clOptions),varMap);
	po::notify(varMap);


	// help option
	if(varMap.count("help"))
	{
		cout << clOptions << endl;
		return 0;
	}

	// initialize option
	if(varMap.count("initialize"))
	{
		if(has_entries())
		{
			cout << SPITFILE << " already exists" << endl;
			return 0;
		}else
		{
			ofstream spitfile(SPITFILE);
			if(spitfile.is_open())
			{
				if(!varMap.count("bare"))
				{
					spitfile << "pwd " << initialPath << endl;
				}

				spitfile.close();
				return 0;
			}else
			{
				cout << "unable to open " << SPITFILE << endl;
				return 1;
			}
		}
	}

	// list option
	if(varMap.count("list"))
	{
		if(has_entries())
		{
			string line;
			ifstream spitfile(SPITFILE);

			if(spitfile.is_open())
			{
				smatch strMatch;

				while(getline(spitfile,line))
				{
					if(regex_match(line,strMatch,entry))
					{
						if(strMatch.size() - 1 == ENTRY_PARTS)
						{
							if(varMap.count("keys"))
							{
								cout << strMatch[1] << endl;
							}else if(varMap.count("values"))
							{
								cout << strMatch[2] << endl;
							}else
							{
								cout << strMatch[1] << " => " << strMatch[2] << endl;
							}
						}else
						{
							cout << "unexpected entry count" << endl;
						}
					}
				}

				spitfile.close();
			}else
			{
				cout << "unable to open " << SPITFILE << endl;
				return 1;
			}
		}else
		{
			cout << "unable to read entries from " << SPITFILE << endl;
		}
	}

	return 0;
}

bool has_entries()
{
	return (fs::exists(SPITFILE) && !fs::is_empty(fs::path(SPITFILE)));
}

void load_entries()
{
	
}