import os 

arquivos = ['1000-contrario.txt', '1000-misturado.txt',
            '1000-ordenado.txt', '1000-quaseordenado.txt']

condicao = ['contrario', 'misturado', 'ordenado', 'quaseordenado']

algoritmos = [1, 12, 2, 21, 3, 32]
nomeAlgoritmo = ['ins', 'insR', 'selec', 'selecR', 'bubble', 'bubbleR']

os.system("clear")
for i, algoritmo in enumerate(algoritmos):
    for j, arquivo in enumerate(arquivos):

        nome_saida = f"res_"+nomeAlgoritmo[i]+"_"+condicao[j]+".csv"

        print(f"Processando {nome_saida}")

        os.system(f"./analisa {algoritmo} < {arquivo} > {nome_saida}")
        os.system("clear")
    
    os.system("clear")
        


