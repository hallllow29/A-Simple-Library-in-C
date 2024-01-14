#ifndef MENULIVROS_H
#define MENULIVROS_H
#include "biblioteca.h"
#include "input.h"
#include "output.h"
#include "menuLivros.h"


BaseDados *inserirLivros(BaseDados *livros);
void listarLivros(BaseDados *livros);
BaseDados *removerLivros(BaseDados *livros);
BaseDados *novaListLivros(BaseDados *livros);
BaseDados *inserirNovoLivro(BaseDados *livro);
int *escolherAutor(BaseDados *autor);
void *escolherTipo(BaseDados *livro, int index);
BaseDados *salvarLivros(BaseDados *livro, char *fileName);
BaseDados *carregarLivros(BaseDados *livro, char *filename);



#endif /* MENULIVROS_H */

