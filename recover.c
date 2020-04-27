#include <stdio.h>
#include <stdint.h>// Correponde a  typedef unint8_t BYTE
#include <stdbool.h>
//este software recupera una imagen
#define TAMAÑO_BLOQUE 512

typedef uint8_t BYTE; //nueva clase creada

//main general con argumentos
int main(int argc, char* argv[])
{//verificar cantidad de archivos por comando
    if(argc != 2){
         fprintf(stderr,"Usage: recover error sin archivo\n");
         //tambien existe, por su nombre
         //stdin, stdout, stderr
         return 1;
    }
    // Asignar el argumento a un string char (este nombre es el archivo en
    // cuestion)

    char *archivo = argv[1];
    
    //1 abrir ese archivo recibido  por argumento y moldeado ala variable >>>> "archivo"
    //2 fopen y la funcion a ralizar "R"
    // con mi puntero file
    
        FILE *filein= fopen(archivo,"r");
        
    //3 verificar si funciona el archivo que recibo por comando
        if(filein == NULL){
            fprintf(stderr,"el archivo %s. no funciona \n",archivo);
            return 2;
        }
        
        
                                                                //creacion de un objeto (array) de la clase BYTE
                                                                BYTE buffer[512];
                                                                //variables
                                                                int contarImagen=0;
                                                                
                                                                // archivos complementarios
                                                                char nombreArchivo[8];//8 byts max
                                                                
                                                                FILE *salida=NULL;
                                                                
    //CICLO
    while(true)
    {
        //leer los cuadrados de memoria de la camara
/*una tipo de dato*/size_t lectura= fread(buffer,sizeof(BYTE),TAMAÑO_BLOQUE,filein);
                                        //array---8bytes cuan larga--cuantas unidades--archivo recibido
                    // FEOF hace lo siguiente
                    //Devuelve 0 ("falso") si no se ha alcanzado el final del fichero o archivo
                    // o un valor distinto de cero ("verdadero") si se ha llegado
                    if(lectura==0 && feof(filein)){
                            break;
                    }                                    
                    //chequiar si encontramos un JPEG
                    bool buscar= buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]== 0xff && (buffer[3] & 0xf0)==0xe0;
                    
                    // si NO encontramos mas JPEG, cerramos el archivo o file
                    if(buscar && salida != NULL){
                            fclose(salida);
                            contarImagen++;
                    }
                    
                    //si encontramos un JPEG, abrimos el archivo o file y escribimos
                    
                    if(buscar){
                        
                        sprintf(nombreArchivo,"%03i.jpg",contarImagen);
                        salida=fopen(nombreArchivo,"w");
                            
                    }
                    
                    //escribir cada vez que tengamos el archivo abierto
                    if(salida !=NULL){
                        fwrite(buffer,sizeof(BYTE),lectura,salida);
                    }

    }
    
    fclose(salida);
    fclose(filein);
    return 0;
    
    
    
    
}
