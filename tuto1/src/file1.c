
#include "file2.h"


int f1 (int p)
{

  if (p<0)
    return -1;
  else
    return 0;
}


int f2(int a)
{
  int ret = 0;
  int status = -1;

  ret = fa(a);

  if (ret == 0)
    {
      ret = fa(a+1);
      if (ret >= 10 & ret < 20)
        {
          status = 0;
        }
      else
        {
          status = -2;
        }
    }
  return status ;
}
