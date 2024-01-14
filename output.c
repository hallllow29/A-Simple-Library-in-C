#include <stdio.h>
#include <stdlib.h>

void menuLivrosDisplay() {
    puts("\t\t\t\t\t\t MENU LIVROS\t\t\t\n");

    puts("[1] Adicionar");
    puts("[2] Listar");
    puts("[3] Carregar");
    puts("[4] Salvar");
    puts("[0] Back");
}

void menuAutoresDisplay() {
    puts("\t\t\t\t\t\t MENU AUTORES\t\t\t\n");
    puts("[1] Adicionar");
    puts("[2] Listar");
    puts("[3] Carregar");
    puts("[4] Salvar");
    puts("[0] Back");
}

void menuEditorasDisplay() {
    puts("\t\t\t\t\t\t MENU EDITORAS\t\t\t\n");
    puts("[1] Adicionar");
    puts("[2] Listar");
    puts("[0] Back\n");

}

void listarTipos() {
    puts("\t\t\t\tTIPOS DE LIVROS");
    puts("[1] Ficção");
    puts("[2] Técnico");
    puts("[3] Romance");
    puts("[4] Estudo");
}