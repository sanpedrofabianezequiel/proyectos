#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#Este software permite mediante una formula, determinar la complejidad de un texto.

int main(void)
{
    string text = get_string("Text: ");
    int sumaLetras = 0;
    int sumaPalabras = 1;
    int sumaOraciones = 0;

//count words
    for (int i = 0; i < strlen(text); i++)
    {
       if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
       {
           sumaLetras++;
       }
       else if (text[i] == ' ')
       {
           sumaPalabras++;
       }
       else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
       {
           sumaOraciones++;
       }
    }
//    printf("letras: %i; palabras: %i; oraciones: %i\n", sumaLetras, sumaPalabras, sumaOraciones);


            float promedioLetras=((float)sumaLetras*100)/(float)sumaPalabras;
            float promedioOraciones=((float)sumaOraciones*100)/(float)sumaPalabras;

    float index = 0.0588 * promedioLetras - 0.296 * promedioOraciones - 15.8;
    
    if (index < 16 && index >= 0)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

}
