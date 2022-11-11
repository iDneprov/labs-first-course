#include <stdio.h> //lab 11 variant 

char CheckTub(char s) {
  return ((int)s < 33 || s == ' ' || s == '.' || s == ',') ? 1 : 0;
}

char FindTubs(char sLast) {
  char s;
  while (s != EOF) {
    s = getchar();
     if (((int)s > 47 && (int)s < 58) && CheckTub(sLast)) {
      return s;
    }
    sLast = s;
  }
  return s;
}

int FindNum() {
  char s = FindTubs(' ');
  int firstNum = -2;
  int sim;
  while (CheckTub(s) == 0) {
    if (firstNum != -2) {
      s = FindTubs(s);
    }
  firstNum = -1;
  sim = (int)s;
  while (sim > 47 && sim < 58) {
    if (firstNum == -1) {
      firstNum++;
    }
    firstNum = firstNum * 10 + sim - 48;
    s = getchar();
    sim = (int)s;
  }
  }
  return (firstNum < 0) ? -1 : firstNum;
}

int Sum(int num) {
  int sum = 0, tens = 10;

  while (num / tens != 0) {
    sum += num % tens;
    num /= tens;
  }
  sum += num % tens;
  return sum;
}

int FindSecondToLast(int first, int second) {
  int flag = 1;
  int firstCheck, secondCheck;
  while (1) {
    if(flag == 1){
      firstCheck = FindNum();
      if (firstCheck < 0){
        break;
      }
      first = firstCheck;
      flag = 0;
    } else {
      secondCheck = FindNum();
      if(secondCheck < 0){
        break;
      }
        second = secondCheck;
        flag = 1;
      }
  }
  return (flag) ? first : second;
}

int SecondToLastNumber() {
  int firstNum, secondNum;
  firstNum = FindNum();
    if(firstNum == -1){
    printf("\nno decimal numbers\n");
    return -1;
    }
  secondNum = FindNum();
 if(secondNum == -1){
    printf("\none decimal numbers:%d\n", firstNum);
    return -1;
 }
  return FindSecondToLast(firstNum, secondNum); 
}

int main(void) {
  int anser = SecondToLastNumber();
  if(anser != -1){
  printf("\nNumber: %d Sum: %d\n", anser, Sum(anser));
  }
}
