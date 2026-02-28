#include <stdio.h>

int main(){
    // Brute Force Solution
    int a,b,c,d,e,f;
    scanf("%d %d %d", &a,&b,&c);
    scanf("%d %d %d", &d,&e,&f);
    printf("%d %d %d\n", d-a, e-b, f-c);


    // Elegant Solution
    typedef struct Jam {
        int Hour;
        int Minutes;
        int Seconds;
    } Jam;

    Jam old,new;
    scanf("%d %d %d", &old.Hour, &old.Minutes, &old.Seconds);
    scanf("%d %d %d", &new.Hour, &new.Minutes, &new.Seconds);
    printf("%d %d %d", new.Hour-old.Hour,new.Minutes-old.Minutes,new.Seconds-old.Seconds);

    return 0;
}