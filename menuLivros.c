#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "input.h"
#include "biblioteca.h"
#include "output.h"
#include "menuLivros.h"
#include "defines.h"
#include "menuAutores.h"
#include "menuEditoras.h"

BaseDados *menuLivros(BaseDados *livros) {
    int option;

    do {
        menuLivrosDisplay();
        scanf("%d", &option);
        cleanInputBuffer();

        switch (option) {
            case 1:
                livros = inserirNovoLivro(livros);
                break;
            case 2:
                listarLivros(livros);
                break;
            case 3:
                // livros = removerLivros(livros);
                break;
            case 0:
                break;

        }



    } while (option != 0);

    return livros;
}

BaseDados *novaListaLivros(BaseDados *livros, int size) {
    if (LIVRO_PTR == NULL) {

        LIVRO_PTR = calloc(1, sizeof (Livro));

        livros->livrosCtr = 0;


    } else if (LIVRO_PTR != NULL && size != 1) {
        LIVRO_PTR = realloc(LIVRO_PTR, size * sizeof (Livro));

        if (LIVRO_PTR == NULL) {
            puts("ERROR ALLOCATING MEMORY");
            return 0;
        }


    }

    return livros;

}

BaseDados *novoLivro(BaseDados *livro, int index) {
    puts("INSERIR NOVO LIVRO\n");
    int tipo;
    int autorIndex;
    int editoraIndex;

    livro->livroPtr[index].numero = index;

    readString(LIVROS_TITULO, MAX_TITULO, MSG_GET_TITULO_LIVRO);
    escolherTipo(livro, index);


    autorIndex = escolherAutor(livro);

    strcpy(livro->livroPtr[index].autor, livro->autorPtr[autorIndex].autorNome);

    editoraIndex = escolherEditora(livro);


    strcpy(livro->livroPtr[index].edtiora, livro->editoraPtr[editoraIndex].nome);



    return livro;

}

BaseDados *inserirNovoLivro(BaseDados *livro) {
    livro = novaListaLivros(livro, LIVROS_CTR + 1);
    livro = novoLivro(livro, LIVROS_CTR);
    LIVROS_CTR++;

    return livro;
}

void listarLivros(BaseDados *livros) {
    int i;

    for (i = 0; i < livros->livrosCtr; i++) {
        printf("Numero:%d\n", livros->livroPtr[i].numero);
        printf("Titulo:%s\n", livros->livroPtr[i].titulo);
        printf("ISBN:%d\n", livros->livroPtr[i].isbn);
        printf("Tipo:%s\n", livros->livroPtr[i].tipo);
        printf("Autor:%s\n", livros->livroPtr[i].autor);
        printf("Edtiora:%s\n", livros->livroPtr[i].edtiora);
    }
}

int *escolherAutor(BaseDados *autor) {
    int escolha;

    listarAutores(autor);

    puts("Escolha o index to autor: ");
    scanf("%d", &escolha);

    for (int i = 0; i < autor->autoresCtr; i++) {
        if (autor->autorPtr[i].autorNum == escolha) {
            return i;
        }
    }

    return -1;

}

int *escolherEditora(BaseDados *editora) {
    int escolha;

    listarEditoras(editora);

    puts("Escolaha o index da editora: ");
    scanf("%d", &escolha);

    for (int i = 0; i < editora->autoresCtr; i++) {
        if (editora->editoraPtr[i].editoraNum == escolha) {
            return i;
        }
    }

    return -1;

}

void *escolherTipo(BaseDados *livro, int index) {
    int escolha;

    listarTipos();
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            strcpy(livro->livroPtr[index].tipo, "Ficção");
            break;
        case 2:
            strcpy(livro->livroPtr[index].tipo, "Romance");
            break;
        case 3:
            strcpy(livro->livroPtr[index].tipo, "Romance");
            break;
        case 4:
            strcpy(livro->livroPtr[index].tipo, "Estudo");
            break;

    }

}

BaseDados *salvarLivros(BaseDados *livro, char *filename) {
    int i;

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fwrite(&livro->livrosCtr, sizeof (int), 1, fp);

    for (i = 0; i < livro->livrosCtr; i++) {
        fwrite(&livro->livroPtr[i], sizeof (Livro), 1, fp);
    }

    fclose(fp);

    return livro;
}

BaseDados *carregarLivros(BaseDados *livro, char *filename) {
    int i;

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        puts("File no Data");
        return livro;
    }

    fread(&livro->livrosCtr, sizeof (int), 1, fp);
    if (livro->livrosCtr > 0) {
        livro->livroPtr = (Livro *) calloc(livro->livrosCtr, sizeof (Livro));
        for (int i = 0; i < livro->livrosCtr; i++) {
            fread(&livro->livroPtr[i], sizeof (Livro), 1, fp);
        }
    }

    fclose(fp);
    return livro;

}

