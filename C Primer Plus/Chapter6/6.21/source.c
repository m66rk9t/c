/*投资问题*/
#include<stdio.h>
#include<stdlib.h>
#define Single_interest 10.0
#define Compound_interest_RATE 1.05
int main(void)
{
    double Daphne,Deirdre;
    int year=0;
    
    for(Daphne=100,Deirdre=100;Deirdre<=Daphne;year++)
    {
        Daphne+=Single_interest;
        Deirdre*=Compound_interest_RATE;
    }
    printf("After %d years, Deirdre's investment exceeds Daphne's investment.\n",year);
    printf("Daphne's investment: %lf.\n",Daphne);
    printf("Deirdre's investment:%lf.\n",Deirdre);

    system("pause");
    return 0;
}