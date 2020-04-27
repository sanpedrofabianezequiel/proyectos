#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
//este software realiza una eleccion presidencial 
//Defino la constante
#define MAX 9
//Defino la Clase Candidate
typedef struct{
    string name;
    int votes;
    
} candidate;
//Defino el objeto de la Clase
    candidate candidates[MAX];
//Defino una variable global
int candidate_count;// cuenta la cantidad de candidatos
//funciones para usar
bool vote (string names);
void print_winner(void);
     int main(int argc, string argv[])
     {  
            //Pedir el nombre (cantidad) de candidatos y copiarlos en el array u objeto
            //Obviamente restringir con sus respectivas clausulas
            if(argc <=1 ){
                printf("Invalid vote. \n");
                return 1;
            }else{
                candidate_count = (argc-1);// lo paso a la variable candiadate_count x comodida
            }
            
            if(candidate_count > MAX ){
                printf("Invalid vote Limite Max Candidates. %i. \n", MAX);
                return 2;
            }
            // asignar los nombres de los postulantes  al objeto/array
                for(int i = 0; i < candidate_count;i++){
                    
                    
                    candidates[i].name = argv[i+1] ;
                    candidates[i].votes=0;
                }
            
            // Ingresar el numero de votantes         
            int numberVotantes = get_int("Number Votantes: ");
                for(int i=0;i < numberVotantes; i++){
                    string nameVotado = get_string("Voto a: ");
               
                        //Funciones
                        if(!vote(nameVotado))
                        {
                            printf("Invalid vote. \n");
                        }
                 }
         
         
         print_winner();
     }//Aca termina el Main  

//funciones
bool vote (string nameVotado2){
        for(int i=0;i<candidate_count;i++){
            
                    if(strcmp(candidates[i].name,nameVotado2)==0){
                        candidates[i].votes++;
                        return true;
                    }
        }
    return false;
    
}
void print_winner(void){
    
        int maxVotos=0;
            for(int i=0;i<candidate_count;i++){
                    if(candidates[i].votes > maxVotos){
                        maxVotos=candidates[i].votes;
                    }
                
            }
            
            for(int i=0;i<candidate_count;i++){
                    if(candidates[i].votes == maxVotos  ){
                        printf("%s\n",candidates[i].name);
                        
                    }
                
            }
    
    return;// para retornar 
    
    
}
