#include <stdio.h>
#include <math.h>

#define PI 3.14159265

void var_input(char* str, float* f) {
  printf("%s", str);
  scanf("%f", f);
}

int main(int argc, char** argv) {
  float a, d, n1, n2, x;
  var_input("Incident angle : ", &a);
  var_input("Glass thicc    : ", &d);
  var_input("Index 1        : ", &n1);
  var_input("Index 2        : ", &n2);
  x = ((d*(cos(a*(PI/180)+asin((n1*cos(a*(PI/180)))/(n2)))))/(cos(asin((n1*cos(a*(PI/180)))/(n2)))));
  printf("Refractive shift : %3f\n", x);
  return 0;
}
