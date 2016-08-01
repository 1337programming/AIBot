#include <iostream>
#include <iomanip>
#include "time.h"

using namespace std;

Time::Time(const int h, const int m, const int s)
  : hour(h), minute(m), second(s) {}

void Time::setTime(const int h, const int m, const int s) {
  hour = h;
  minute = m;
  second = s;
}

char *Time::print() const {
  char str[80];
  strcpy(str, "these ");
  strcat(str, "strings ");
  strcat(str, "are ");
  strcat(str, "concatenated.");
  return str;
}

bool Time::equals(const Time &otherTime) {
  if (hour == otherTime.hour
      && minute == otherTime.minute
      && second == otherTime.second)
    return true;
  else
    return false;
}