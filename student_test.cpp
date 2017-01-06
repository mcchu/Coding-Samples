#include <iostream>
#include "student.h"
#include <string>
#include <map>

using namespace std;

int main()
{
  map<string, Student> stumap;
  int idx, score_idx, score;
  double average = 0;
  int num_grades = 0;
  string name; 
 do
 {
  cout << "------ MENU ------ " <<endl;
  cout << "1: Add new student (input: 1 <Name>)" <<endl;
  cout << "2: Remove student (input: 2 <Name>)" << endl;
  cout << "3: Add a new score to all student objects (input: 3)" << endl;
  cout << "4. Update score for student (input: 4 <Name> <Score idx> <Score>)" << endl;
  cout << "5. Calculate average (input: 5 <Score idx>)" << endl;
  cout << "6. Print student names and scores (input: 6)" << endl;
  cout << "7. Exit program (input: 7)" << endl;
  cout << "------------------- " <<endl;
  cout << "Input index and commands:" <<endl;
  cin >> idx;


	if(idx == 1)		//adds new student
	{
	   cin >> name;
	   Student s1(name);
	   stumap[name] = s1;
	   cout << endl;
	}
	if (idx == 2)		//erases student
	{
	   cin >> name;
	   stumap.erase(name);
	   cout << endl;
	}
	if (idx == 3)		//adds slot for new score
	{
	   map<string, Student>::iterator it;
	   num_grades++;
	   for (it = stumap.begin(); it != stumap.end(); ++it)
	   {
		(it->second).add_grade(0);
	   }
	   cout << endl;
	}
	if (idx == 4)		//updates score at idx value
	{
	   cin >> name >> score_idx >> score;
	   stumap[name].update_grade(score_idx, score);
	   cout << endl;
	}
	if (idx == 5)		//calculates average of scores at idx value
	{
	   int num_stu = 0;
	   cin >> score_idx;
	   map<string, Student>::iterator it1;
	   for(it1 = stumap.begin(); it1 != stumap.end(); ++it1)
	   {
		average += (it1->second).get_grade(score_idx);
		num_stu ++;
	   }
	   cout << endl;
	   cout << "Average: " << (double)average/num_stu;
	   cout << endl <<endl;
	}
	if (idx == 6)		//outputs results
	{
	   cout << endl;
	   map<string, Student>::iterator me;
	   for(me = stumap.begin(); me != stumap.end(); ++me)
	   {
		cout << me->first << ": ";
		if (num_grades > 0)
		{ 
			for (int i = 0; i < num_grades; i++)
			{
			   cout << (me->second).get_grade(i) << " ";
			}
		}
		cout << endl;
	   }
	   cout << endl;
	}

	if (idx == 7)		//exits
	{
	   cout << endl;
	   cout << "Exiting. " << endl;
	}

	if (idx > 7)		//if user inputs more than 6
	{
	    cout << endl;
	    cout << "ERROR. Please enter valid index (1-7) " << endl << endl;
	}

  }while(idx != 7);

  cout << "Thank you, bye bye!" << endl << endl;


   return 0;
}
