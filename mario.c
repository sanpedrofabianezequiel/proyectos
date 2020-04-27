#include <cs50.h>
#include <stdio.h>

int get__int(string mouse);
int main(void)
{
    
            int n;
            do{
                n = get_int("Height: ");
            }while(n<1 || n>8);
                  

            




    //for general
        for(int i = 0 ; i < n; i ++){   
            //for espacios
            
            for(int j = n-1 ; j > i; j --)
                printf(" "); 

                 //for hastes   
                for(int j = 0 ; j <= i; j ++)
                        printf("#"); 
                        
                                                                   
                        printf("\n");
                                                                           
                     }

        
                 
  
}
//first i need declaration the function
