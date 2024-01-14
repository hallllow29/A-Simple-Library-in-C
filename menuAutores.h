#ifndef MENUAUTORES_H
#define MENUAUTORES_H
#include "biblioteca.h"
#include "menuAutores.h"



BaseDados *inserirAutor(BaseDados *autor, int index);
BaseDados *novoAutor(BaseDados *autor);
BaseDados *novaListaAutores(BaseDados *autor, int size);
void *listarAutores(BaseDados *autor);
BaseDados *carregarAutores(BaseDados *autor, char *filename);
BaseDados *salvarAutores(BaseDados *autor, char *filename);

#endif /* MENUAUTORES_H */

