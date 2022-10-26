Слесарчук В.А. ЛР№ 9

# ЛР №9

Слесарчук Василий

## Задние
Вариант № 22
![](https://i.imgur.com/8Eqz0Gr.jpeg)

## Код

    #include <stdio.h>
    #include <stdbool.h>

    int sign(int a) {
      if (a > 0) { return 1; }
      if (a < 0) { return -1; }
      if (a == 0) { return 0; }
    }

    int max(int a, int b) {
      if (a >= b) { return a;}
      else { return b; }
    }

    int min(int a, int b) {
      if (a <= b) { return a; }
      else { return b; }
    }

    int abs(int a) {
      if (a < 0){ return a * (-1); }
      else { return a; }
    }

    int calc_i(int i, int j, int l, int k) {
      return (((i + j) % (abs(min(j - l, l - k)) + 1) - k) % 20) + 10;
    }

    int calc_j(int i, int j, int l, int k) {
      int a = (i + j) / (2 + sign((j * l) - (i * k)));
      int b = (j + l) / (2 + sign((i * j) - (l * k)));
      return (max(a, b) - 10);
    }

    int calc_l(int i, int j, int l, int k) {
      return ((max(i, j) * min(i, l)) % 30);
    }

    bool check_it_out(int i, int j) {
      int inf_j = 0;
      int sup_j = 10 - i;
      int sup_i = 10;
      int inf_i = -10;
      if (((i >= inf_i) & (i <= sup_i)) & ((j >= inf_j) & (j <= sup_j))) { return true; }
      else { return false; }
    }

    void start_calc(int i, int j, int l) {
      bool flag = false;
      for (int k = 0; k <= 49; k++)
      {
        int cur_i = i;
        int cur_j = j;
        int cur_l = l;

        i = calc_i(cur_i, cur_j, cur_l, k);
        j = calc_j(cur_i, cur_j, cur_l, k);
        l = calc_l(cur_i, cur_j, cur_l, k);


        if (check_it_out(i, j) == true)
        {
          flag = true;
          printf("ALERT! DOT IN THE AREA!!\nTime: k = %d\nDot coords: (%d, %d)\nDynamic motion parameter: %d\n\n", k + 1, i, j, l);
          break;
        }
      }
      if (flag == false) { printf("TIME OUT!!\nDOT NOT IN THE AREA\nTime: k = %d\nDot coords: (%d, %d)\nDynamic motion parameter: %d\n\n", 50, i, j, l); }
    }

    int main(void) {
      int i = 8, j = 15, l = 10;
      start_calc(i, j, l);
      return 0;
    }
