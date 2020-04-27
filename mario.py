while True:
    print("alto: ",end="")
    n = int(input())
    if n>0 and n<=8:
        break

#next
for i in range(n):
    print(" " * (n-i-1),end="")# 3-0-(1 que es el valor que va ocupar el has)
    print("#" * (i+1))#0+1 si o si para poner 1 has como minimo

