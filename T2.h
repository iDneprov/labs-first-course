#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
//#include "TxLib.h"

//{----------------------------------------------------------------------------------------------------------------
//! @file
//! @mainpage
//! @author ������ �������.
//!
//! � ������ ������ ����������, ������ �������� ��� � ���� �������.
//!
//! @par ������ �������:
//! -#   @ref Output ()
//}----------------------------------------------------------------------------------------------------------------

void Output(int massiv[], int n, const char name[]);

void MassivInit(int massiv[], int n, double d);

void FillingMassiv(int massiv[], int n);

void FillingStrok(char massiv[], int n);

int CheckEqualMassiv (int seq_1[], int seq_2[], int n);

int CheckEqualStrok (char seq_1[], char seq_2[], int n);

int SummElemMass(int massiv[], int n);

int MaxElemMass(int mass[], int n);

int MinElemMass(int mass[], int n);

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
//!         FillingMassiv’?
//!             int seq1[n] = {};
//!             int seq2[n] = {};
//!             int summSeq[n] = {};
//!
//!             MassivInit(seq1, n, 2);
//!             MassivInit(seq2, n, 1);
//!             SummMassiv(summSeq, seq1, seq2, n);
//!
//!             Output (seq1,    n, "seq1   ");
//!             Output (seq2,    n, "seq2   ");
//!             Output (summSeq, n, "summSeq");
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
//!             int seq1[n] = {};
//!             int seq2[n] = {};
//!
//!             MassivInit(seq1, n, 2);
//!             MassivInit(seq2, n, 1);
//!
//!             SummElemMas (seq1, n,);
//!
//!             return 0;
//!         }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------


void Output(int massiv[], int n, const char name[])
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


int SummElemMass(int massiv[], int n)
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


void MassivInit(int massiv[], int n, double d)
{
  assert(massiv != 0);
  
  for (int i = 0; i < n; i++)
  {
    assert(i < n);
    
    massiv[i] = massiv[0] + d*i;
  }
}


void FillingMassiv(int massiv[], int n)
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


void FillingStrok(char massiv[], int n)
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


int MaxElemMass(int mass[], int n)
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


int MinElemMass(int mass[], int n)
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


int CheckEqualMassiv (int seq_1[], int seq_2[], int n)
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


int CheckEqualStrok (char seq_1[], char seq_2[], int n)
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
