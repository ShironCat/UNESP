#include <iostream>

typedef struct ELEMENTO {
    std::string codigo, nome;
    float preco;
    int quantidade;
    struct ELEMENTO *proximo;
} lista;

lista *listaInseriInicio(lista *inicio, std::string codigo, float preco, std::string nome, int quantidade) {
    lista *novo = new lista();
    novo->codigo = codigo;
    novo->preco = preco;
    novo->nome = nome;
    novo->quantidade = quantidade;
    novo->proximo = inicio;
    inicio = novo;
    return inicio;
}

void listaAjustaPreco(lista *inicio, int taxa) {
    int i;
    for(i = 0; i < 5; i++) {
        inicio->preco -= (float)taxa / 100 * inicio->preco;
        inicio = inicio->proximo;
    }
}

void listaExibeRelatorio(lista *inicio) {
    int i;
    for(i = 0; i < 5; i++) {
        std::cout << "Código do produto: " << inicio->codigo << "\t Novo preço: " << inicio->preco << "\n";
    }
}

void listaExibeMaiorQuantidade(lista *inicio) {
    int i;
    for(i = 0; i < 5; i++) {
        do {
            if(inicio->quantidade >= 500) {
                std::cout << "O Produto \"" << inicio->nome << "\" possui " << inicio->quantidade << " unidades no estoque.\n";
            }
            inicio = inicio->proximo;
        } while(inicio != NULL);
    }
}

int main() {
    int i, quantidade, taxa;
    float preco;
    std::string codigo, nome;
    lista *inicio = NULL, *fim = NULL;
    for(i = 0; i < 5; i++) {
        std::cout << "Insira o código do produto: ";
        std::cin >> codigo;
        std::cout << "Insira o preço do produto: ";
        std::cin >> preco;
        std::cout << "Insira o nome do produto: ";
        std::cin >> nome;
        std::cout << "Insira a quantidade estocada do produto: ";
        std::cin >> quantidade;
        inicio = listaInseriInicio(inicio, codigo, preco, nome, quantidade);
        if(fim == NULL) fim = inicio;
    }
    std::cout << "Insira a taxa de desconto: ";
    std::cin >> taxa;
    listaAjustaPreco(inicio, taxa);
    listaExibeRelatorio(inicio);
    listaExibeMaiorQuantidade(inicio);
}