import numpy as np
import os

algoritmos = [(1, "seq"), (2, "binRec"), (3, "binIter")] 
tamanhos = [200, 2000, 20000]

for algoritmo in algoritmos:
    for tamanho in tamanhos:
        arq_saida = f"{algoritmo[1]}_{str(tamanho)}.csv"
        os.system(f"./main {algoritmo[0]} {tamanho} 28 > {arq_saida}")
        print(f"Pronto alg {algoritmo[1]} para tam {tamanho}")

