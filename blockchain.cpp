#include "blockchain.hpp"
#include "menu.hpp"

int main(void){
    Blockchain* blockchain = new Blockchain();
    blockchain->adicionarBloco("Teste");
    blockchain->adicionarBloco("Teste1");
    blockchain->adicionarBloco("Teste2");
    blockchain->adicionarBloco("Teste3");
    blockchain->adicionarBloco("Teste4");

    // Definindo `invalidanr_cadeia = true` abaixo altera-se o registro do penultimo bloco, permitindo testar a validação da blockchain
    bool invalidar_cadeia = false;
    if(invalidar_cadeia) {
      Bloco* penultimoBloco = blockchain->ultimoBloco->anterior;
      penultimoBloco->registro = "Teste alterando dados";
    }
    
    menu(blockchain);
    
    return 0;
}
