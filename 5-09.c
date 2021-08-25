#include <stdio.h>
#include "check.h"
#include "5-09-date.h"

int main(void)
{
  int day = day_of_year(2021, 2, 24);
  printf("[day_of_year] %c | year:2021 | month:2 | day:24 | RETURN:%d\n",
    istrue(day == 55), day);
  day = day_of_year(2077, 0, 32);
  printf("[day_of_year] %c | year:2077 | month:0 | day:32 | RETURN:%d\n\n",
    istrue(day == 0), day);

  int month;
  month_day(1999, 33, &month, &day);
  printf("[month_day] %c | year:1999 | yearday:33 | RETURN/month:%d | RETURN/day:%d\n", istrue(month == 2 && day == 2), month, day);
  month_day(2000, 0, &month, &day);
  printf("[month_day] %c | year:1999 | yearday:33 | RETURN/month:%d | RETURN/day:%d\n", istrue(!month && !day), month, day);
}