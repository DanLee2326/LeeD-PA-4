#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "DietPlan.hpp"
#include "ExercisePlan.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ostream;

class FitnessAppWrapper
{
public:
	void runApp(void); // starts the main application.

	void loadDailyPlan(fstream& fileStream, DietPlan& plan); // must define two of these functions; one for a DietPlanand one for an ExercisePlan.This function reads one record from the given stream.These will be considered overloaded functions!Precondition: file is already open!
	void loadDailyPlan(fstream& fileStream, ExercisePlan& plan);

	void loadWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[]); // must define two of these functions; one for a DietPlanand one for an ExercisePlan.This function must read in all seven daily plans from the given stream.Note: the array parameter would change if using a vector or linked list!This function should call loadDailyPlan() directly.Precondition : file is already open!
	void loadWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[]);

	void displayDailyPlan(ostream& printPlan, DietPlan& plan); // writes a daily plan to the screen.You must apply the overloaded stream insertion operator here!Note : you must determine the appropriate parameters and return type.Once again you must define two of these!
	void displayDailyPlan(ostream& printPlan, ExercisePlan& plan);

	void displayWeeklyPlan(ostream& printPlan, DietPlan weeklyPlan[]); // writes a weekly plan to the screen.This function must call displayDailyPlan().Note : you must determine the appropriate parameters and return type.Once again you must define two of these!
	void displayWeeklyPlan(ostream& printPlan, ExercisePlan weeklyPlan[]);

	void storeDailyPlan(fstream& storePlan, DietPlan& plan); // writes a daily plan to a file.You must apply the overloaded stream insertion operator here!Note : you must determine the appropriate parameters and return type.Once again you must define two of these!
	void storeDailyPlan(fstream& storePlan, ExercisePlan& plan);

	void storeWeeklyPlan(fstream& storePlan, DietPlan weeklyPlan[]); // writes a weekly plan to a file.This function must call storeDailyPlan().You must apply the overloaded stream insertion operator here!Note : you must determine the appropriate parameters and return type.Once again you must define two of these!
	void storeWeeklyPlan(fstream& storePlan, ExercisePlan weeklyPlan[]);

	void displayMenu(); // displays nine menu options. These include :
	// 1.    Load weekly diet plan from file.
	// 2.    Load weekly exercise plan from file.
	// 3.    Store weekly diet plan to file.
	// 4.    Store weekly exercise plan to file.
	// 5.    Display weekly diet plan to screen.
	// 6.    Display weekly exercise plan to screen.
	// 7.    Edit daily diet plan.
	// 8.    Edit daily exercise plan.
	// 9.    Exit.   // Note: this must write the most recent weekly plans to the corresponding files.

	//Other functions ? There should be!
	int selectMenuOption() const;

private:
	DietPlan weeklyDiet[7];
	ExercisePlan weeklyExercise[7];
};
