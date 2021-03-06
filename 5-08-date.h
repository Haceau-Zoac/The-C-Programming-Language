#ifndef _5_8_DATE_H
#define _5_8_DATE_H

static char daytab[2][13] =
{
  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
  { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) 
{
  if (month < 1 || month > 12) return 0;
  const int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  for (int i = 1; i < month; ++i)
    day += daytab[leap][i];
  return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int* month, int* day)
{
  if (yearday < 1)
  {
    *month = 0;
    *day = 0;
    return;
  }
  const int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  int i = 1;
  for (; yearday > daytab[leap][i]; ++i)
    yearday -= daytab[leap][i];
  *month = i;
  *day = yearday;
}

#endif // _5_8_DATE_H