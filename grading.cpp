#include <iostream>
#include <string>
using namespace std;

int score(string teacherInput, string studentAnswers)
{
  int score = 0;
  for (int i = 0; i < 20; i++)
  {
    if(studentAnswers[i] == teacherInput[i])
    {
      score += 2;
    } else if (studentAnswers[i] != teacherInput[i] && studentAnswers[i] != '-')
    {
      score -= 1;
    }
  }
  return score;
}

void scoresAnalysis(int scores[], int count)
{
  cout << "Highest Score: ";
  int maxVal = scores[0];
  for (int i = 1; i < count; i++) {
    if (scores[i] > maxVal) {
        maxVal = scores[i];
    }
  }
  cout << maxVal << endl;

  cout << "Lowest Score: ";
  int minVal = scores[0];
  for (int i = 1; i < count; i++) {
    if (scores[i] < minVal) {
        minVal = scores[i];
    }
  }
  cout << minVal << endl;

  cout << "Average Score: ";
  double ave = 0.00;
  for (int i = 0; i < count; i++)
  {
    ave += scores[i];
  }
  cout << ave/count;
}

int main()
{
  int rollNos[100], scores[100];
  string teacherInput;
  cout << "Enter the answer key to the True/False questions in the form 'TFFTFT...' : ";
  cin >> teacherInput;
  while (teacherInput.length() != 20)
  {
    cout << "Enter the correct number of answers please: ";
    cin >> teacherInput;
  }

  int choice = 0, count = 0, rollNo;
  string studentAnswers;
  while (choice != -1)
  {
    cout << "Enter the Roll# of the student: ";
    cin >> rollNo;
    cout << "Enter student's answers: ";
    cin >> studentAnswers;
    while (studentAnswers.length() != 20)
    {
    cout << "Enter the correct number of answers please: ";
    cin >> studentAnswers;
    }
    rollNos[count] = rollNo;
    scores[count] = score(teacherInput, studentAnswers);
    count++;
    cout << "Wanna add more students? Respond by number. (-1 means No and any other number means Yes) " << endl;
    cin >> choice;
  }

  cout << "Roll#    | Score" << endl;
  cout << "----------------" << endl;
  for (int i = 0; i < count; i++)
  {
    cout << rollNos[i] << "      | " << scores[i] << endl;
  }
  scoresAnalysis(scores, count);
  return 0;
}