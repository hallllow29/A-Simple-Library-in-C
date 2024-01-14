#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "biblioteca.h"
#include "output.h"
#include "menuAutores.h"
#include "menuLivros.h"
#include "defines.h"

int main() {
    int option = 0;
    
    BaseDados *storage = malloc(1 * sizeof(BaseDados));
    
    
    BaseDados livros = {.livrosCtr = 0};
    BaseDados autores = {.autoresCtr = 0};
    BaseDados editoras = {.editorasCtr = 0};
    
    do{
        puts("[1] MENU LIVROS");
        puts("[2] MENU AUTORES");
        puts("[3] MENU EDITORAS");
        puts("[4] CARREGAR FICHEIRO");
        puts("[5] SALVAR");
        puts("[0] EXIT");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                storage = menuLivros(storage);
                break;
            case 2:
                menuAutores(storage);
                break;
            case 3:
                menuEditoras(storage);
                break;
            case 4:
                storage = carregarLivros(storage, SAVE_LIVROS);
                break;
            case 5:
                storage = salvarLivros(storage, SAVE_LIVROS);
            case 0:
                break;
                
                
        } 
        
        
    } while(option != 0);
    
    return 0;
            
}
