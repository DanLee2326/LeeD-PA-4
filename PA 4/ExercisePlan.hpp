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

class ExercisePlan
{
public:
	// constructor
	ExercisePlan(int newGoal = 0, string newName = "", string newDate = "");

	// copy constructor
	ExercisePlan(const ExercisePlan& copyPlan);

	// destructor
	~ExercisePlan();

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
fstream& operator<< (fstream& outfile, const ExercisePlan& a);
ostream& operator<< (ostream& printPlan, const ExercisePlan& b);
fstream& operator>> (fstream& infile, ExercisePlan& c);