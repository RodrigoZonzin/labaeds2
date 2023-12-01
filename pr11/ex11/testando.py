import os 

arquivos = ['10000-contrario.txt', '10000-misturado.txt',
            '10000-ordenado.txt', '10000-quaseordenado.txt']

condicao = ['contrario', 'misturado', 'ordenado', 'quaseordenado']

algoritmos = [1, 12, 2, 21, 3, 32,4 ,2]
nomeAlgoritmo = ['shell', 'shellR', 'quick', 'quickR', 'heap', 'heapR', 'merge', 'mergeR']

os.system("clear")
for i, algoritmo in enumerate(algoritmos):
    for j, arquivo in enumerate(arquivos):

        nome_saida = f"res_"+nomeAlgoritmo[i]+"_"+condicao[j]+".csv"

        print(f"Processando {nome_saida}")

        os.system(f"./ord {algoritmo} < {arquivo} > {nome_saida}")
        os.system("clear")
    
    os.system("clear")
        


