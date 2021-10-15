#include "ExercisePlan.hpp"

// constructor
ExercisePlan::ExercisePlan(int newGoal, string newName, string newDate)
{
	mGoal = newGoal;
	mName = newName;
	mDate = newDate;
}

// copy constructor
ExercisePlan::ExercisePlan(const ExercisePlan& copyPlan)
{
	mGoal = copyPlan.getGoal();
	mName = copyPlan.getName();
	mDate = copyPlan.getDate();
}

// destructor
ExercisePlan::~ExercisePlan()
{

}

// setters
void ExercisePlan::setGoal(int newGoal)
{
	mGoal = newGoal;
}

void ExercisePlan::setName(string newName)
{
	mName = newName;
}

void ExercisePlan::setDate(string newDate)
{
	mDate = newDate;
}

// getters
int ExercisePlan::getGoal() const
{
	return mGoal;
}

string ExercisePlan::getName() const
{
	return mName;
}

string ExercisePlan::getDate() const
{
	return mDate;
}

void ExercisePlan::editGoal()
{
	int n = 0;
	cout << "Enter a new goal: ";
	cin >> n;

	mGoal = n;
}

// non-member functions
fstream& operator<< (fstream& outfile, const ExercisePlan& a)
{
	outfile
		<< a.getName() << endl
		<< a.getGoal() << endl
		<< a.getDate() << endl
		<< endl;
	return outfile;
}

ostream& operator<< (ostream& printPlan, const ExercisePlan& b)
{
	printPlan
		<< b.getName() << endl
		<< b.getGoal() << endl
		<< b.getDate() << endl
		<< endl;
	return printPlan;
}

fstream& operator>> (fstream& infile, ExercisePlan& c)
{
	if (infile.is_open())
	{
		while (!infile.eof())
		{
			char a[100] = "";
			infile.getline(a, 100);
			c.setName(a);
			infile.getline(a, 100);
			c.setGoal(atoi(a));
			infile.getline(a, 100);
			c.setDate(a);
			infile.getline(a, 100);
		}
	}
	return infile;
}