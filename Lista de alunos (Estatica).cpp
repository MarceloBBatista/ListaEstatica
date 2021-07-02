#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "interface.h"


int main()
{
    using namespace std;

    setlocale(LC_ALL, "Portuguese");


	List* ListaAlunos;
	Aluno p;
	Aluno *Alunop;

	Alunop = &p;

    int i = 1;
	int aux = 0;
	char menu;

	ListaAlunos = criaLista();

    while (i != 0)
    {
		printf("\n#############################################");
		printf("\n           MENU - Lista de informacao      ");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n-->  1 = Matriculas\n   ");
		printf("\n-->  2 = Adicionar Novo Aluno\n ");
		printf("\n-->  3 = Remover Aluno\n ");
		printf("\n-->  4 = Buscar\n  ");
		printf("\n-->  5 = Situacao do Estudante\n ");
		printf("\n-->  6 = Imprimir Lista de Alunos\n ");
		printf("\n-->  7 = Calcular Media da Turma\n ");
		printf("\n");
		printf("\nAperte Outra Tecla Para Sair!\n ");
		printf("\n");
		printf("\n#############################################");
		printf("\n\n\n>> "); cin >> menu;

		

		menu = toupper(menu);

		switch (menu)
		{
			case '1': // Mostrar Alunos Matriculados
				aux = tamanhoDaLista(ListaAlunos);
				cout << "Elementos na Lista : " << aux << endl;
				break;

			case '2': // Add novo aluno
				cout << "Informe o Nome :"; cin >> p.nome ;
				cout << "Informe a Matricula :"; cin >> p.matricula ;
				cout << "Informe a Idade :"; cin >> p.idade;
				aux = inserirAlunoNovo(ListaAlunos, p);
				if (aux == 0) {
					cout << "ERROR" << endl;
				}
				break;

			case '3': // Remove Aluno da Lista
				cout << "Informe a Matricula do Aluno :"; cin >> p.matricula;
				aux = removeAluno(ListaAlunos, p.matricula);
				if (aux == 0) {
					cout << "ERROR" << endl;
				}
				break;

				//Buscar Aluno na Lista
			case '4':
				cout << "Informe a posicao que deseja acessar :"; cin >> aux;



				aux = buscarAlunoNaLista(ListaAlunos, aux, Alunop);

				if (aux == 0) {
					cout << "ERROR" << endl;
				}
					//----



				if (p.n2 && p.n1 <= 0) {

					cout << " Aluno solicitado: " << endl << " Nome - " << p.nome << endl << " Matricula - " << p.matricula << endl << " Idade - " << p.idade << endl;
					cout <<"Situacao - "<< "Cursando..."<<endl<<endl;

					cout << "Deseja adicionar notas do aluno ?\n [1] para SIM || [2] para NAO" << endl;
					int mudarNotas;
					cin >> mudarNotas;
					
					if (mudarNotas == 1) {
						cout << "Digite a nota 1: "; cin >> p.n1;
						cout << "Digite a nota 2: "; cin >> p.n2;

						cout << "Nota adicionada !" << endl;
					}

				}
				else
				{
					cout << " Aluno solicitado em : " << endl << " Nome - " << p.nome << endl << " Matricula - " << p.matricula << endl << " Idade - " << p.idade << endl;
					cout << "Situacao : " << "" << endl << endl;
					if (p.n1 * 0.4 && p.n2 * 0.6 >= 6) {

						cout << "Aluno APROVADO !\n";
					}
					else
					{
						cout << "Aluno REPROVADO\n";
					}




			
				}
				
				
				break;

				// Consultar Situação do Aluno
			case '5':

				cout << "Informe a Posicao do Aluno Desejado :"; cin >> aux;

				aux = buscarAlunoNaLista(ListaAlunos, aux, Alunop);

				if (aux == 0) {
					cout << "ERROR" << endl;
				}

				if (p.n1 || p.n2 < 0)
				{
					cout << "Aluno Cursando..." << endl;
				}
				else {
					cout << " Notas do Aluno : " << endl << " Nota 1 - " << p.n1 << endl << "Nota 2 - " << p.n2 << endl;
					cout << " ";

					if (p.n1 * 0.4 && p.n2 * 0.6 >= 6) {

						cout << "Aluno APROVADO!\n";
					}
					else
					{
						cout << "Aluno REPROVADO!\n";
					}
				}
				break;

				// Exibir Lista de Alunos
			case '6':

				imprimirLista(ListaAlunos);


				break;

				
				//Calcular Média da Turma
			case '7':
				aux = tamanhoDaLista(ListaAlunos);

				float nota1, nota2, somanota, mediaaluno, somaclasse = 0;
				float mediaclasse = 0;
				int i, aprovado = 0, reprovado = 0, exame = 0;

				for (i = 1; i <= aux; i++)
				{
					cout << "\n Digite a Primeira Nota: ";
					cin >> nota1;

					cout << "\n Digite a Segunda Nota: ";
					cin >> nota2;

					somanota = nota1 + nota2;
					mediaaluno = somanota / 2;

					if (mediaaluno >= 7)
					{
						cout << "\n Aprovado!";
						exame++;
					}

					else

					{
						cout << "\n Reprovado!";
						reprovado++;
					}

					somaclasse = somaclasse + somanota;
				}

				mediaclasse = somaclasse / (aux*2);
				cout << "\n A media da classe  foi : " << mediaclasse;
				system("pause");
				

			

		}


    }
}

