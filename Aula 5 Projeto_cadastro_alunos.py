# opc do menu:
# 1. Adicionar aluno
# 2. Listar todos os alunos
# 3. Buscar aluno pelo nome
# 4. Remover aluno
# 5. Mostrar média geral das notas
# 6. Sair

Alunos = {
    'Nome': [],
    'Idade': [],
    'Nota': [],
}

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
            nota = float(input())
            adicionar_aluno(nome, idade, nota)
            

        case 2: #Listar todos os alunos
            if Alunos["Nome"] == []:
                print("\nNão existe nenhum aluno cadastrado.\n")
            else:
                print(f"\n{Alunos}")
                        
        case 3: #Buscar aluno pelo nome
            print(f"Digite o nome do aluno: ")
            
        case 4: #Remover aluno
            print(f"{Alunos}")

            
        case 5: #Mostrar média geral das notas
            print(f"{Alunos}")

                        
        case 6:
            print(f"Encerrando o programa...\n")

        case _:
            print(f"Opção inválida\n")