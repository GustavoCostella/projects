#Programa em python que controle a retirada de dinheiro de um cofre.
#Gustavo Costella Barbosa e-mail: gustavocostellabarbosa@hotmail.com // github.com/GustavoCostella
import os
qntd100=0
qntd50=0
qntd20=0
qntd10=0
qntd05=0
while True:
    valor = int(input("Quanto você quer sacar? "))
    qntd100=0
    qntd50=0
    qntd20=0
    qntd10=0
    qntd05=0
    if valor <= 0:
        print("Não é possivel sacar o dinheiro")
        exit()
    if (valor >=100 ):
        qntd100=valor//100
        valor=valor-(qntd100*100)

    if (valor >=50):
        qntd50=valor//50
        valor=valor-(qntd50*50)

    if (valor >=20):
        qntd20=valor//20
        valor=valor-(qntd20*20)

    if (valor >=10 ):
        qntd10=valor//10
        valor=valor-(qntd10*10)

    if (valor >=5):
        qntd05=valor//5
        valor=valor-(qntd05*5)
    print ("Foram utilizadas",qntd100,"notas de R$100,00")
    print ("Foram utilizadas",qntd50,"notas de R$50,00")
    print ("Foram utilizadas",qntd20,"notas de R$20,00")
    print ("Foram utilizadas",qntd10,"notas de R$10,00")
    print ("Foram utilizadas",qntd05,"notas de R$5,00") 
    resto = valor
    print("Resto na conta: ",resto)
os.system("PAUSE")
