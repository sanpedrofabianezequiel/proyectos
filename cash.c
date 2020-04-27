#include <cs50.h>
#include <stdio.h>
#include <math.h>
# Este software permite ingresar cierta cantidad de monedas, y calcular cuanto seria la mejor y cantidad justa de monedas que tendria que dar de vuelto
int main(void)
{
        float dollars;
        do  {
        //float
         dollars= get_float("change owed: ");
        }while( dollars <=0);
       

        //redondear
        int cents = round(dollars * 100);

        int cantidadMonedas=0;

        int denominacion[]={25,10,5,1};
            for(int i=0;i<4;i++){
                        while(cents>=denominacion[i])
                        {
                            cents-=denominacion[i]; 
                            cantidadMonedas++;
                        }
                 }
        printf("%i\n",cantidadMonedas);

}
