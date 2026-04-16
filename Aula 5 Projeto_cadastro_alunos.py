#Programa de Cadastro de alunos básico

import json #para poder salvar em um arquivo txt as informações dos alunos

try: # irá carregar todos os alunos pelo arquivo .txt ou caso nn exista o arquivo, irá abrir uma nova lista para adicionar alunos
    with open("Cadastros.txt", "r") as f:
        Alunos = json.load(f)
except:
    Alunos = {
        'Nome': [],
        'Idade': [],
        'Nota': []}

def menu():  #mostra o menu
    print("\n1. Adicionar aluno") 
    print("2. Listar todos os alunos")
    print("3. Buscar aluno pelo nome")
    print("4. Remover aluno")
    print("5. Mostrar média geral das notas")
    print("6. Sair\n")

def salvar_dados(): #irá salvar os dados dos alunos no arquivo txt
    with open("Cadastros.txt", "w") as f:
        json.dump(Alunos, f)    

def adicionar_aluno(nome, idade, nota): #irá adicionar um novo aluno ao sistema
    Alunos['Nome'].append(nome)
    Alunos['Idade'].append(idade)
    Alunos['Nota'].append(nota)

def pesquisar_aluno(nome): #irá pesquisar um aluno pelo seu nome e trazer informações
    if nome in Alunos['Nome']:
        index = int(Alunos['Nome'].index(nome))
        print (f"\n{Alunos['Nome'][index]} | {Alunos['Idade'][index]} | {Alunos['Nota'][index]}\n")
    else:
        print("Aluno não encontrado")    
    
def remover_aluno(nome): #irá remover o aluno do sistema
    if nome in Alunos['Nome']:
        index = int(Alunos['Nome'].index(nome))
        print(f"Removendo aluno(a): '{Alunos['Nome'][index]}'")
        Alunos['Nome'].pop(index)
        Alunos['Idade'].pop(index)
        Alunos['Nota'].pop(index)
    else:
        print("\nAluno não encontrado")

def media_aluno(): #mostra a média geral da escola
    media = 0
    if len(Alunos['Nota']) != 0:
        return sum(Alunos['Nota']) / len(Alunos['Nota'])
    else:
        return "Não existem alunos cadastrados no momento\n"

opcao = 0
while opcao != 6: #while onde funciona o sistema :p
    menu()
    print("Digite a opção que deseja acessar: ")
    opcao = int(input())
    match opcao:

        case 1: #Adicionar aluno
            print("Para adicioanr um aluno, digite: \n")
            print("Digite o Nome do Aluno: ")
            nome = str(input())
            print("Digite a Idade do Aluno: ")
            idade = int(input())
            print("Digite a Nota do Aluno: ")
            while True:
                nota = float(input())
                if nota >= 0 and nota <= 10:
                    break
                else:
                    print("\nDigite uma nota que seja de 0 a 10\n")
            adicionar_aluno(nome, idade, nota)         

        case 2: #Listar todos os alunos
            if Alunos["Nome"] == []:
                print("\nNão existe nenhum aluno cadastrado.\n")
            else:
                print("\n")
                for i in range(len(Alunos['Nome'])):
                    print(f"Nome: {Alunos['Nome'][i]} | Idade: {Alunos['Idade'][i]} | Nota: {Alunos['Nota'][i]}")
                    print("________________________________________________________________________________________\n")
                        
        case 3: #Buscar aluno pelo nome
            print(f"Digite o nome do aluno: ")
            nome_pesquisa = str(input())
            pesquisar_aluno(nome_pesquisa)
            
        case 4: #Remover aluno
            print(f"Digite o nome do aluno que deseja Remover: ")
            remover = input()
            remover_aluno(remover)
           
        case 5: #Mostrar média geral das notas
            print(f'Média dos alunos: {media_aluno():.2f}')

        case 6: #encerrar programa e salvar as informaões dos alunos no arquivos .txt
            salvar_dados()
            print(f"Encerrando o programa...\n")

        case _:
            print(f"Opção inválida\n")