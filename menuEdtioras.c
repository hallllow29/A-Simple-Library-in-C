#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include "defines.h"
#include "input.h"
#include "menuLivros.h"
#include "menuAutores.h"
#include "output.h"
#include "menuEditoras.h"   

BaseDados *menuEditoras(BaseDados *editoras) {
    int option;

    do {
        menuEditorasDisplay();
        scanf("%d", &option);
        cleanInputBuffer();

        switch (option) {
            case 1:
                editoras = novaEditora(editoras);
                break;
            case 2:
                listarEditoras(editoras);
                break;
            case 0:
                break;

                if (option == 9) {
                    option == 0;
                }
        }



    } while (option != 0);

    return editoras;


}

BaseDados *novaEditora(BaseDados *editora) {
    editora = novaListaEditora(editora, editora->editorasCtr + 1);
    editora = inserirEditora(editora, editora->editorasCtr);
    editora->editorasCtr++;

    return editora;

}

BaseDados *novaListaEditora(BaseDados *editora, int size) {
    if (editora->editoraPtr == NULL) {

        editora->editoraPtr = calloc(1, sizeof (Editora));
        editora->editorasCtr = 0;

    } else if (editora->editoraPtr != NULL && size != 1) {

        editora->editoraPtr = realloc(editora->editoraPtr, size * sizeof (Editora));

    }

    return editora;
}

BaseDados *inserirEditora(BaseDados *editora, int index) {
    editora->editoraPtr[index].editoraNum = index;

    readString(editora->editoraPtr[index].nome, MAX_NOME, "Nome da editora: ");
    readString(editora->editoraPtr[index].morada.cidade, MAX_CIDADE, "Cidade :");
    readString(editora->editoraPtr[index].morada.rua, MAX_RUA, "Rua: ");
    editora->editoraPtr[index].morada.postalCode.postalCode1 = getInt(1000, 9999, "Postal code 1:");
    editora->editoraPtr[index].morada.postalCode.postalCode2 = getInt(100, 999, "Postal code 2:");

    return editora;

}

void listarEditoras(BaseDados *editoras) {
    int i;

    for (i = 0; i < editoras->editorasCtr; i++) {
        printf("Numero:%d\n", editoras->editoraPtr[i].editoraNum);
        printf("Nome: %s\n", editoras->editoraPtr[i].nome);
        printf("Morada: %s,%s,%d-%d\n", editoras->editoraPtr[i].morada.rua, editoras->editoraPtr[i].morada.cidade, editoras->editoraPtr[i].morada.postalCode.postalCode1, editoras->editoraPtr[i].morada.postalCode.postalCode2);

    }
}