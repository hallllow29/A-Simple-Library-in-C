#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include "defines.h"
#include "input.h"
#include "output.h"
#include "menuAutores.h"

BaseDados *menuAutores(BaseDados *autor) {
    int option = 0;

    do {
        menuAutoresDisplay();
        scanf("%d", &option);
        cleanInputBuffer();

        switch (option) {
            case 1:
                autor = novoAutor(autor);
                break;
            case 2:
                listarAutores(autor);
                break;
            case 3:
                autor = carregarAutores(autor, SAVE_AUTORES);
                break;
            case 4:
                autor = salvarAutores(autor, SAVE_AUTORES);
                break;
            case 0:
                break;
        }
    } while (option != 0);

    if (option == 9) {
        option == 0;
    }
    
    return autor;
}

BaseDados *novoAutor(BaseDados *autor) {
    autor = novaListaAutores(autor, (autor->autoresCtr + 1));
    autor = inserirAutor(autor, autor->autoresCtr);
    autor->autoresCtr++;

    return autor;
}

BaseDados *novaListaAutores(BaseDados *autor, int size) {
    if (autor->autorPtr == NULL) {

        autor->autorPtr = malloc(1 * sizeof (Autor));
        autor->autoresCtr = 0;

    } else if (autor->autorPtr != NULL && size != 1) {

        autor->autorPtr = realloc(autor->autorPtr, size * sizeof (Autor));

    }

    return autor;

}

BaseDados *inserirAutor(BaseDados *autor, int index) {
    autor->autorPtr[index].autorNum = index;

    readString(autor->autorPtr[index].autorNome, MAX_NOME, "Nome do autor: ");
    readString(autor->autorPtr[index].paginaWeb, MAX_PAGINA_WEB, "Web page: ");
    autor->autorPtr[index].dataNascimento.ano = getInt(1900, 2024, "Ano de nascimento: ");
    autor->autorPtr[index].dataNascimento.dia = getInt(0, 31, "Dia: ");
    autor->autorPtr[index].dataNascimento.mes = getInt(0, 31, "Mes: ");

    return autor;


}

void *listarAutores(BaseDados *autor) {
    int i;

    for (i = 0; i < autor->autoresCtr; i++) {
        printf("Numero:%d\n", autor->autorPtr[i].autorNum);
        printf("Nome:%s\n", autor->autorPtr[i].autorNome);
        printf("Web Page:%s\n", autor->autorPtr[i].paginaWeb);
        printf("Data de Nascimento %d-%d-%d\n", autor->autorPtr[i].dataNascimento.dia, autor->autorPtr[i].dataNascimento.mes, autor->autorPtr[i].dataNascimento.ano);

    }
}

BaseDados *salvarAutores(BaseDados *autor, char *filename) {
    int i;

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fwrite(&autor->autoresCtr, sizeof (int), 1, fp);

    for (i = 0; i < autor->autoresCtr; i++) {
        fwrite(&autor->autorPtr[i], sizeof (Autor), 1, fp);
    }

    fclose(fp);

    return autor;
}

BaseDados *carregarAutores(BaseDados *autor, char *filename) {
    int i;

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        puts("File no Data");
        return autor; // ou retornar NULL ou tratar o erro de outra forma
    }

    fread(&autor->autoresCtr, sizeof (int), 1, fp);
    if (autor->autoresCtr > 0) {
        autor->autorPtr = (Livro *) calloc(autor->autoresCtr, sizeof (Autor));
        for (int i = 0; i < autor->autoresCtr; i++) {
            fread(&autor->autorPtr[i], sizeof (Autor), 1, fp);
        }
    }

    fclose(fp);
    return autor;

}