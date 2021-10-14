#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

//STUDENT INFO INPUT
void studentInfo (vector<string> &studentFirstNames, vector<string> &studentLastNames, vector<double> &studentGradeAvg) {
    
   string firstNameInput;
   string lastNameInput;
   double gradeAvgInput;
   unsigned int i;
    
   for (i = 0; i < studentFirstNames.size() ; ++i) {
      //Student Name Input
      cout << "Please enter student (First Last Grade) info: ";
      cin >> firstNameInput >> lastNameInput >> gradeAvgInput;
      
      //Storing student name in array
      studentFirstNames.at(i) = firstNameInput;
      studentLastNames.at(i) =  lastNameInput;
      studentGradeAvg.at(i) = gradeAvgInput;
   }
   cout << "Thank you for entering your students information!" << endl;
}

//ADD STUDENT
void addStudent(vector<string> &studentFirstNames, vector<string> &studentLastNames, vector<double> &studentGradeAvg) {
   
   string firstNameInput;
   string lastNameInput;
   double gradeAvgInput;
   
   cout << "Please enter student (First Last Grade) info: ";
   cin >> firstNameInput >> lastNameInput >> gradeAvgInput;
      
   //Storing student name in array
   studentFirstNames.push_back(firstNameInput);
   studentLastNames.push_back(lastNameInput);
   studentGradeAvg.push_back(gradeAvgInput);
}

//REMOVE STUDENT
void removeStudent(vector<string> &studentFirstNames, vector<string> &studentLastNames, vector<double> &studentGradeAvg) {
   
    string firstNameInput;
    string lastNameInput;
    bool found = false;
    unsigned int i = 0;
   
    cout << "Please enter students first and last name: ";
    cin >> firstNameInput >> lastNameInput;
    cout << "Removing: " << firstNameInput << " " << lastNameInput << endl;
    
    while (!found && (i < studentFirstNames.size())) {
      if (studentFirstNames.at(i) == firstNameInput || studentLastNames.at(i) == lastNameInput) {
         studentFirstNames.erase(studentFirstNames.begin() + i);
         studentLastNames.erase(studentLastNames.begin() + i);
         studentGradeAvg.erase(studentGradeAvg.begin() + i); 
         found = true;
      }
      ++i;
   }
}

//CLASS SUMMARY
void classSummary (vector<string> &studentFirstNames, vector<string> &studentLastNames, vector<double> &studentGradeAvg) { 
   
   unsigned int i;
   int numOfStudents = studentFirstNames.size();
   double classGradeAvgTotal = 0;
   
   for (i = 0; i < studentGradeAvg.size() ; ++i) {
      classGradeAvgTotal += studentGradeAvg.at(i);
   }
   
   cout << "Class Summary" << endl;
   cout << "------------------------" << endl;
   cout << "Name" << right << setw(20) << "Grade" << endl;
   cout << "---------" << right << setw(18) << "--------" << endl;
   for (i = 0; i < studentFirstNames.size() ; ++i) {
      cout << studentFirstNames.at(i) << " " << studentLastNames.at(i) << fixed << setprecision(2) << right << setw(23) << studentGradeAvg.at(i) << endl;
   }
   cout << "Number of Students:" << endl;
   cout << "-------------------" << endl;
   cout << numOfStudents << endl;
   cout << "Average Grade:" << endl;
   cout << "--------------" << endl;
   cout << classGradeAvgTotal / numOfStudents << endl;
   // cout << "selection: ";
}

//MENU
void menu(vector<string> &studentFirstNames, vector<string> &studentLastNames, vector<double> &studentGradeAvg) {
   
   char choice;
   
   //Menu
   cout << "Please choose one of the following options:" << endl;
   cout << "a: add a student" << endl;
   cout << "r: remove a student" << endl;
   cout << "p: print the class summary" << endl;
   cout << "m: print menu" << endl;
   cout << "q: quit program" << endl;
   
   cout << "selection: ";
   cin >> choice;
   
   
   //Invalid Selection Loop
   while (choice != 'a' && choice != 'r' && choice != 'p' && choice != 'm' && choice != 'q' ) {
      cout << "Not a valid selection." << endl;
      cout << "selection: ";
      cin >> choice;
   }
   
   //Menu options loop & switch
   while (choice != 'q') { 
         switch(choice) {
            case 'a':
                addStudent(studentFirstNames, studentLastNames, studentGradeAvg);
                break;
            case 'r':
                removeStudent(studentFirstNames, studentLastNames, studentGradeAvg);
                break;
            case 'p':
                classSummary(studentFirstNames, studentLastNames, studentGradeAvg);
                break;
            case 'm':
                menu(studentFirstNames, studentLastNames, studentGradeAvg);
                break;
         }
         cout << "selection: ";
         cin >> choice;
      }

}

//MAIN
int main() {

   int numOfStudents;
   vector<string> studentFirstNames;
   vector<string> studentLastNames;
   vector<double> studentGradeAvg;
   // unsigned int i;
   
   //Prompt input of number of students 
   cout << "Welcome to the student roster!" << endl;
   cout << "How many students are in your class?: ";
   cin >> numOfStudents;
   
   //Resizing vectors to number of students in class 
   studentFirstNames.resize(numOfStudents);
   studentLastNames.resize(numOfStudents);
   studentGradeAvg.resize(numOfStudents);
   
   //Calls function that prompts for and stores the first & last names of students & grade avg
   studentInfo(studentFirstNames, studentLastNames, studentGradeAvg);
   
   //Calls menu function
   menu(studentFirstNames, studentLastNames, studentGradeAvg);

   return 0;
}
