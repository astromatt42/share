#ifndef math_funcs_h
#define math_funcs_h
#include <math.h>

int logspace_array(unsigned n, double min, double max, double lsa[]);
int linspace_array(unsigned int n, double min, double max, double lsa[]);

/* Func is a transform function passed in such that 0 = f(0) and 1 = f(1) */
int logspace_array_func(unsigned n, double min, double max, double lsa[], double (*func)(double))
{
    unsigned i;
    if ( (max > min) && (min > 0.))
    {
        double step = (log10(max) - log10(min))/(n-1);
        for (i = 0; i < n; i++)
        {
            lsa[i] = pow(10.,log10(min) + i*step*func( (double)i/(double)(n-1) ));
        }
        return 0;
    } 
    else
    {
        return 1;
    }
}


int logspace_array(unsigned n, double min, double max, double lsa[])
  {
  unsigned i;
  if ( (max > min) && (min > 0.)){
    double step = (log10(max) - log10(min))/(n-1);
    for (i = 0; i < n; i++){
      lsa[i] = pow(10.,log10(min) + i*step);
      }
    return 0;
    } else {
    return 1;
    }
  }

int linspace_array(unsigned int n, double min, double max, double lsa[])
  {
  unsigned int i;
  if ( (max > min) && (min >= 0.)){
    double step = (max - min)/(n-1);
    for (i = 0; i < n; i++){
      lsa[i] = min + i*step;
      }
    return 0;
    } else {
    return 1;
    }
  }

int double_integer_array(int min, int max, double lsa[])
{
    int i;
    if ( max > min )
    {
        for (i = min; i < max+1; i++)
        {
            lsa[i] = (double) i;
        }
        return 0;
    } 
    else 
    {
        return 1;
    }
}

double maxval( int len, double array[] )
  {
  int i;
  double maxval = array[0];
  for (i = 1; i < len; i++)
    {
    if ( maxval < array[i] )
      {
      maxval = array[i];
      }
    }
  return maxval;
  }

double minval( int len, double array[] )
  {
  int i;
  double minval = array[0];
  for (i = 1; i < len; i++)
    {
    if ( minval > array[i] )
      {
      minval = array[i];
      }
    }
  return minval;
  }

#endif
