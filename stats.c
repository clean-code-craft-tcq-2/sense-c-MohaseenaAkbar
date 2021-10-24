#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    static int total = 0;
    for(int i=0;i<setlength;i++)
    {
      total + = numberset[i];
    }
    s.average = total/setlength;
    s.min = 0;
    s.max = 0;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
