from cs50 import get_float
def main():
    while True:
        dollar =get_float("Give your money: ")
        if dollar >=0:
            break

    #redondear ??
    centavo = int(dollar*100)

    print(funcion(centavo))

#funcion
def funcion(centavos):
    totalMonedas=0
    lista =[25,10,5,1]

    while centavos >=25:
        centavos= centavos -25
        totalMonedas = totalMonedas+1
    while centavos >=10:
        centavos= centavos -10
        totalMonedas = totalMonedas+1
    while centavos >=5:
        centavos= centavos -5
        totalMonedas= totalMonedas+1
    while centavos >=1:
        centavos= centavos -1
        totalMonedas =totalMonedas+1
    return totalMonedas





if __name__=="__main__":
    main()
