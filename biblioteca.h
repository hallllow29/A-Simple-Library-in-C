#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define MAX_LIVROS 50
#define MAX_NUMERO 13
#define MAX_TITULO 20
#define MAX_NOME 30
#define MAX_RUA 30
#define MAX_CIDADE 20
#define MAX_PAGINA_WEB 50
#define MSG_GET_NOME_LIVRO "Introduza o nome do livro: "
#define MSG_GET_TITULO_LIVRO "Introduza o titulo do livro: "
#define MSG_GET_ISBN "Introduza o ISBN: "
#define SAVE_LIVROS "livros.bin"
#define SAVE_AUTORES "autores.bin"
#define SAVE_EDITORAS "editoras.bin"

// CATEGORIAS
typedef enum {
    ficcao = 1, tecnico = 2, romance = 3, estudo = 4,
            
} Tipo;

// EDITORA
typedef struct {
    int postalCode1;
    int postalCode2;
} CodigoPostal;

typedef struct {
    char rua[MAX_RUA];
    char cidade[MAX_CIDADE];
    CodigoPostal postalCode;
} Morada;

typedef struct {
    int editoraNum;
    char nome[MAX_NOME];
    Morada morada;
    
} Editora;

// AUTOR
typedef struct {
    int dia;
    int mes;
    int ano;
} DataNascimento;

typedef struct {
    int autorNum;
    char autorNome[MAX_NOME];
    char paginaWeb[MAX_PAGINA_WEB];
    DataNascimento dataNascimento;
} Autor;

// LIVRO
typedef struct {
    int numero;
    int isbn;
    char titulo[MAX_TITULO];
    char tipo[MAX_NOME];
    char edtiora[MAX_NOME];
    char autor[MAX_NOME];
    
} Livro;

// CONTEM OS COUNTERS E POINTERS PARA LIVROS, AUTORES E EDITORAS
typedef struct {
    int livrosCtr;
    Livro *livroPtr;
    
    int autoresCtr;
    Autor *autorPtr;
    
    int editorasCtr;
    Editora *editoraPtr;
     
} BaseDados;


BaseDados *menuLivros(BaseDados *storage);
BaseDados *menuAutores(BaseDados *storage);
BaseDados *menuEditoras(BaseDados *storage);













#endif /* BIBLIOTECA_H */

