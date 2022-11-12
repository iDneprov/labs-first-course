#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <cctype>
//#include "TxLib.h"

//{----------------------------------------------------------------------------------------------------------------
//! @file
//! @mainpage
//! @author ������ �������.
//!
//! � ������ ������ ����������, ������ �������� ��� � ���� �������.
//!
//! @par ������ �������:
//! -#   @ref output ()
//}----------------------------------------------------------------------------------------------------------------

void output(int massiv[], int n, const char name[]);

void massiv_init(int massiv[], int n, double d);

void filling_massiv(int massiv[], int n);

void filling_strok(char massiv[], int n);

int check_equal_massiv (int seq_1[], int seq_2[], int n);

int check_equal_strok (char seq_1[], char seq_2[], int n);

int summ_elem_mass(int massiv[], int n);

int max_elem_mass(int mass[], int n);

int min_elem_mass(int mass[], int n);

//{----------------------------------------------------------------------------------------------------------------
//! ���������� �������.
//!
//! @param   massiv ������ ��� ����������.
//! @param   n      ����� �������.
//! @param   name   ��� ����������� �������.
//!
//! @par ������ �������������
//! @code
//!         int main ()
//!         filling_massiv’?
//!             int seq_1[n] = {};
//!             int seq_2[n] = {};
//!             int summ_seq[n] = {};
//!
//!             massiv_init(seq_1, n, 2);
//!             massiv_init(seq_2, n, 1);
//!             summ_massiv(summ_seq, seq_1, seq_2, n);
//!
//!             output (seq_1,    n, "seq_1   ");
//!             output (seq_2,    n, "seq_2   ");
//!             output (summ_seq, n, "summ_seq");
//!
//!             return 0;
//!         }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------


//{----------------------------------------------------------------------------------------------------------------
//! ����� ��������� �������.
//!
//! @param   massiv ������ ��� ����������.
//! @param   n      ����� �������.
//!
//! @par ������ �������������
//! @code
//!         int main ()
//!         {
//!             const int n = 5;
//!
//!             int seq_1[n] = {};
//!             int seq_2[n] = {};
//!
//!             massiv_init(seq_1, n, 2);
//!             massiv_init(seq_2, n, 1);
//!
//!             summ_elem_mas (seq_1, n,);
//!
//!             return 0;
//!         }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------


void output(int massiv[], int n, const char name[])
{
  printf ("%s = {", name);
  
  assert(massiv != 0);
  
  for (int i = 0; i < n; i++)
  {
    assert(i < n);
  
    printf ("[%d] = %2d", i, massiv[i]);

    if (i < n - 1)
        printf (", ");
  }
  printf ("}\n");
}


int summ_elem_mass(int massiv[], int n)
{
  int summ = 0;

  assert(massiv != 0);
  
  for (int i = 0; i < n; i++)
  {
    assert(i < n);
    
    summ += massiv[i];
  }
 // printf("summ = %d\n", summ);

  return summ;
}


void massiv_init(int massiv[], int n, double d)
{
  assert(massiv != 0);
  
  for (int i = 0; i < n; i++)
  {
    assert(i < n);
    
    massiv[i] = massiv[0] + d*i;
  }
}


void filling_massiv(int massiv[], int n)
{
  bool res = true;

  printf("Ввод массива:\n");
  
  assert(massiv != 0);
  
  for (int i = 0; i < n; i++)
  {
    assert(i < n);
    
    printf("Введи %d число массива, мраз: ", i);
    res = scanf("%d", &massiv[i]);
    
    if (res != true)
    {
      printf("Криво ввел\n");
      
      assert(res == true);
    }
  }
  printf("\n");
}


void filling_strok(char massiv[], int n)
{
  bool res = true;

  printf("Ввод строки:\n");
  
  assert(massiv != 0);
  
  printf("Введи строку, мраз: ");
    
  res = fgets(massiv, n, stdin);
    
  if (res != true)
  {
    printf("Криво ввел\n");
      
    assert(res == true);
  }
  printf("\n");
}


int max_elem_mass(int mass[], int n)
{
  int max = mass[0];
  
  assert(mass != 0);
  
  for (int i = 0; i < n; i++)
  {
    assert(i < n);

    if(mass[i] > max)
        max = mass[i];
  } 
 // printf("max = %d \n", max);

  return max;
}


int min_elem_mass(int mass[], int n)
{
  int min = mass[0];
  
  assert(mass != 0);
  
  for (int i = 0; i < n; i++)
  {
    assert(i < n);
    
    if(mass[i] < min)
        min = mass[i];
  }
  //printf("min = %d \n", min);

  return min;
}


int check_equal_massiv (int seq_1[], int seq_2[], int n)
{
  assert(seq_1 != 0);
  
  assert(seq_2 != 0);
  
  for (int i = 0; i < n; i++)
  {
    assert(i < n);
    
    if (seq_1[i] != seq_2[i])
        return false;
  }
  return true;
}


int check_equal_strok (char seq_1[], char seq_2[], int n)
{
  assert(seq_1 != 0);
  
  assert(seq_2 != 0);
  
  for (int i = 0; i < n; i++)
  {
    assert(i < n);
    
    if (seq_1[i] != seq_2[i])
        return false;
  }
  return true;
}
