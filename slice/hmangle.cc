//Example: Given a time, calculate the angle between
//the hour and minute hands
//like 3:27
//
#include <iostream>
using namespace std;

int main() {
  int h       = 3;
  int m       = 27;

  //Angle between the minute hand and 12 o'cloc
  int m_angle = 360 * m / 60;
  //Angle between the hour   hand and 12 o'cloc
  int h_angle = 360 * (h % 12) / 12 + (m / 60) * (1 / 12) * 360;

  cout << (h_angle - m_angle) % 360 << endl;

  return 0;
}
