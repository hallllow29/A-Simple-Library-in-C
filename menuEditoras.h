#ifndef MENUEDITORAS_H
#define MENUEDITORAS_H

#include "biblioteca.h"
#include "defines.h"
#include "input.h"
#include "menuAutores.h"
#include "menuLivros.h"



BaseDados *novaEditora(BaseDados *editora);
BaseDados *novaListaEditora(BaseDados *editora, int size);
BaseDados *inserirEditora(BaseDados *editora, int index);
void listarEditoras(BaseDados *editoras);
int *escolherEditora(BaseDados *editora);

#endif /* MENUEDITORAS_H */

