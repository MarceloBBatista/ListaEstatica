#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "interface.h"


using namespace std;

struct Ponto;

struct List
{
	int Quantidade;

	Aluno listaAlunos[Limite];
};



// Função para criar Lista
List* criaLista()
{
	List* Pont;
	Pont = (List*)malloc(sizeof(List));

	if (Pont == NULL) {
		return 0;
	}
	Pont->Quantidade = 0;
}
//---

// Função para verificar se a lista está cheia
int listaCheia(List* Pont) {

	if (Pont == NULL) {
		cout << "\nERROR" << endl;
		return -1;
	}
	else
	{
		return (Pont->Quantidade == Limite);

		// Se retornar 1 significa que atingiu o maximo.
		// Se retornar 0 siginifica que ainda tem espaço na lista.
	}
}
//---

// Função que verifica se a lista está vazia
int listaVazia(List* Pont) {

	if (Pont == NULL) {
		cout << "\nERROR" << endl;
		return -1;
	}
	else
	{
		return (Pont->Quantidade == 0);
		// Se retornar 1 significa que está vazia.
		// Se retornar 0 siginifica que tem condeudo na lista.
	}
}
//---


// Função para inserir aluno na lista ( *insere no final )
int inserirAlunoNovo(List* Pont, Aluno aluno) {

	if (Pont == NULL) {
		cout << "\nERROR" << endl;
		return 0;
	}
	else if (listaCheia(Pont))
	{
		cout << "\nLista cheia" << endl;
		return 0;
	}
	else
	{
		Pont->listaAlunos[Pont->Quantidade] = aluno;
		Pont->Quantidade++;
		return 1;
	}
}
//---

// Função para remover aluno da lista
int removeAluno(List* Pont, float matAluno) {

	if (Pont == NULL) {
		cout << "\nERROR" << endl;
		return 0;
	}
	else if (Pont->Quantidade == 0) {
		cout << "Lista vazia!" << endl;
		return 0;
	}
	else
	{
		int i = 0;
		while (i < Pont->Quantidade && Pont->listaAlunos[i].matricula != matAluno) {
			i++;
		}

		if (i == Pont->Quantidade) {
			cout << "Aluno não encontrado!" << endl;
			return 0;
		}

		for (int x = i; x < Pont->Quantidade; x++) {
			Pont->listaAlunos[x] = Pont->listaAlunos[x + 1];
		}
		Pont->Quantidade--;
		return 1;
	}

}
//---

// Função para buscar aluno (por matricula)
int buscarAlunoNaLista(List* Pont, int al, Aluno* aluno){
	if (Pont == NULL) {
		cout << "\nERROR" << endl;
		return 0;
	}
	else if (al <= 0 || al > Pont->Quantidade)
	{
		cout << "Elemento não encontrado!" << endl;
		return 0;
	}
	else
	{
		*aluno = Pont->listaAlunos[al - 1];
		return 1;
	}
}
//---



// Função para limpar a lista
void liberarLista(List* Pont) {
	free(Pont);
}
//---

// Função para ver o tamanho da lista
int tamanhoDaLista(List* Pont) {

	if (Pont == NULL) {
		cout << "\nERROR" << endl;
		return -1;
	}
	else
	{
		return Pont->Quantidade;
	}
}
//---

// Função para exibir a lista toda

void imprimirLista(List* Pont) {
	for (int i = 0; i < Pont->Quantidade; i++) {
		cout << i + 1 << " - " << "Nome = " << Pont->listaAlunos[i].nome << " Matricula = " << Pont->listaAlunos[i].matricula<< "\n";
	}
}
