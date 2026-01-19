#pragma once
#ifndef MENU
#define MENU

#include <iostream>
#include <string>

#include "blockchain.hpp"

using namespace std;

void exibirBloco(Bloco* block){
    cout << "-----------------------------------------\n";
    cout << "Indice: " << block->indice << endl;
    cout << "Hash Anterior: " << block->anterior->hash << endl;
    cout << "Registro: " << block->registro << endl;
    cout << "Nounce: " << block->nounce << endl;
    cout << "Criacao: " << block->criacao << endl;
    cout << "Hash: " << block->hash << endl;
    cout << "-----------------------------------------\n";
}

void exibirBlockchain(Blockchain* bc){
    Bloco* block = bc->ultimoBloco;
    while(block!=bc->genesis){
        exibirBloco(block);
        block=block->anterior;
    }
}

#define PAUSE "read -n 1 -s -r -p \"Press any key to continue...\""

void menu(Blockchain* bc){
    int opcao = 0;
    while(opcao!=4){
        cout << "\nEscolha uma opcao:\n1)\tAdicionar Bloco;\n2)\tMostrar Blockchain;\n3)\tVerificar Validade;\n4)\tSair.\n";
        cout << "-------------------------------\nOpcao: ";
        cin >> opcao;
        string aux;
        switch(opcao){
            case 1:
                cout << "\nRegistro: ";
                cin >> aux;
                bc->adicionarBloco(aux);
                break;
            case 2:
                system("clear");
                exibirBlockchain(bc);
                system(PAUSE" && clear");
                break;
            case 3:
                cout << "Blockchain ";
                bc->validar() ? cout << "valida!\n" : cout << "invalida!\n";
                system(PAUSE);
                break;
            case 4:
                break;
            default:
                cout << "Opcao invalida!";
                opcao = 2;
                system(PAUSE);
                break;
        }
        system("clear");
    }
}

#endif
