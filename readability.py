from cs50 import get_string
import re
from math import ceil
def main():
    texto = input("Insert your text: ")
    sumaLetras=0
    sumaPalabras=1
    sumaOraciones=0

    #ciclos
    for i in range(len(texto)):
         if re.findall("[a-z]",texto[i]):
             sumaLetras=sumaLetras+1
    for i in range(len(texto)):
         if re.findall(" ",texto[i]):
             sumaPalabras=sumaPalabras+1
    for i in range(len(texto)):
         if  re.findall("[.]|[!]|[?]",texto[i]) :
             sumaOraciones=sumaOraciones+1

   # print(sumaLetras)
   # print(sumaPalabras)
   # print(sumaOraciones)

#Promedio de todo
    promedioLetras = float(sumaLetras*100)/float(sumaPalabras)
    promedioOraciones=float(sumaOraciones*100)/float(sumaPalabras)
#Formula
    index=0.0588 * promedioLetras -0.296 * promedioOraciones - 15.8

    if (index < 16 and index >=0):
        print(f"Grade {int(ceil(index))} ")
    elif (index >=16):
        print(f"Grade 16+ ")
    else:
        print("Before Grade 1 ")



if __name__ == "__main__":
    main()
