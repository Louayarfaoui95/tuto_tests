
#include "file2.h"


int f1 (int p)
{

  if (p<0)
    return -1;
  else
    return 0;
}

/*
  SPECIFICATION DE f2 :
  EX1: fa retourne 0 au premier appel et une valeur dans [10;20[ lors du second appel ==> f2 retourne 0
  EX2: si le premier appel de fa != 0 ==> pas de second appel et f2 retourne -1
  EX3: si le second appel est hors de [10;20[, f2 retourne -2
  EX4: la valeur du paramètre passé à fa lors du premier appel est la valeur du paramètre a de f2
  EX5: la valeur du paramètre passé à fa lors du deuxième appel est 1 + la valeur du paramètre a de f2
 */
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
