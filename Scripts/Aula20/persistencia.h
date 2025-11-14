#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "fila.h"

/* Salva toda a fila em arquivo texto (um registro por linha) */
int salvarEmArquivo(Fila *f, const char *nomeArquivo);

/* Carrega a fila a partir do arquivo (limpa a fila antes). */
int carregarDeArquivo(Fila *f, const char *nomeArquivo);

/* Apaga o arquivo de dados do disco. */
int apagarArquivo(const char *nomeArquivo);

#endif /* PERSISTENCIA_H */
