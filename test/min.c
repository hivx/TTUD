#include<stdio.h>
# define pi 3.14159
int main() {
    float r;
    scanf("%f",&r);
    if(r<=0) {
        printf("ERROR");
        return 0;
    }
    printf("%f",r*2*pi);
    printf("%f",pi*r*r);
    return 0;

}
