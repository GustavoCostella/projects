#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5 //Defina qual é o maximo de clientes e produtos que pode cadastrar

typedef struct _produto
{
    char nome[30], data_fab[12], data_val[12], fornecedor[30];
    int qtd_estoque;
    double val_venda, val_aquisicao;
} Produto;

typedef struct _compra
{
    Produto produtos[20];
    double total;
} Compra;

typedef struct _cartao
{
    int numero;
    Compra compras[20];
    double total_compras;
} Cartao;

typedef struct _cliente
{
    char nome[30], cpf[15], telefone[15], endereco[50];
    int cartao;
} Cliente;

void cadastrar_cliente(int *l, Cliente cliente[])
{
    system("clear");
    char sn;
    int auxCPF, auxTel;
    for(*l; *l < MAX; *l+=1)
    {
        setbuf(stdin,NULL);
        printf("Digite o nome do cliente: ");
        fgets(cliente[*l].nome,30,stdin);
        setbuf(stdin,NULL);
        printf("Digite o cpf do cliente: ");
        fgets(cliente[*l].cpf,15,stdin);
        for(;;)
        {
            auxCPF = strlen(cliente[*l].cpf);
            if(auxCPF != 12)
            {
                printf("CPF nao tem 11 digitos, por favor, digite novamente: ");
                fgets(cliente[*l].cpf,15,stdin);
            }
            else
            {
                break;
            }
        }
        auxCPF = strlen(cliente[*l].cpf);
        cliente[*l].cpf[auxCPF -1] = '\0';
        setbuf(stdin,NULL);
        printf("Digite o telefone do cliente: ");
        fgets(cliente[*l].telefone,15,stdin);
        for(;;)
        {
            auxTel = strlen(cliente[*l].telefone);
            if(auxTel < 11)
            {
                printf("Numero nao tem 11 digitos, por favor, digite novamente: ");
                fgets(cliente[*l].telefone,15,stdin);
            }
            else
            {
                break;
            }
        }
        setbuf(stdin,NULL);
        printf("Digite o endereco do cliente: ");
        fgets(cliente[*l].endereco,50,stdin);
        setbuf(stdin,NULL);
        printf("Desejar cadastrar mais algum cliente? (s)sim  (n)nao\n");
        scanf("%c", &sn);
        getchar();
        if(sn=='n' || sn=='N')
        {
            *l=*l+1;
            break;
        }
        else {}
    }
}

void cadastrar_produto(int *L, Produto produto[])
{
    system("clear");
    double aux2;
    char sn;
    for(*L; *L<MAX; *L+=1)
    {
        setbuf(stdin,NULL);
        printf("Insira o nome do produto:");
        fgets(produto[*L].nome,30,stdin);
        setbuf(stdin,NULL);
        printf("Nome do fornecedor:");
        fgets(produto[*L].fornecedor,30,stdin);
        setbuf(stdin,NULL);
        printf("Insira a data de fabricação do produto:");
        fgets(produto[*L].data_fab,12,stdin);
        setbuf(stdin,NULL);
        printf("Insita a data de validade do produto:");
        fgets(produto[*L].data_val,12,stdin);
        setbuf(stdin,NULL);
        do
        {
            printf("Digite o valor de aquisicao(Maior que 1): ");
            scanf("%lf", &aux2);
        }
        while(aux2<1);
        produto[*L].val_aquisicao=aux2;
        setbuf(stdin,NULL);
        printf("Insira o valor da venda:");
        scanf("%lf",&produto[*L].val_venda);
        setbuf(stdin,NULL);
        printf("Quantos itens existira no estoque?:");
        scanf("%d",&produto[*L].qtd_estoque);
        setbuf(stdin,NULL);
        printf("Desejar cadastrar mais algum produto? (s)sim  (n)nao\n");
        scanf("%c", &sn);
        getchar();
        if(sn=='n' || sn=='N')
        {
            *L=*L+1;
            break;
        }
        else {}
    }
}

void cadastrar_venda(int *l, int *L, Cliente cliente[], Produto produto[])
{

    int i, j, x,z, aux, h, numcart, pagamento, dd,ddd;
    double total=0, quanti=0,troco;
    char busca[30], buscar[15], sn, buscapag[15];
    setbuf(stdin,NULL);
    if(*l==0)
        printf("Nenhum cliente cadastrado :)\n");
    else if(*L==0)
        printf("Nenhum produto cadastrado :)\n");
    else
    {   
        printf("Produtos disponiveis:\n");
        for(j=0; j<*L; j++)
        {   
            for(z=0;z<*L;z++){
            printf("%s\n", produto[z].nome);
            }
            printf("Informe o nome do produto: ");
            setbuf(stdin,NULL);
            fgets(busca,15,stdin);
            for(i=0; i<*L; i++)
            {
                if(strcmp(produto[i].nome,busca)==0)
                {
                    setbuf(stdin,NULL);
                    printf("Unidades atuais: %d\n", produto[i].qtd_estoque);
                    printf("Digite quantas unidades deseja comprar: ");
                    scanf("%d", &x);
                    do
                    {
                        aux = produto[i].qtd_estoque;
                        aux -= x;
                        if(aux<0)
                        {
                            printf("\nQuantidade indisponivel, por favor, escolha até %d unidade(s)\n", produto[i].qtd_estoque);
                            scanf("%d", &x);
                        }
                        else
                            produto[i].qtd_estoque = produto[i].qtd_estoque - x;
                    }
                    while(aux<0);
                    printf("Venda feita com sucesso\n");
                    quanti= x * produto[i].val_venda;
                    total = total + quanti;
                    printf("Total da compra ate o momento: %.2lf\n", total);
                    printf("Deseja comprar mais algum produto?\n");
                    scanf("%c", &sn);
                    getchar();
                    if(sn=='n' || sn=='N')
                        break;
                }
            }
        }
        printf("Qual sera a forma de pagamento?\n 1 - Cartao\n 2 - Dinheiro\n 3 - Cheque\n");
        setbuf(stdin,NULL);
        scanf("%d", &pagamento);
        switch(pagamento)
        {
        case 1:
            printf("Digite o cpf do cliente: \n");
            setbuf(stdin,NULL);
            scanf("%s",buscapag);
            setbuf(stdin,NULL);
            for(h = 0; h < *l; h++)
            {
                if(strcmp(cliente[h].cpf, buscapag)==0)
                {
                    printf("Digite o numero do cpf: ");
                    setbuf(stdin,NULL);
                    scanf("%s",cliente[*l].cpf);
                    printf("Compra realizada com sucesso!\n");
                }
                else
                    printf("cpf invalido");
            }
            printf("Digite enter para sair");
            getchar();
            break;
        case 2:
            printf("Total em dinheiro %.2f\n", total);
            printf("Dinheiro do cliente : ");
            scanf("%d",&dd);
            setbuf(stdin,NULL);
            troco=dd-total;
            printf("Troco : %.2lf\n",troco);
            printf("Digite enter para sair");
            getchar();
            break;
        case 3:
            printf("Total em dinheiro %.2f\n", total);
            printf("Digite o numero do cheque: ");
            scanf("%d",&ddd);
            setbuf(stdin,NULL);
            printf("Venda efetuada com sucesso\n");
            printf("Digite enter para sair");
            getchar();
            break;
        default:
            printf("Opcao inválida\n\n");
            break;
        }
    }
}

void buscar_cliente(int *l, Cliente cliente[])
{
    int i,a;
    char buscar[12];
    setbuf(stdin,NULL);
    if(*l==0)
        printf("Nenhum cliente cadastrado :)\n");
    else
    {
        printf("Digite o cpf do cliente para buscar: ");
        scanf("%s", buscar);
        for(i=0; i < *l; i++)
        {
            if(strcmp(cliente[i].cpf, buscar)==0)
            {
                printf("Nome:%sTelefone:%sEndereco:%s", cliente[i].nome, cliente[i].telefone, cliente[i].endereco);
                a++;
            }
        }
        if(a==0)
            printf("CPF não encontrado\n");
    }
    printf("Pressione enter para sair");
    setbuf(stdin,NULL);
    getchar();
}


void listar_prod_fornecedor(int *L, Produto produto[])
{
    system("clear");
    char busca[50];
    int i;
    setbuf(stdin,NULL);
    if(*L==0)
        printf("Nenhum produto cadastrado :)\n");
    else
    {
        printf("Digite o fornecedor desejado:\n");
        fgets(busca,50,stdin);
        for (i=0; i<*L; i++)
        {
            if(strcmp(produto[i].fornecedor,busca)==0)
                printf("Nome: %sData Fabricacao: %sData Validade: %sValor Compra: %.2lf\nValor Venda: %.2lf\nQuantidade: %d\n\n",produto[i].nome,produto[i].data_fab,produto[i].data_val,produto[i].val_aquisicao,produto[i].val_venda,produto[i].qtd_estoque);
        }
    }
    printf("Pressione enter para sair");
    setbuf(stdin,NULL);
    getchar();
}

void listar_prod_baixa(int *L, Produto produto[])
{
    system("clear");
    int i;
    if(*L==0)
        printf("Nenhum produto cadastrado :)\n");
    else
    {
        for (i=0; i<*L; i++)
        {
            if(produto[i].qtd_estoque < 10)
                printf("%s com %d produtos\n",produto[i].nome, produto[i].qtd_estoque);
            else
                printf("\nNenhum produto em baixa no estoque :)\n");
        }
    }
    printf("Pressione enter para sair");
    setbuf(stdin,NULL);
    getchar();

}

void listar_clientes(int *l, Cliente cliente[])
{
    system("clear");
    int a;
    if(*l==0)
        printf("Nenhum cliente cadastrado :)\n");
    else
    {
        for(a=0; a<*l; a++)
        {
            printf("%s\n",cliente[a].nome);
        }
    }
    setbuf(stdin,NULL);
    printf("Pressione enter para sair");
    getchar();
}

void buscar_produto(int *L, Produto produto[])
{
    int i;
    char busca[50];
    setbuf(stdin,NULL);
    if(*L==0)
        printf("Nenhum produto cadastrado :)\n");
    else
    {
        printf("Digite o nome do produto para buscar: ");
        fgets(busca,50,stdin);
        for(i=0; i<*L; i++)
        {
            if(strcmp(produto[i].nome,busca)==0)
            {
                printf("Nome: %sData Fabricacao: %sData Validade: %sValor Compra: %.2lf\nValor Venda: %.2lf\nQuantidade: %d\n",produto[i].nome,produto[i].data_fab,produto[i].data_val,produto[i].val_aquisicao,produto[i].val_venda,produto[i].qtd_estoque);
            }
        }
    }
    printf("Pressione enter para sair");
    setbuf(stdin,NULL);
    getchar();
}

void adicionar_prod_estoque(int *L, Produto produto[])
{
    char busca[50];
    int i, add;
    setbuf(stdin,NULL);
    if(*L==0)
        printf("Nenhum produto cadastrado :)\n");
    else
    {
        printf("Digite o nome do produto para adicionar ao estoque:\n");
        fgets(busca,50,stdin);
        for (i=0; i<*L; i++)
        {
            if(strcmp(produto[i].nome,busca)==0)
            {
                printf("Unidades atuais: %d\n", produto[i].qtd_estoque);
                printf("Deseja adicionar quantas unidades?\n");
                scanf("%d", &add);
                produto[i].qtd_estoque = produto[i].qtd_estoque + add;
                break;
            }
            else
            {
                printf("Produto nao encontrado\n");
                break;
               }
        }
    }
    printf("Pressione enter para sair");
    setbuf(stdin,NULL);
    getchar();
}

int main()
{
    system("clear");
    int opcao;
    int l=0; //Contador de clientes
    int L=0; //Contador de produtos
    Produto produto[MAX];
    Cliente cliente[MAX];

    do
    {
        system("clear");
        system("clear");
        printf("\tMenu de Opções:\n");
        printf("1 - Cadastrar clientes, produtos ou venda:\n");
        printf("2 - Buscar cliente:\n");
        printf("3 - Buscar produto:\n");
        printf("4 - Adicionar produto no estoque:\n");
        printf("5 - Listar produtos:\n");
        printf("6 - Listar clientes:\n");
        printf("0 - Sair do sistema:\n");
        printf("\n--> ");
        scanf("%d", &opcao);
        printf("\n");
        switch(opcao)
        {
        case 1:
            do
            {
                system("clear");
                printf("\tSubmenu de cadastro\n");
                printf("1 - Cadastrar cliente:\n");
                printf("2 - Cadastrar produto:\n");
                printf("3 - Cadastrar venda:\n");
                printf("0 - Voltar ao menu anterior\n");
                printf("\n--> ");
                scanf("%d", &opcao);
                printf("\n");
                switch(opcao)
                {
                case 1:
                    cadastrar_cliente(&l, cliente);
                    opcao = 0;
                    break;
                case 2:
                    cadastrar_produto(&L, produto);
                    opcao = 0;
                    break;
                case 3:
                    cadastrar_venda(&l,&L, cliente, produto);
                    opcao = 0;
                    break;
                case 0:
                    break;
                default:
                    printf("Opcao inválida\n\n");
                    break;
                }
            }
            while(opcao != 0);
            opcao = 1;
            break;
        case 2:
            system("clear");
            buscar_cliente(&l, cliente);
            break;
        case 3:
            system("clear");
            buscar_produto(&L, produto);
            break;
        case 4:
            system("clear");
            adicionar_prod_estoque(&L, produto);
            break;
        case 5:
            do
            {
                system("clear");
                printf("\tSubmenu de produtos\n");
                printf("1 - Listar produtos por fornecedor:\n");
                printf("2 - Listar produtos em baixa no estoque:\n");
                printf("0 - Voltar ao menu anterior\n");
                printf("\n--> ");
                scanf("%d", &opcao);
                printf("\n");
                switch(opcao)
                {
                case 1:
                    listar_prod_fornecedor(&L, produto);
                    opcao = 0;
                    break;
                case 2:
                    listar_prod_baixa(&L, produto);
                    opcao = 0;
                    break;
                case 0:
                    break;
                default:
                    printf("Opcao inválida\n\n");
                    break;
                }

            }
            while(opcao != 0);
            opcao = 5;
            break;
        case 6:
            listar_clientes(&l, cliente);
            break;
        case 0:
            break;
        default:
            printf("Opção inválida\n\n");
        }
    }
    while(opcao != 0);

    return 0;
}