/**************************************************************************/
/*PURPOSE: The program gives the average of three numbers.                */
/*IMPLEMENTED BY: David Garcia                                            */
/*DATE: 10/24/15                                                          */
/*USER INFORMATION: The user inputs numbers in the in file.               */
/*IMPLEMENTATION METHOD: The program will calculate the average of five   */
/*scores while droping the lowest and the highest.                        */
/*OVERVIEW OF SUBPARTS: The program of the main function and subparts.    */
/**************************************************************************/
#include <iostream>
using namespace std;

//Protypes
void getJudgeData(double &score1, double &score2, double &score3, double &score4, double &score5);
void calcScore(double lscore, double hscore, double score1, double score2, double score3, double score4, double score5);
double findLowest(double score1, double score2, double score3, double score4, double score5);
double findHighest(double score1, double score2, double score3, double score4, double score5);

//Start the main function
int main()
{
  double score1, score2, score3, score4, score5, lscore, hscore;
  //Call the other functions to work!
  getJudgeData(score1, score2, score3, score4,score5);
  lscore = findLowest(score1, score2, score3, score4,score5);
  hscore = findHighest (score1, score2, score3, score4, score5);
  calcScore(lscore, hscore, score1, score2, score3, score4, score5);
  //Don't forget that return zero!
  return 0;
}

//Start the input function and return multiple variables.
void getJudgeData(double &score1, double &score2, double &score3, double &score4, double &score5)
{ 
  //Get info from user.
  cout << "Enter the five scores using a space in between. " << endl;
  cin >> score1 >> score2 >> score3 >> score4 >> score5;
  //Make sure the numbers fit into the domain.
  while ((score1 < 0)||(score1 > 10)||(score2 < 0)||(score2 > 10)||(score3 < 0)||(score3 > 10)||(score4 < 0)||(score4 > 10)||(score5 < 0)||(score5 > 10))
    {
      cout << "One or more of the scores you have entered is invalid! " << endl;
      cout << "Re-enter the five scores using a space in between" << endl;
      cin >> score1 >> score2 >> score3 >> score4 >> score5;
    }
}

double findLowest(double score1, double score2, double score3, double score4, double score5)
{
  double lowScore;
  //Determine the lowest score.
  if ((score1 <= score2)&&(score1 <= score3)&&(score1 <= score4)&&(score1 <= score5))
    lowScore = score1;
  else if ((score2 <= score1)&&(score2 <= score3)&&(score2 <= score4)&&(score2 <= score5))
    lowScore = score2;
  else if ((score3 <= score1)&&(score3 <= score2)&&(score3 <= score4)&&(score3 <= score5))
    lowScore = score3;
  else if ((score4 <= score1)&&(score4 <= score2)&&(score4 <= score3)&&(score4 <= score5))
    lowScore = score4;
  else if ((score5 <= score1)&&(score5 <= score2)&&(score5 <= score3)&&(score5 <= score4))
    lowScore = score5;
  return lowScore;
}

double findHighest(double score1, double score2, double score3, double score4, double score5)
{
  double highScore;
  //Determine the highest score.
  if ((score1 >= score2)&&(score1 >= score3)&&(score1 >= score4)&&(score1 >= score5))
    highScore = score1;
  else if ((score2 >= score1)&&(score2 >= score3)&&(score2 >= score4)&&(score2 >= score5))
    highScore = score2;
  else if ((score3 >= score1)&&(score3 >= score2)&&(score3 >= score4)&&(score3 >= score5))
    highScore = score3;
  else if ((score4 >= score1)&&(score4 >= score2)&&(score4 >= score3)&&(score4 >= score5))
    highScore = score4;
  else if ((score5 >= score1)&&(score5 >= score2)&&(score5 >= score3)&&(score5 >= score4))
    highScore = score5;
  return highScore;
}

void calcScore(double lscore, double hscore, double score1, double score2, double score3, double score4, double score5)
{
  double avg, total;
  //Determine the average while dropping the higest and lowest score. 
  total = (score1+score2+score3+score4+score5)-(lscore+hscore);
  avg = total/3;
  //Display the message to the user.
  cout << "After dropping the highest score (" << hscore << ") and the lowest score(" << lscore << "), the average of the remaining scores are " << avg << endl;
}
