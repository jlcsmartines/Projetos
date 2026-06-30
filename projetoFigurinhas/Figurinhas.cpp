/*

STICKER MARKET FIFA® WORLD CUP 2026 | V1

Projeto de um sistema
Tema do sistema: Controle de figurinhas da copa do mundo
©Made by:   João Lucas Martines

*/

#include <iostream>
#include <locale>
#include <vector>
#include <string>
#include <cstdlib> // para limpar o cmd após cada loop do menu, deixando mais limpo visualmente

/* Programa não estava aceitando using namespace std */
using std::cin;
using std::cout; 
using std::endl;
using std::getline;
using std::string;
using std::vector;

/* STRUCT e VETOR*/
struct Figurinha
{
    int codigo;
    string nome;
    bool ativo;
    int estoque;
    double valor;
};

int main()
{
    setlocale(LC_ALL, "Portuguese");

    /* Variáveis de Menus */
    int menu = 0;        // Variável para navegação do menu principal
    int menu_cadastro;   // Variável para navegação do submenu de cadastro
    int menu_listagem;   // Variável para navegação do submenu de listagem
    int menu_consulta;   // Variável para navegação do submenu de consulta
    int menu_alteracao;  // Variável para navegação do submenu de alteração
    int menu_entrada;    // Variável para navegação do submenu de entrada de estoque
    int menu_venda;      // Variável para navegação do submenu de lançamentos de vendas
    int menu_inativacao; // Variável para navegação do submenu de inativação e ativação

    /* Variáveis de verificação */
    bool duplicidade;          // Variável para verificar se o código da figurinha já está cadastrado
    int confirmacaoInativacao; // Variável para armazenar a confirmação do usuário sobre a inativação da figurinha
    int confirmacaoAtivacao;   // Variável para armazenar a confirmação do usuário sobre a ativação da figurinha

    /* NOME DO VETOR COM AS FIGURINHAS: "Album" */
    vector<Figurinha> Album;

    /* Figurinhas Pré Carregadas para apresentação */
    Album = {
        /*Cod | Nome  |  ativo| quant | valor*/
        {5519, "Endrick", false, 1, 20.70},
        {5507, "Vinícios Jr.", true, 2, 50.30},
        {5509, "Matheus Cunha", true, 3, 30.50},
        {5510, "Neymar Jr.", true, 1, 1.71}};

    /* Variável para armazenar a quantidade de figurinhas */
    int Quantidade_figurinhas = Album.size();

    // MENU
    do
    {
        Quantidade_figurinhas = Album.size(); // Atualiza a quantidade de figurinhas a cada interação do menu principal

        cout << "\nSTICKER´S MARKET FIFA® WORLD CUP 2026" << endl;
        cout << "\n          ..::Menu::..            " << endl;
        cout << "\n1. Cadastrar Figurinha" << endl;
        cout << "2. Listar Figurinhas" << endl;
        cout << "3. Consultar Figurinha" << endl;
        cout << "4. Alterar Cadastro" << endl;
        cout << "5. Entrada de Estoque" << endl;
        cout << "6. Lançamento de Vendas" << endl;
        cout << "7. Inativar/Reativar figurinha" << endl;
        cout << "8. Sair" << endl;
        cout << "Digite um número para acessar uma área: ";
        cin >> menu;

        switch (menu)
        {
        case 1: // Menu Cadastro
        {
            do
            {

                cout << "\n::::::CADASTRO DE FIGURINHAS::::::" << endl
                     << endl;
                cout << "1. Cadastrar nova figurinha\n2. Voltar ao menu principal\n"
                     << endl;
                cout << "Digite um número: ";
                cin >> menu_cadastro;

                if (menu_cadastro == 1) // Cadastrar nova figurinha
                {
                    Figurinha novaFigurinha; // Figurinha temporária

                    do
                    {
                        duplicidade = false;
                        cout << "\nDigite o código da figurinha: ";
                        cin >> novaFigurinha.codigo;

                        // Verificação de duplicidade
                        for (int i = 0; i < Quantidade_figurinhas; i++)
                        {
                            if (Album[i].codigo == novaFigurinha.codigo)
                            {
                                cout << "\nCódigo já cadastrado, tente novamente\n";
                                duplicidade = true;
                                break;
                            }
                        }
                    } while (duplicidade == true);

                    // Lendo o restante das informações necessárias para o cadastro
                    cout << "Digite o nome do jogador/figurinha: ";
                    cin.ignore();                     // Limpa o buffer do teclado
                    getline(cin, novaFigurinha.nome); // Lê o nome completo, incluindo espaços

                    cout << "Digite o valor da figurinha: ";
                    cin >> novaFigurinha.valor;
                    do
                    {
                        cout << "Digite a quantidade em estoque: ";
                        cin >> novaFigurinha.estoque;
                        if (novaFigurinha.estoque == 0)
                        {
                            novaFigurinha.ativo = false;
                        }
                        if (novaFigurinha.estoque > 0)
                        {
                            novaFigurinha.ativo = true;
                        }
                        if (novaFigurinha.estoque < 0)
                        {
                            cout << "\nEstoque inválido, não pode ser negativo.\n\nPor favor, insira um valor inteiro maior que zero.\n";
                        }
                    } while (novaFigurinha.estoque < 0);

                    cout << "Confirmar cadastro? (1 - Sim / 2 - Não): ";
                    int confirmacao;
                    cin >> confirmacao;
                    if (confirmacao == 1)
                    {
                        // Insere de forma segura no fim do vetor
                        Album.push_back(novaFigurinha);
                        cout << "\n* Figurinha cadastrada com sucesso! *" << endl;
                        cout << "            ?\\(^o^)/?" << endl;
                        Quantidade_figurinhas = Album.size(); // Atualiza a quantidade de figurinhas após o cadastro
                    }
                    else // Cancelamento do cadastro, retornando ao menu principal
                    {
                        cout << "\nCadastro cancelado, retornando ao menu\n";
                        cout << "__________________________________________________________" << endl;
                    }
                    continue; // Retorna ao início do loop para permitir novo cadastro ou voltar ao menu
                }
                if (menu_cadastro != 1 && menu_cadastro != 2) // Opção inválida
                {
                    cout << "\nOpção inválida, retornando ao menu" << endl;
                    cout << "__________________________________________________________" << endl;
                    continue;
                }
            } while (menu_cadastro != 2);
            cout << "Voltando ao menu principal..." << endl;
            cout << "__________________________________________________________" << endl;
            break;
        }

        case 2: //Menu listagem
            do
            {
                cout << "\n::::::LISTAGEM DE FIGURINHAS::::::" << endl;
                cout << "1. Listar figurinhas ativas\n2. Listar figurinhas inativas\n3. Listar todas as figurinhas\n4. Voltar ao menu principal\nDigite um número: ";
                cin >> menu_listagem;

                switch (menu_listagem)
                {
                case 1: // Listar figurinhas ativas
                {
                    if (Quantidade_figurinhas == 0) // Se não houver figurinhas cadastradas
                    {
                        cout << "\nNão existem figurinhas cadastradas\n";
                        cout << "__________________________________________________________" << endl;
                    }
                    else // Listar apenas as figurinhas ativas
                    {
                        for (int i = 0; i < Quantidade_figurinhas; i++)
                        {
                            if (Album[i].ativo == true)
                            {
                                cout << "\nFigurinha " << i + 1;
                                cout << "\nStatus figurinha: Ativa";
                                cout << "\nCódigo: " << Album[i].codigo;
                                cout << "\nNome: " << Album[i].nome;
                                cout << "\nEstoque: " << Album[i].estoque;
                                cout << "\nValor: R$ " << Album[i].valor << endl;
                            }
                        }

                        bool nenhumaAtiva = true;
                        for (int j = 0; j < Quantidade_figurinhas; j++)
                        {
                            if (Album[j].ativo == true)
                            {
                                nenhumaAtiva = false;
                                break;
                            }
                        }
                        if (nenhumaAtiva)
                        {
                            cout << "\nNão existem figurinhas ativas\n";
                            cout << "__________________________________________________________" << endl;
                        }
                    }
                    break;
                }

                case 2: // Listar figurinhas inativas
                {
                    if (Quantidade_figurinhas == 0)
                    {
                        cout << "\nNão existem figurinhas cadastradas\n";
                        cout << "__________________________________________________________" << endl;
                    }
                    else
                    {
                        for (int i = 0; i < Quantidade_figurinhas; i++)
                        {
                            if (Album[i].ativo == false)
                            {
                                cout << "\nFigurinha " << i + 1;
                                cout << "\nStatus figurinha: Inativa";
                                cout << "\nCódigo: " << Album[i].codigo;
                                cout << "\nNome: " << Album[i].nome;
                                cout << "\nEstoque: " << Album[i].estoque;
                                cout << "\nValor: R$ " << Album[i].valor << endl;
                            }
                        }

                        bool nenhumaInativa = true;
                        for (int j = 0; j < Quantidade_figurinhas; j++)
                        {
                            if (Album[j].ativo == false)
                            {
                                nenhumaInativa = false;
                                break;
                            }
                        }
                        if (nenhumaInativa)
                        {
                            cout << "\nNão existem figurinhas inativas\n";
                            cout << "__________________________________________________________" << endl;
                        }
                    }
                    break;
                }

                case 3: // Listar todas as figurinhas
                {
                    if (Quantidade_figurinhas == 0)
                    {
                        cout << "\nNão existem figurinhas cadastradas\n";
                        cout << "__________________________________________________________" << endl;
                    }
                    else
                    {
                        cout << "\n:::::::Lista de todas as figurinhas::::::: \n";
                        cout << "Quantidade total de figurinhas: " << Quantidade_figurinhas << endl;

                        for (int i = 0; i < Quantidade_figurinhas; i++)
                        {
                            cout << "\nFigurinha " << i + 1;
                            cout << "\nStatus figurinha: " << (Album[i].ativo ? "Ativa" : "Inativa");
                            cout << "\nCódigo: " << Album[i].codigo;
                            cout << "\nNome: " << Album[i].nome;
                            cout << "\nEstoque: " << Album[i].estoque;
                            cout << "\nValor: R$ " << Album[i].valor << endl;
                        }
                        cout << "__________________________________________________________" << endl;
                    }
                    break;
                }

                case 4: // Voltar ao menu principal
                {
                    continue; // Sai do loop do submenu de listagem e retorna ao menu principal
                }

                default: // Opção inválida
                {
                    cout << "\nOpção inválida, retornando ao menu de listagem\n";
                    cout << "__________________________________________________________" << endl;
                    break;
                }
                }

            } while (menu_listagem != 4);

            cout << "Voltando ao menu principal..." << endl;
            cout << "__________________________________________________________" << endl;
            break;

        case 3: // Menu consulta
        {
            do
            {
                cout << "\n::::::CONSULTAR FIGURINHAS::::::" << endl
                     << endl;
                cout << "\n1. Consultar por código\n2. Consultar por nome\n3. Voltar ao menu principal\n"
                     << endl;
                cout << "Digite um número: ";
                cin >> menu_consulta;
                if (menu_consulta == 1) // Consulta por código
                {
                    int buscaCodigo;         // Variável para armazenar o código da figurinha a ser buscada
                    bool encontrada = false; // Variável para indicar se a figurinha foi encontrada ou não

                    cout << "Digite o código da figurinha: ";
                    cin >> buscaCodigo;

                    for (int i = 0; i < Quantidade_figurinhas; i++) // Loop para encontrar a figurinha com o código buscado
                    {
                        if (Album[i].codigo == buscaCodigo)
                        {
                            if (Album[i].ativo == true)
                            {
                                cout << "\nStatus figurinha: Ativa";
                            }
                            else
                            {
                                cout << "\nStatus figurinha: Inativa";
                            }
                            cout << "\nCódigo: " << Album[i].codigo;
                            cout << "\nNome: " << Album[i].nome;
                            cout << "\nEstoque: " << Album[i].estoque;
                            cout << "\nValor: R$ " << Album[i].valor << endl;

                            encontrada = true;
                            break;
                        }
                    }
                    if (!encontrada)
                    {
                        cout << "\nFigurinha não encontrada\n";
                        cout << "__________________________________________________________" << endl;
                    }
                }
                else if (menu_consulta == 2) // Consulta por nome
                {
                    string buscaNome;
                    bool encontrada = false;

                    cout << "Digite o nome da figurinha: ";
                    cin.ignore();            // Limpa o buffer do teclado antes de ler a string
                    getline(cin, buscaNome); // Lê o nome completo, incluindo espaços

                    for (int i = 0; i < Quantidade_figurinhas; i++) // Loop para encontrar a figurinha com o nome buscado
                    {
                        if (Album[i].nome == buscaNome)
                        {
                            if (Album[i].ativo == true)
                            {
                                cout << "\nStatus figurinha: Ativa";
                            }
                            else
                            {
                                cout << "\nStatus figurinha: Inativa";
                            }
                            cout << "\nCódigo: " << Album[i].codigo;
                            cout << "\nNome: " << Album[i].nome;
                            cout << "\nEstoque: " << Album[i].estoque;
                            cout << "\nValor: R$ " << Album[i].valor << endl;

                            encontrada = true;
                            break;
                        }
                    }
                    if (!encontrada)
                    {
                        cout << "\nFigurinha não encontrada\n";
                        cout << "__________________________________________________________" << endl;
                    }
                }
                else if (menu_consulta != 3 && menu_consulta != 1 && menu_consulta != 2) // Opção inválida
                {
                    cout << "\nOpção inválida, retornando ao menu\n";
                    cout << "__________________________________________________________" << endl;
                    continue; // Retorna ao início do loop para permitir nova consulta ou voltar ao menu
                }
            } while (menu_consulta != 3);
            break;
        }

        case 4: // Menu alterações
        {
            do
            {

                cout << "\n::::::ALTERAR CADASTRO DE FIGURINHAS::::::" << endl
                     << endl;
                cout << "1. Alterar uma figurinha\n2. Voltar ao menu principal\nDigite um número: ";
                cin >> menu_alteracao;

                if (menu_alteracao == 1) // Alterar uma figurinha
                {
                    int codigoAlteracao;     // Variável para armazenar o código da figurinha a ser alterada
                    bool encontrada = false; // Variável para indicar se a figurinha foi encontrada ou não

                    cout << "\nDigite o código da figurinha que deseja alterar: ";
                    cin >> codigoAlteracao;

                    for (int i = 0; i < Quantidade_figurinhas; i++) // Loop para encontrar a figurinha a ser alterada
                    {
                        if (Album[i].codigo == codigoAlteracao) // Encontrou a figurinha a ser alterada
                        {
                            encontrada = true;  // Marca que a figurinha foi encontrada para evitar mensagens de erro após o loop
                            int campoAlteracao; // Variável para navegação do submenu de campos a serem alterados
                            cout << "\nFigurinha encontrada!!" << endl;
                            int alterarOutroCampo; // Variável para decidir se deseja alterar outro campo da figurinha
                            do
                            {

                                cout << " O que deseja alterar?\n1. Código\n2. Nome\n3. Valor\n4. Estoque\nDigite um número: ";
                                cin >> campoAlteracao;

                                switch (campoAlteracao) // Submenu para escolher qual campo da figurinha será alterado
                                {
                                case 1: // Alterar código
                                    do
                                    {
                                        duplicidade = false;
                                        cout << "\nCódigo atual: " << Album[i].codigo << endl;
                                        cout << "Digite o novo código: ";
                                        int codigoNovo;
                                        cin >> codigoNovo;
                                        for (int i = 0; i < Quantidade_figurinhas; i++)
                                        {
                                            if (Album[i].codigo == codigoNovo)
                                            {
                                                cout << "\nCódigo já cadastrado, tente novamente\n";
                                                duplicidade = true;
                                                break;
                                            }
                                        }
                                    } while (duplicidade);

                                    cout << "\nCódigo alterado com sucesso!\n";
                                    cout << "__________________________________________________________" << endl;
                                    cout << "\nDeseja alterar outro campo? (1 - Sim / 2 - Não): ";
                                    cin >> alterarOutroCampo;
                                    if (alterarOutroCampo == 1)
                                    {
                                        continue; // Retorna ao início do loop para permitir nova alteração de campo
                                    }
                                    else
                                    {
                                        break; // Sai do loop do submenu de campos a serem alterados e retorna ao menu principal
                                    }
                                    break;
                                case 2: // Alterar nome
                                    cout << "\nNome atual: " << Album[i].nome << endl;
                                    cout << "Digite o novo nome: ";
                                    cin.ignore();
                                    getline(cin, Album[i].nome);
                                    cout << "\nNome alterado com sucesso!\n";
                                    cout << "__________________________________________________________" << endl;
                                    cout << "\nDeseja alterar outro campo? (1 - Sim / 2 - Não): ";
                                    cin >> alterarOutroCampo;
                                    if (alterarOutroCampo == 1)
                                    {
                                        continue; // Retorna ao início do loop para permitir nova alteração de campo
                                    }
                                    else
                                    {
                                        break; // Sai do loop do submenu de campos a serem alterados e retorna ao menu principal
                                    }
                                    break;
                                case 3: // Alterar valor
                                    cout << "\nValor atual: R$ " << Album[i].valor << endl;
                                    cout << "Digite o novo valor: R$ ";
                                    cin >> Album[i].valor;
                                    cout << "\nValor alterado com sucesso!\n";
                                    cout << "__________________________________________________________" << endl;
                                    cout << "\nDeseja alterar outro campo? (1 - Sim / 2 - Não): ";
                                    cin >> alterarOutroCampo;
                                    if (alterarOutroCampo == 1)
                                    {
                                        continue; // Retorna ao início do loop para permitir nova alteração de campo
                                    }
                                    else
                                    {
                                        break; // Sai do loop do submenu de campos a serem alterados e retorna ao menu principal
                                    }
                                    break;
                                case 4:              // Alterar estoque
                                    int novoEstoque; // Variável temporária para armazenar o novo valor de estoque
                                    do
                                    {
                                        cout << "\nEstoque atual: " << Album[i].estoque << endl;
                                        cout << "Digite o novo estoque: ";
                                        cin >> novoEstoque;
                                        if (novoEstoque > 0)
                                        { // Se o estoque for maior que zero, reativa a figurinha
                                            cout << "\nEstoque alterado com sucesso!\n";
                                            Album[i].ativo = true;          // Reativa a figurinha se o estoque for maior que zero
                                            Album[i].estoque = novoEstoque; // Atualiza o estoque com o novo valor
                                        }
                                        else if (novoEstoque == 0)
                                        { // Se o estoque for zero, inativa a figurinha
                                            cout << "\nEstoque zerado, figurinha inativada.\n";
                                            Album[i].ativo = false; // Inativa a figurinha se o estoque for zero
                                            Album[i].estoque = 0;   // Reseta o estoque para zero
                                        }
                                        if (novoEstoque < 0)
                                        { // Se o estoque for negativo, exibe mensagem de erro e inativa a figurinha
                                            cout << "\nEstoque inválido, não pode ser negativo.\n\nPor favor, insira um valor inteiro maior que zero.\n";
                                            Album[i].ativo = false; // Inativa a figurinha se o estoque for negativo
                                        }
                                    } while (novoEstoque < 0); // Repete a solicitação se o estoque for negativo
                                    cout << "__________________________________________________________" << endl;
                                    cout << "\nDeseja alterar outro campo? (1 - Sim / 2 - Não): ";
                                    cin >> alterarOutroCampo;
                                    if (alterarOutroCampo == 1)
                                    {
                                        continue; // Retorna ao início do loop para permitir nova alteração de campo
                                    }
                                    else
                                    {
                                        break; // Sai do loop do submenu de campos a serem alterados e retorna ao menu principal
                                    }
                                    break;
                                default: // Opção inválida no submenu de campos a serem alterados
                                    cout << "\nOpção inválida, retornando ao menu principal\n";
                                    cout << "__________________________________________________________" << endl;
                                    break;
                                }
                            } while (alterarOutroCampo == 1);
                            break;
                        }
                    }

                    if (!encontrada) // Se a figurinha não for encontrada após o loop
                    {
                        cout << "\nFigurinha não encontrada\n";
                        cout << " Retornando ao menu principal, consulte códigos em 2. Listar.\n";
                        cout << "__________________________________________________________" << endl;
                    }
                }
                else if (menu_alteracao != 2 && menu_alteracao != 1) // Opção inválida no submenu de alteração
                {
                    cout << "\nOpção inválida, retornando ao menu\n";
                    cout << "__________________________________________________________" << endl;
                    continue; // Retorna ao início do loop para permitir nova alteração ou voltar ao menu
                }
            } while (menu_alteracao != 2);
            break;
        }

        case 5: // Menu entrada estoque
        {
            // Implementação da navegação em menu para a entrada de estoque
            do
            {
                cout << "\n::::::ENTRADA DE ESTOQUE::::::" << endl
                     << endl;
                cout << "1. Dar entrada no estoque\n2. Voltar ao menu principal\nDigite um número: ";
                cin >> menu_entrada;

                if (menu_entrada == 1)
                {
                    int codigoEntrada;
                    int quantidadeEntrada;
                    int confirmacao;
                    int novoEstoque;
                    bool encontrada = false;
                    bool estavaInativa = false;

                    // Verifica se existem figurinhas cadastradas
                    if (Quantidade_figurinhas == 0)
                    {
                        cout << "\nNão existem figurinhas cadastradas\n";
                        cout << "__________________________________________________________" << endl;
                        continue; // Utiliza 'continue' em vez de 'break' para não sair do submenu
                    }

                    cout << "\nDigite o código da figurinha: ";
                    cin >> codigoEntrada;

                    for (int i = 0; i < Quantidade_figurinhas; i++)
                    {
                        // Procura a figurinha
                        if (Album[i].codigo == codigoEntrada)
                        {
                            encontrada = true;

                            // Guarda se estava inativa antes da alteração
                            if (Album[i].ativo == false)
                            {
                                estavaInativa = true;
                            }

                            cout << "\nFigurinha encontrada!!" << endl;
                            cout << "Nome: " << Album[i].nome << endl;
                            cout << "Estoque atual: " << Album[i].estoque << endl;
                            cout << "Status atual: "
                                 << (Album[i].ativo ? "Ativa" : "Inativa")
                                 << endl;

                            cout << "\nDigite a quantidade para entrada no estoque: ";
                            cin >> quantidadeEntrada;

                            // Validação da quantidade
                            if (quantidadeEntrada <= 0)
                            {
                                cout << "\nQuantidade inválida, operação cancelada\n";
                                cout << "__________________________________________________________" << endl;
                                break;
                            }

                            // Simulação antes de alterar
                            novoEstoque = Album[i].estoque + quantidadeEntrada;

                            cout << "\n:::::::: RESUMO DA OPERAÇÃO ::::::::" << endl;
                            cout << "Estoque anterior: " << Album[i].estoque << endl;
                            cout << "Quantidade adicionada: " << quantidadeEntrada << endl;
                            cout << "Novo estoque: " << novoEstoque << endl;

                            cout << "\nConfirmar entrada de estoque? (1 - Sim / 2 - Não): ";
                            cin >> confirmacao;

                            if (confirmacao == 1)
                            {
                                // Faz a alteração real
                                Album[i].estoque = novoEstoque;

                                // Reativa automaticamente se voltou a ter estoque
                                if (Album[i].estoque > 0)
                                {
                                    Album[i].ativo = true;
                                }

                                cout << "\nEntrada de estoque realizada com sucesso!\n";

                                // Aviso especial se foi reativada
                                if (estavaInativa)
                                {
                                    cout << "Cadastro reativado automaticamente devido à entrada de estoque.\n";
                                }

                                cout << "__________________________________________________________" << endl;
                            }
                            else
                            {
                                cout << "\nOperação cancelada, nenhuma alteração foi feita.\n";
                                cout << "__________________________________________________________" << endl;
                            }

                            break; // Encontrou a figurinha, não precisa continuar o loop de busca
                        }
                    }

                    // Caso não encontre a figurinha
                    if (!encontrada)
                    {
                        cout << "\nFigurinha não encontrada\n";
                        cout << "Retornando ao menu, consulte códigos em 2. Listar.\n";
                        cout << "__________________________________________________________" << endl;
                    }
                }
                else if (menu_entrada != 2) // Tratativa para opções inválidas
                {
                    cout << "\nOpção inválida, retornando ao menu de entrada de estoque\n";
                    cout << "__________________________________________________________" << endl;
                }

            } while (menu_entrada != 2);

            cout << "Voltando ao menu principal..." << endl;
            cout << "__________________________________________________________" << endl;
            break;
        }

        case 6: // Menu saida | venda
        {
            // Implementação da navegação em menu para Lançamento de Vendas
            do
            {
                cout << "\n:::::::::: LANÇAMENTO DE VENDAS ::::::::::" << endl
                     << endl;
                cout << "1. Realizar nova venda\n2. Voltar ao menu principal\nDigite um número: ";
                cin >> menu_venda;

                if (menu_venda == 1)
                {
                    vector<int> indiceCarrinho;
                    vector<int> quantidadeCarrinho;

                    int codigoVenda;
                    int quantidadeVenda;
                    int adicionarMais;
                    int confirmacao;
                    bool encontrada;
                    double totalGeral = 0;

                    if (Quantidade_figurinhas == 0)
                    {
                        cout << "\nNão existem figurinhas cadastradas.\n";
                        cout << "__________________________________________________________" << endl;
                        continue; // 'continue' para voltar ao submenu em caso de erro
                    }

                    // adicionar produtos no carrinho
                    do
                    {
                        encontrada = false;

                        cout << "\nDigite o código da figurinha: ";
                        cin >> codigoVenda;

                        for (int i = 0; i < Quantidade_figurinhas; i++)
                        {
                            if (Album[i].codigo == codigoVenda)
                            {
                                encontrada = true;

                                // bloqueia venda se estiver inativa
                                if (Album[i].ativo == false)
                                {
                                    cout << "\nVenda bloqueada." << endl;
                                    cout << "Esta figurinha está INATIVA." << endl;
                                    break; // Interrompe o laço de procura
                                }

                                // mostra dados
                                cout << "\nFigurinha encontrada!" << endl;
                                cout << "Nome: " << Album[i].nome << endl;
                                cout << "Código: " << Album[i].codigo << endl;
                                cout << "Estoque atual: " << Album[i].estoque << endl;
                                cout << "Valor unitário: R$ " << Album[i].valor << endl;
                                cout << "Status: Ativa" << endl;

                                cout << "\nDigite a quantidade desejada: ";
                                cin >> quantidadeVenda;

                                // valida quantidade
                                if (quantidadeVenda <= 0)
                                {
                                    cout << "\nQuantidade inválida." << endl;
                                    break;
                                }

                                // verifica estoque
                                if (quantidadeVenda > Album[i].estoque)
                                {
                                    cout << "\nEstoque insuficiente." << endl;
                                    cout << "Disponível: " << Album[i].estoque << endl;
                                    break;
                                }

                                // adiciona ao carrinho
                                indiceCarrinho.push_back(i);
                                quantidadeCarrinho.push_back(quantidadeVenda);

                                cout << "\nItem adicionado ao carrinho com sucesso!" << endl;
                                break;
                            }
                        }

                        if (!encontrada)
                        {
                            cout << "\nFigurinha não encontrada." << endl;
                        }

                        cout << "\nDeseja adicionar mais itens?" << endl;
                        cout << "1 - Sim" << endl;
                        cout << "2 - Não" << endl;
                        cout << "Digite: ";
                        cin >> adicionarMais;

                    } while (adicionarMais == 1);

                    // carrinho vazio
                    if (indiceCarrinho.size() == 0)
                    {
                        cout << "\nNenhuma venda realizada." << endl;
                        cout << "__________________________________________________________" << endl;
                        continue; // Retorna ao submenu de vendas
                    }

                    // mostra carrinho
                    cout << "\n===================================" << endl;
                    cout << "            CARRINHO              " << endl;
                    cout << "===================================" << endl;

                    for (size_t j = 0; j < indiceCarrinho.size(); j++) // Utilizando size_t para compatibilidade de tipagem em arrays
                    {
                        int indice = indiceCarrinho[j];

                        double subtotal =
                            quantidadeCarrinho[j] * Album[indice].valor;

                        cout << "\nItem " << j + 1 << endl;
                        cout << "Nome: " << Album[indice].nome << endl;
                        cout << "Quantidade: " << quantidadeCarrinho[j] << endl;
                        cout << "Valor unitário: R$ "
                             << Album[indice].valor << endl;
                        cout << "Subtotal: R$ "
                             << subtotal << endl;

                        cout << "-----------------------------------" << endl;

                        totalGeral = totalGeral + subtotal;
                    }

                    cout << "\nTOTAL DA COMPRA: R$ " << totalGeral << endl;

                    cout << "===================================" << endl;

                    // confirmação
                    cout << "\nConfirmar venda?" << endl;
                    cout << "1 - Sim" << endl;
                    cout << "2 - Não" << endl;
                    cout << "Digite: ";
                    cin >> confirmacao;

                    if (confirmacao == 1)
                    {
                        // desconta estoque
                        for (size_t j = 0; j < indiceCarrinho.size(); j++)
                        {
                            int indice = indiceCarrinho[j];

                            Album[indice].estoque =
                                Album[indice].estoque - quantidadeCarrinho[j];

                            // inativa automaticamente se zerar
                            if (Album[indice].estoque == 0)
                            {
                                Album[indice].ativo = false;
                            }
                        }

                        // comprovante
                        cout << "\n===================================" << endl;
                        cout << "         COMPROVANTE FINAL         " << endl;
                        cout << "===================================" << endl;

                        for (size_t j = 0; j < indiceCarrinho.size(); j++)
                        {
                            int indice = indiceCarrinho[j];

                            double subtotal =
                                quantidadeCarrinho[j] * Album[indice].valor;

                            cout << "\nProduto: "
                                 << Album[indice].nome << endl;

                            cout << "Quantidade vendida: "
                                 << quantidadeCarrinho[j] << endl;

                            cout << "Valor unitário: R$ "
                                 << Album[indice].valor << endl;

                            cout << "Valor item: R$ "
                                 << subtotal << endl;

                            cout << "-----------------------------------" << endl;
                        }

                        cout << "\nVALOR TOTAL PAGO: R$ "
                             << totalGeral << endl;

                        cout << "===================================" << endl;
                    }
                    else
                    {
                        cout << "\nVenda cancelada." << endl;
                        cout << "Nenhuma alteração foi feita." << endl;
                    }
                }
                else if (menu_venda != 2) // Opção inválida
                {
                    cout << "\nOpção inválida, retornando ao menu\n";
                    cout << "__________________________________________________________" << endl;
                }

            } while (menu_venda != 2);

            cout << "Voltando ao menu principal..." << endl;
            cout << "__________________________________________________________" << endl;
            break;
        }

        case 7: // Menu inativação | ativação
        {
            do
            {
                cout << "\n::::::INATIVAR FIGURINHA::::::" << endl
                     << endl;
                cout << "1. Inativar uma figurinha\n2. Reativar uma figurinha\n3. Voltar ao menu principal\nDigite um número: ";
                cin >> menu_inativacao;

                switch (menu_inativacao)
                {
                case 1: // Inativar uma figurinha
                {
                    int codigoInativacao;    // Variável para armazenar o código da figurinha a ser inativada
                    bool encontrada = false; // Variável para indicar se a figurinha foi encontrada ou não

                    cout << "\nDigite o código da figurinha que deseja inativar: ";
                    cin >> codigoInativacao;

                    for (int i = 0; i < Quantidade_figurinhas; i++) // Loop para encontrar a figurinha a ser inativada
                    {
                        if (Album[i].codigo == codigoInativacao) // Encontrou a figurinha a ser inativada
                        {
                            encontrada = true; // Marca que a figurinha foi encontrada para evitar mensagens de erro após o loop
                            cout << "\nFigurinha encontrada!!" << endl;
                            cout << "Nome: " << Album[i].nome << endl;
                            cout << "Valor: R$ " << Album[i].valor << endl;
                            cout << "Estoque: " << Album[i].estoque << endl;
                            cout << "Status atual: " << (Album[i].ativo ? "Ativa" : "Inativa") << endl; // mostra o status atual da figurinha antes de confirmar a inativação, mostrando a string "Ativa" ou "Inativa" de acordo com o valor do campo ativo da figurinha
                            do
                            {
                                cout << "Confirmar inativação? (1 - Sim / 2 - Não): ";
                                cin >> confirmacaoInativacao;
                                if (confirmacaoInativacao == 1)
                                {
                                    encontrada = true;      // Marca que a figurinha foi encontrada
                                    Album[i].ativo = false; // Inativa a figurinha alterando seu status para falso
                                    cout << "\nFigurinha inativada com sucesso!\n";
                                }
                                if (confirmacaoInativacao == 2)
                                {
                                    cout << "\nInativação cancelada, retornando ao menu\n"; // Caso o usuário não confirme a inativação, exibe mensagem de cancelamento e retorna ao menu
                                }
                                if (confirmacaoInativacao != 1 && confirmacaoInativacao != 2)
                                {
                                    cout << "\nOpção inválida, digite novamente\n"; // Caso o usuário digite uma opção inválida, exibe mensagem de erro e retorna ao menu
                                    continue;
                                }
                            } while (confirmacaoInativacao != 1 && confirmacaoInativacao != 2);
                            cout << "__________________________________________________________" << endl;
                            break;
                        }
                    }

                    if (!encontrada) // Se a figurinha não for encontrada após o loop
                    {
                        cout << "\nFigurinha não encontrada\n";
                        cout << " Retornando ao menu, consulte códigos em 2. Listar.\n";
                        cout << "__________________________________________________________" << endl;
                    }
                    break;
                }
                case 2: // Reativar uma figurinha
                {
                    int codigoAtivacao;      // Variável para armazenar o código da figurinha a ser ativada
                    bool encontrada = false; // Variável para indicar se a figurinha foi encontrada ou não

                    cout << "\nDigite o código da figurinha que deseja ativar: ";
                    cin >> codigoAtivacao;

                    for (int i = 0; i < Quantidade_figurinhas; i++) // Loop para encontrar a figurinha a ser ativada
                    {
                        if (Album[i].codigo == codigoAtivacao) // Encontrou a figurinha a ser ativada
                        {
                            encontrada = true; // Marca que a figurinha foi encontrada para evitar mensagens de erro após o loop
                            cout << "\nFigurinha encontrada!!" << endl;
                            cout << "Nome: " << Album[i].nome << endl;
                            cout << "Valor: R$ " << Album[i].valor << endl;
                            cout << "Estoque: " << Album[i].estoque << endl;
                            cout << "Status atual: " << (Album[i].ativo ? "Ativa" : "Inativa") << endl; // mostra o status atual da figurinha antes de confirmar a ativação, mostrando a string "Ativa" ou "Inativa" de acordo com o valor do campo ativo da figurinha
                            do
                            {
                                cout << "Confirmar ativação? (1 - Sim / 2 - Não): ";
                                cin >> confirmacaoAtivacao;
                                if (confirmacaoAtivacao == 1)
                                {
                                    encontrada = true;     // Marca que a figurinha foi encontrada
                                    Album[i].ativo = true; // Ativa a figurinha alterando seu status para true
                                    cout << "\nFigurinha ativada com sucesso!\n";
                                }
                                if (confirmacaoAtivacao == 2)
                                {
                                    cout << "\nAtivação cancelada, retornando ao menu\n"; // Caso o usuário não confirme a ativação, exibe mensagem de cancelamento e retorna ao menu
                                }
                                if (confirmacaoAtivacao != 1 && confirmacaoAtivacao != 2)
                                {
                                    cout << "\nOpção inválida, digite novamente\n"; // Caso o usuário digite uma opção inválida, exibe mensagem de erro e retorna ao menu
                                    continue;
                                }
                            } while (confirmacaoAtivacao != 1 && confirmacaoAtivacao != 2);
                            cout << "__________________________________________________________" << endl;
                            break;
                        }
                    }

                    if (!encontrada) // Se a figurinha não for encontrada após o loop
                    {
                        cout << "\nFigurinha não encontrada\n";
                        cout << " Retornando ao menu, consulte códigos em 2. Listar.\n";
                        cout << "__________________________________________________________" << endl;
                    }
                    break;
                }
                case 3: // Voltar ao menu principal
                {
                    cout << "\nVoltando ao menu principal..." << endl;
                    cout << "__________________________________________________________" << endl;
                    break; // Sai do loop do submenu de inativação e retorna ao menu principal
                }

                default: // Opção inválida | n.a.
                    cout << "Opção inválida, digite novamente\n";
                    cout << "__________________________________________________________" << endl;
                    break;
                }
            } while (menu_inativacao != 3);
            break;
        }
        }
        system("cls"); // Para limpar o painel a cada loop do menu, deixando mais limpo visualmente
    } while (menu != 8);

    cout << "\n============================================================\n";
    cout << "       OBRIGADO POR USAR O STICKER'S MARKET FIFA® 2026!   \n";
    cout << "============================================================\n\n";

    cout << "############################################################\n";
    cout << "##########################  ####  ##########################\n";
    cout << "########################  ########  ########################\n";
    cout << "######################  ############  ######################\n";
    cout << "####################  ################  ####################\n";
    cout << "##################  ######********######  ##################\n";
    cout << "################  ########********########  ################\n";
    cout << "##############  ##########********##########  ##############\n";
    cout << "################  ########********########  ################\n";
    cout << "##################  ######********######  ##################\n";
    cout << "####################  ################  ####################\n";
    cout << "######################  ############  ######################\n";
    cout << "########################  ########  ########################\n";
    cout << "##########################  ####  ##########################\n";
    cout << "############################################################\n\n";

    cout << "                        VAI BRASIL !!!!\n";
    cout << "                              BR\n";
    cout << "__________________________________________________________\n";

    return 0;
}
