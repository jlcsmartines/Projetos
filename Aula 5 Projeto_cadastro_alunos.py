#Programa de Cadastro de alunos básico

Alunos = {
    'Nome': [],
    'Idade': [],
    'Nota': []}

def menu():
    print("1. Adicionar aluno\n")
    print("2. Listar todos os alunos\n")
    print("3. Buscar aluno pelo nome\n")
    print("4. Remover aluno\n")
    print("5. Mostrar média geral das notas\n")
    print("6. Sair\n")

def adicionar_aluno(nome, idade, nota):
    Alunos['Nome'].append(nome)
    Alunos['Idade'].append(idade)
    Alunos['Nota'].append(nota)

def pesquisar_aluno(nome):
    index = int(Alunos['Nome'].index(nome))
    print (f"\n{Alunos['Nome'][index]} | {Alunos['Idade'][index]} | {Alunos['Nota'][index]}\n")

def remover_aluno(nome):
    index = int(Alunos['Nome'].index(nome))
    Alunos['Nome'].pop(index)
    Alunos['Idade'].pop(index)
    Alunos['Nota'].pop(index)

def media_aluno():
    media = 0
    for nota in Alunos['Nota']:
        media += nota
    media = media / len(Alunos['Nota'])
    return media
    
opcao = 0
while opcao != 6:
    menu()
    print("Digite a opção que deseja acessar: ")
    opcao = int(input())
    match opcao:

        case 1: #Adicionar aluno
            print("Para adicioanr um aluno, digite: 'Nome' 'Idade' 'Nota'")
            nome = str(input())
            idade = int(input())
            while True:
                nota = float(input())
                if nota >0 and nota <= 10:
                    break
                else:
                    print("\nDigite uma nota que seja de 0 a 10\n")
            adicionar_aluno(nome, idade, nota)         

        case 2: #Listar todos os alunos
            if Alunos["Nome"] == []:
                print("\nNão existe nenhum aluno cadastrado.\n")
            else:
                for i in range(len(Alunos['Nome'])):
                    print(f"Nome: {Alunos['Nome'][i]} | Idade: {Alunos['Idade'][i]} | Nota: {Alunos['Nota'][i]}")
                        
        case 3: #Buscar aluno pelo nome
            print(f"Digite o nome do aluno: ")
            nome_pesquisa = str(input())
            pesquisar_aluno(nome_pesquisa)
            
        case 4: #Remover aluno
            print(f"Digite o nome do aluno que deseja Remover: ")
            remover = input()
            remover_aluno(remover)
           
        case 5: #Mostrar média geral das notas
            print(media_aluno())

        case 6:
            print(f"Encerrando o programa...\n")

        case _:
            print(f"Opção inválida\n")