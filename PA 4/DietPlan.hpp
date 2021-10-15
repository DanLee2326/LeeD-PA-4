#pragma once

#include <fstream>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ostream;

class DietPlan
{
public:	
	// constructor
	DietPlan(int newGoal = 0, string newName = "", string newDate = "");

	// copy constructor
	DietPlan(const DietPlan& copyPlan);

	// destructor
	~DietPlan();

	// setters
	void setGoal(int newGoal);
	void setName(string newName);
	void setDate(string newDate);

	// getters
	int getGoal() const;
	string getName() const;
	string getDate() const;

	void editGoal();

private:
	int mGoal;
	string mName;
	string mDate;
};

// non-member functions
fstream& operator<< (fstream& outfile, const DietPlan& a);
ostream& operator<< (ostream& printPlan, const DietPlan& b);
fstream& operator>> (fstream& infile, DietPlan& c);