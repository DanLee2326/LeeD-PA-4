#include "FitnessAppWrapper.hpp"

void FitnessAppWrapper::runApp(void)
{
	bool checkDiet = false;
	bool checkExercise = false;

	while (true)
	{
		displayMenu();
		int i = selectMenuOption();

		switch (i)
		{
		case 1:
		{
			fstream afile;
			afile.open("dietPlans.txt", std::ios::in);
			loadWeeklyPlan(afile, weeklyDiet);
			afile.close();

			cout << "File Opened Successfully" << endl << endl;
			checkDiet = true;
			break;
		}
		case 2:
		{
			fstream afile;
			afile.open("exercisePlans.txt", std::ios::in);
			loadWeeklyPlan(afile, weeklyExercise);
			afile.close();

			cout << "File Opened Successfully" << endl << endl;
			checkExercise = true;
			break;
		}
		case 3:
		{
			fstream afile;
			afile.open("dietPlans.txt", std::ios::out);
			storeWeeklyPlan(afile, weeklyDiet);
			afile.close();

			cout << "File Saved Successfully" << endl << endl;
			break;
		}
		case 4:
		{
			fstream afile;
			afile.open("exercisePlans.txt", std::ios::out);
			storeWeeklyPlan(afile, weeklyExercise);
			afile.close();

			cout << "File Saved Successfully" << endl << endl;
			break;
		}
		case 5:
		{
			displayWeeklyPlan(cout, weeklyDiet);
			break;
		}
		case 6:
		{
			displayWeeklyPlan(cout, weeklyExercise);
			break;
		}
		case 7:
		{
			cout << "Weekly Plans" << endl;
			cout << "1 - Sunday Plan" << endl;
			cout << "2 - Monday Plan" << endl;
			cout << "3 - Tuesday Plan" << endl;
			cout << "4 - Wednesday Plan" << endl;
			cout << "5 - Thursday Plan" << endl;
			cout << "6 - Friday Plan" << endl;
			cout << "7 - Saturday Plan" << endl << endl;

			cout << "Select the diet plan you want to edit: ";
			int n;
			cin >> n;

			if (n < 8 && n > 0)
			{
				weeklyDiet[n-1].editGoal();
				system("cls");
			}
			else
			{
				system("cls");
				cout << "Invalid Plan Number" << endl << endl;
			}
			break;
		}
		case 8:
		{
			cout << "1 - Sunday Plan" << endl;
			cout << "2 - Monday Plan" << endl;
			cout << "3 - Tuesday Plan" << endl;
			cout << "4 - Wednesday Plan" << endl;
			cout << "5 - Thursday Plan" << endl;
			cout << "6 - Friday Plan" << endl;
			cout << "7 - Saturday Plan" << endl << endl;

			cout << "Select the exercise plan you want to edit: ";
			int n;
			cin >> n;

			if (n < 8 && n > 0)
			{
				weeklyExercise[n - 1].editGoal();
				system("cls");
			}
			else
			{
				system("cls");
				cout << "Invalid Plan Number" << endl << endl;
			}
			break;
		}
		case 9:
		{
			if (checkDiet)
			{
				fstream afile;
				afile.open("dietPlans.txt", std::ios::out);
				storeWeeklyPlan(afile, weeklyDiet);
				afile.close();
			}
			if (checkExercise)
			{
				fstream afile;
				afile.open("exercisePlans.txt", std::ios::out);
				storeWeeklyPlan(afile, weeklyExercise);
				afile.close();
			}

			cout << "Files Saved Successfully" << endl << endl;
			cout << "Thank you for using Fitness App Wrapper" << endl << endl;
			return;
			break;
		}
		default:
			cout << "Invalid Input" << endl << endl;
			break;
		};
	}
}

void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, DietPlan& plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, ExercisePlan& plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayDailyPlan(ostream& printPlan, DietPlan& plan)
{
	printPlan << plan;
}

void FitnessAppWrapper::displayDailyPlan(ostream& printPlan, ExercisePlan& plan)
{
	printPlan << plan;
}

void FitnessAppWrapper::displayWeeklyPlan(ostream& printPlan, DietPlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		displayDailyPlan(printPlan, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayWeeklyPlan(ostream& printPlan, ExercisePlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		displayDailyPlan(printPlan, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::storeDailyPlan(fstream& storePlan, DietPlan& plan)
{
	storePlan << plan;
}

void FitnessAppWrapper::storeDailyPlan(fstream& storePlan, ExercisePlan& plan)
{
	storePlan << plan;
}

void FitnessAppWrapper::storeWeeklyPlan(fstream& storePlan, DietPlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(storePlan, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::storeWeeklyPlan(fstream& storePlan, ExercisePlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(storePlan, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayMenu()
{
	cout << "Fitness App Wrapper" << endl;
	cout << "1. Load weekly diet plan from file" << endl;
	cout << "2. Load weekly exercise plan from file" << endl;
	cout << "3. Store weekly diet plan to file" << endl;
	cout << "4. Store weekly exercise plan to file" << endl;
	cout << "5. Display weekly diet plan to screen" << endl;
	cout << "6. Display weekly exercise plan to screen" << endl;
	cout << "7. Edit daily diet plan" << endl;
	cout << "8. Edit daily exercise plan" << endl;
	cout << "9. Exit" << endl << endl;
}

int FitnessAppWrapper::selectMenuOption() const
{
	int n = 0;
	cout << "Select an option: ";
	cin >> n;

	system("cls");
	return n;
}