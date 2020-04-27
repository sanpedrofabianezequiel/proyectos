#include "helpers.h"
#include <math.h>
//Este software crea filtros estilo Instagram
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
/*Creo un float donde almacenar el nuevo resultado gris*/
            float gris;
                    for(int i=0; i < width;i++){
                                    for(int j=0;j < height;j++){
                                        //promediar los colores
/*Uso la propiedad del objeto "Imagen" perteneciente a la classe RGBTIPLE*/  gris= round((image[j][i].rgbtBlue + image[j][i].rgbtGreen + image[j][i].rgbtRed)/3.000 );
                                        
                                        //Asignar el resultado al Array bidemensional
                                        image[j][i].rgbtBlue= gris;
                                         image[j][i].rgbtGreen= gris;
                                          image[j][i].rgbtRed= gris;
                                    }
                    }
}







  //////////////////////////////////limitar hasta 255
                int limite(int max){
                            if(max>255){
                                max=255;
                            }
                    return max;
                }



// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
        int red;
        int green;
        int blue;
                for(int i=0;i<width;i++){
                                for(int j=0;j<height;j++){
                                    //1- vuelvo a resolver el calculo, en este caso me dan el algoritmo
                                    //2-lo redondeo
                                    //3 uso funcion limit para sepia y lo limito el resultado a 255
                                    red=limite(round(.393 * image[j][i].rgbtRed + .769 * image[j][i].rgbtGreen + .189 * image[j][i].rgbtBlue));
                                   green=limite(round(.349 * image[j][i].rgbtRed + .686 * image[j][i].rgbtGreen + .168 * image[j][i].rgbtBlue));
                                    blue=limite(round(.272 * image[j][i].rgbtRed + .534 * image[j][i].rgbtGreen + .131 * image[j][i].rgbtBlue));
                                    
                                    //4- asigno ese resultado  a las nuevas variables que cree
                                    image[j][i].rgbtBlue=blue;
                                    image[j][i].rgbtGreen=green;
                                    image[j][i].rgbtRed=red;
                                }
                }
        
                //algoritmo que nos da Harvard
            /*sepiaRed (mi varaible creada va aquie "red")= .393 * originalRed + .769 * originalGreen + .189 * originalBlue
              sepiaGreen (mi varaible creada va aquie "green") = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
              sepiaBlue (mi varaible creada va aquie "blue") = .272 * originalRed + .534 * originalGreen + .131 * originalBlue*/
           
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
       //variables o array temporales
       int temporal[3];
       
        
        for(int j=0;j<height;j++){
                    for(int i=0;i<width/2;i++){
                        temporal[0]=image[j][i].rgbtBlue;
                        temporal[1]=image[j][i].rgbtGreen;
                        temporal[2]=image[j][i].rgbtRed;
                        
                        //cambiar de posiscion // trazladarlo le resto "i" y "-1" luego utilizo eso como ubicacion y se le asigna el original
                        
                        image[j][i].rgbtBlue=image[j][width-i-1].rgbtBlue;
                        image[j][i].rgbtGreen=image[j][width-i-1].rgbtGreen;
                        image[j][i].rgbtRed=image[j][width-i-1].rgbtRed;
                        // ubicar donde corresponde
                        //La nueva ubicacion se vera modificada por el "Adicional" de la variable temporal u original
                       image[j][width-i-1].rgbtBlue=temporal[0];
                       image[j][width-i-1].rgbtGreen=temporal[1];
                       image[j][width-i-1].rgbtRed=temporal[2];
                               
                    }
        }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    
    
    
    
    
    return;
}
