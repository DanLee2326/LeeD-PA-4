#include "DietPlan.hpp"

// constructor
DietPlan::DietPlan(int newGoal, string newName, string newDate)
{
	mGoal = newGoal;
	mName = newName;
	mDate = newDate;
}

// copy constructor
DietPlan::DietPlan(const DietPlan& copyPlan)
{
	mGoal = copyPlan.getGoal();
	mName = copyPlan.getName();
	mDate = copyPlan.getDate();
}

// destructor
DietPlan::~DietPlan()
{

}

// setters
void DietPlan::setGoal(int newGoal)
{
	mGoal = newGoal;
}

void DietPlan::setName(string newName)
{
	mName = newName;
}

void DietPlan::setDate(string newDate) 
{
	mDate = newDate;
}

// getters
int DietPlan::getGoal() const
{
	return this->mGoal;
}

string DietPlan::getName() const
{
	return this->mName;
}

string DietPlan::getDate() const
{
	return this->mDate;
}

void DietPlan::editGoal()
{
	int n = 0;
	cout << "Enter a new goal: ";
	cin >> n;

	mGoal = n;
}

// non-member functions
fstream& operator<< (fstream& outfile, const DietPlan& a)
{
	outfile
		<< a.getName() << endl 
		<< a.getGoal() << endl 
		<< a.getDate() << endl
		<< endl;
	return outfile;
}

ostream& operator<< (ostream& printPlan, const DietPlan& b)
{
	printPlan
		<< b.getName() << endl
		<< b.getGoal() << endl
		<< b.getDate() << endl
		<< endl;
	return printPlan;
}

fstream& operator>> (fstream& infile, DietPlan& c)
{
	if (infile.is_open())
	{
		while (!infile.eof())
		{
			char pFile[100] = "";
			infile.getline(pFile, 100);
			c.setName(pFile);
			infile.getline(pFile, 100);
			c.setGoal(atoi(pFile));
			infile.getline(pFile, 100);
			c.setDate(pFile);
			infile.getline(pFile, 100);
		}
	}
	return infile;
}