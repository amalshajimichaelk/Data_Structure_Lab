#include <stdio.h>
struct poly{
  int coeff;
  int exp;
  };
int main(){
  int i,j, n, m, k=0,a;
  struct poly p1[10], p2[10], p3[10];
  printf("Enter the no. of terms of 1st polynomial: ");
  scanf("%d", &n);
  printf("Enter the terms of 1st polynomial:\n");
  for(i=0; i<n; i++){
    printf("Enter the coefficient and exponent of term %d: ", i+1);
    scanf("%d%d", &p1[i].coeff, &p1[i].exp);
    }
  for(i=0; i<n; i++){
  if(p1[i].exp != 0){
    printf("%d(x^%d)+", p1[i].coeff, p1[i].exp);
    }
  else{
    printf("%d\n", p1[i].coeff);
    }
  }
  printf("Enter the no. of terms of 2nd polynomial: ");
  scanf("%d", &m);
  printf("Enter the terms of 2nd polynomial:\n");
  for(j=0; j<m; j++){
    printf("Enter the coefficient and exponent of term %d: ", j+1);
    scanf("%d%d", &p2[j].coeff, &p2[j].exp);
    }
   for(j=0; j<m; j++){
  if(p2[j].exp != 0){
    printf("%d(x^%d)+", p2[j].coeff, p2[j].exp);
    }
  else{
    printf("%d\n", p2[j].coeff);
    }
  }
    while(i<m && j<n){
      if(p1[i].exp == p2[j].exp){
        p3[k].coeff = p1[i].coeff + p2[j].coeff;
        p3[k].exp = p1[i].exp;
        i++, j++, k++;
        }
      else if(p1[i].exp > p2[j].exp){
        p3[k].coeff = p1[i].coeff;
        p3[k].exp = p1[i].exp;
        i++, k++;
        }
      else{
        p3[k].coeff = p2[j].coeff;
        p3[k].exp = p2[j].exp;
        j++, k++;
        }
      }
    while (i<n){
        p3[k].coeff = p1[i].coeff;
        p3[k].exp = p1[i].exp;
        i++, k++;
        }
    while (j<m){
        p3[k].coeff = p2[j].coeff;
        p3[k].exp = p2[j].exp;
        j++, k++;
        }
printf("The Resultant Polynomial:\n");
for(a=0; a<m; a++){
if(p3[a].exp != 0){
    printf("%d(x^%d)+", p3[a].coeff, p3[a].exp);
    }
  else{
    printf("%d\n", p3[a].coeff);
    }
}
return 0;
}
