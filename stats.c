#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    float total = 0;
    float min = numberset[0];
    float max = numberset[0];
if(setlength !=0)
{
    for(int i=0;i<setlength;i++)
    {
         if(numberset[i]<min) 
         {
              min= numberset[i];
         }
	 if(numberset[i]> max) 
	 {
              max= numberset[i];
	 }
	total = total + numberset[i];
    }
    s.average = total/setlength;
    s.min = min;
    s.max = max;
}
else
{
    s.average = NAN;
    s.min = 0;
    s.max = 0;
}
return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if(computedStats.max > maxThreshold)
    {
        emailAlerter();
	ledAlerter();
    }
}

void emailAlerter()
{
    emailAlertCallCount++;
}

void ledAlerter()
{
   ledAlertCallCount++;
}
