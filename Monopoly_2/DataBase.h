

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "LogFile.h"
#include "ReadWriteFile.h"


typedef int _percent_type;
typedef int _value_type;

extern LogFile Log;



struct addiction {
	addiction() : value(0), percent(0)
	{
		Log.AddLine("create [addiction] base", Info);
	}
	addiction(_value_type value, _percent_type percent) : value(value), percent(percent)
	{	
		Log.AddLine("create [addiction] params:" + std::to_string(value) + "&" + std::to_string(percent), Info);
	}
	//value 
	_value_type value;
	//percent 
	_percent_type percent;
};

struct percents {
	percents()
	{
		Log.AddLine("create [percents] base", Info);
		for (int i = 0; i < 3; i++)
		{
			pr_dep[i] = addiction(0, 0);
		}
	}
	percents(std::vector<std::pair<_value_type, _percent_type>> param)
	{
		Log.AddLine("create [percents] with params", Info);
		for (int i = 0; i < 3; i++)
		{
			pr_dep[i] = addiction(param[i].first, param[i].second);
		}
	}
	_percent_type find(_value_type value)
	{
		if (value > pr_dep[0].value)
			return pr_dep[0].percent;
		else if (value > pr_dep[1].value)
			return pr_dep[1].percent;
		else if (value > pr_dep[2].value)
			return pr_dep[2].percent;
		else
			return 0;
	}
	std::vector<std::string> data()
	{
		Log.AddLine("save data [percents]", Info);
		std::vector<std::string> tmp;
		for (int i = 0; i < 3; i++)
		{
			tmp.push_back(std::to_string(i) + " " +
				std::to_string(pr_dep[i].value) + " " +
				std::to_string(pr_dep[i].value));
			Log.AddLine(std::to_string(i) + " " + std::to_string(pr_dep[i].value) + " " + std::to_string(pr_dep[i].value), Info);
		}
		return tmp;
	}
	// percents - deposit(from money)
	addiction pr_dep[3];
};


struct bankClient
{

	int my_deposit, my_credit;
	_value_type credit_param, deposit_param;
private:

};


class bank {
	
public:
	bank(std::vector<std::pair<_value_type, _percent_type>> deposit_params,
		 std::vector<std::pair<_value_type, _percent_type>> credit_params,
		 RWFile* my_file) : my_file(my_file)
	{
		Init(deposit_params, credit_params);
		Log.AddLine("create bank", Info);
	}
	void Init(	std::vector<std::pair<_value_type, _percent_type>> deposit_params,
				std::vector<std::pair<_value_type, _percent_type>> credit_params)
	{
		deposit = percents(deposit_params);
		credit  = percents(credit_params);
		Log.AddLine("init bank", Info);
	}

	void addClient(int ID_client)
	{

	}



	void save()
	{
		for(auto str : deposit.data())
			my_file->WrileLine(str);
		for (auto str : credit.data())
			my_file->WrileLine(str);
		Log.AddLine("add to file ", Info);
	}

	percents deposit;
	percents credit;

	~bank()
	{
		save();
	}
private:
	RWFile* my_file;
	std::vector<bankClient> clients;
};










