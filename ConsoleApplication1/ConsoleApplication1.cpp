// RSocial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>

using namespace std;


const int BORDA_PRINCIPAL_VERTICAL = 29;
const int BORDA_PRINCIPAL_HORIZONTAL = 119;
const int CENTRALIZAR_ESCRITA_HORIZONTAL = 15;
const int CENTRALIZAR_ESCRITA_VERTICAL = 5;
const int PAGINA_INICIAL_MENSAGEM_DE_ERRO = 15;
const int PAGINA_INICIAL_SEGUNDA_OPCAO = 1;
const int PAGINA_INICIAL_TERCEIRA_OPCAO = 5;
const int MENSANGEM_NOME_DE_USUARIO_X = BORDA_PRINCIPAL_HORIZONTAL / 2 - CENTRALIZAR_ESCRITA_HORIZONTAL;
const int MENSANGEM_NOME_DE_USUARIO_Y = BORDA_PRINCIPAL_VERTICAL / 2 - CENTRALIZAR_ESCRITA_VERTICAL;
const int MENSANGEM_SENHA_X = BORDA_PRINCIPAL_HORIZONTAL / 2 - CENTRALIZAR_ESCRITA_HORIZONTAL;
const int MENSANGEM_SENHA_Y = BORDA_PRINCIPAL_VERTICAL / 2 - CENTRALIZAR_ESCRITA_VERTICAL + 1;
const int MENSANGEM_SENHA_CONFIRMAR_X = BORDA_PRINCIPAL_HORIZONTAL / 2 - CENTRALIZAR_ESCRITA_HORIZONTAL;
const int MENSANGEM_SENHA_CONFIRMAR_Y = BORDA_PRINCIPAL_VERTICAL / 2 - CENTRALIZAR_ESCRITA_VERTICAL + 2;
const int MENSANGEM_NOME_COMPLETO_X = BORDA_PRINCIPAL_HORIZONTAL / 2 - CENTRALIZAR_ESCRITA_HORIZONTAL;
const int MENSANGEM_NOME_COMPLETO_Y = BORDA_PRINCIPAL_VERTICAL / 2 - CENTRALIZAR_ESCRITA_VERTICAL + 3;
const int MENSANGEM_DATA_DE_NASCIMENTO_X = BORDA_PRINCIPAL_HORIZONTAL / 2 - CENTRALIZAR_ESCRITA_HORIZONTAL;
const int MENSANGEM_DATA_DE_NASCIMENTO_Y = BORDA_PRINCIPAL_VERTICAL / 2 - CENTRALIZAR_ESCRITA_VERTICAL + 4;
const char CERCA = '#';
const char VAZIO = '\0';


struct Corpo_principal {
	char corpo[BORDA_PRINCIPAL_VERTICAL][BORDA_PRINCIPAL_HORIZONTAL];
};

struct Usuario {
	string *nome_de_usuario;
	string *nome;
	string *senha;
	string *genero;
	string *data_nascimento;
};

void setCursorPosition_posicao(int x, int y)
{
	
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cordenadas_cursor = { (SHORT)x , (SHORT)y };
	SetConsoleCursorPosition(hOut, cordenadas_cursor);
}

void limpar_mensagens(int x, int y){
	setCursorPosition_posicao(x, y);
	cout << setw(40) << VAZIO;
}

void limpar_mensagens_pagina_inicial_opcao() {
	limpar_mensagens(BORDA_PRINCIPAL_HORIZONTAL / 2 - CENTRALIZAR_ESCRITA_HORIZONTAL, BORDA_PRINCIPAL_VERTICAL / 2 - CENTRALIZAR_ESCRITA_VERTICAL);
	limpar_mensagens(BORDA_PRINCIPAL_HORIZONTAL / 2 - CENTRALIZAR_ESCRITA_HORIZONTAL, BORDA_PRINCIPAL_VERTICAL / 2 - CENTRALIZAR_ESCRITA_VERTICAL + 1);
	limpar_mensagens(BORDA_PRINCIPAL_HORIZONTAL / 2 - CENTRALIZAR_ESCRITA_HORIZONTAL, BORDA_PRINCIPAL_VERTICAL / 2 - CENTRALIZAR_ESCRITA_VERTICAL + 2);
	limpar_mensagens(BORDA_PRINCIPAL_HORIZONTAL / 2 - CENTRALIZAR_ESCRITA_HORIZONTAL - 5, BORDA_PRINCIPAL_VERTICAL / 2 - CENTRALIZAR_ESCRITA_VERTICAL + 3);
}

void chamar_CursorPosition(string elemento) {
	int somatorio = 0;

	somatorio = elemento.length() - 12;
	if (elemento == "Nome de Usuario") {
		setCursorPosition_posicao(MENSANGEM_NOME_DE_USUARIO_X, MENSANGEM_NOME_DE_USUARIO_Y);
	}
	else if (elemento == "Nome de Usuario Preenchimento") {
		setCursorPosition_posicao(MENSANGEM_NOME_DE_USUARIO_X + somatorio, MENSANGEM_NOME_DE_USUARIO_Y);
	}
	else if (elemento == "Senha") {
		setCursorPosition_posicao(MENSANGEM_SENHA_X, MENSANGEM_SENHA_Y);
	}
	else if (elemento == "Senha Preenchimento") {
		setCursorPosition_posicao(MENSANGEM_SENHA_X + somatorio, MENSANGEM_SENHA_Y);
	}
	else if (elemento == "Confirmar Senha") {
		setCursorPosition_posicao(MENSANGEM_SENHA_CONFIRMAR_X, MENSANGEM_SENHA_CONFIRMAR_Y);
	}
	else if (elemento == "Confirmar Senha Preenchimento") {
		setCursorPosition_posicao(MENSANGEM_SENHA_CONFIRMAR_X + somatorio, MENSANGEM_SENHA_CONFIRMAR_Y);
	}
	else if (elemento == "Nome Completo") {
		setCursorPosition_posicao(MENSANGEM_NOME_COMPLETO_X, MENSANGEM_NOME_COMPLETO_Y);
	}
	else if (elemento == "Nome Completo Preenchimento") {
		setCursorPosition_posicao(MENSANGEM_NOME_COMPLETO_X + somatorio, MENSANGEM_NOME_COMPLETO_Y);
	}
	else if (elemento == "Data de Nascimento") {
		setCursorPosition_posicao(MENSANGEM_DATA_DE_NASCIMENTO_X, MENSANGEM_DATA_DE_NASCIMENTO_Y);
	}
	else if (elemento == "Data de Nascimento Dia Preenchimento") {
		setCursorPosition_posicao(MENSANGEM_DATA_DE_NASCIMENTO_X + somatorio - 4, MENSANGEM_DATA_DE_NASCIMENTO_Y);
	}
	else if (elemento == "Data de Nascimento Mes Preenchimento") {
		setCursorPosition_posicao(MENSANGEM_DATA_DE_NASCIMENTO_X + somatorio - 1, MENSANGEM_DATA_DE_NASCIMENTO_Y);
	}
	else if (elemento == "Data de Nascimento Ano Preenchimento") {
		setCursorPosition_posicao(MENSANGEM_DATA_DE_NASCIMENTO_X + somatorio + 2, MENSANGEM_DATA_DE_NASCIMENTO_Y);
	}

}

void senha_limpar_campo() {
	chamar_CursorPosition("Senha Preenchimento");
	cout << setw(40) << VAZIO;
	chamar_CursorPosition("Confirmar Senha Preenchimento");
	cout << setw(40) << VAZIO;
}

void converter_escolhas(int &escolha) {
	if (escolha == 49) {
		escolha = 1;
	}
	else if (escolha == 50) {
		escolha = 2;
	}
	else if (escolha == 51) {
		escolha = 3;
	}
	else if (escolha == 52) {
		escolha = 4;
	}
}

void _preencher_corpo(Corpo_principal &pagina, int &linha, int coluna, int chamadas = 0, int ZERO = 0) {
	if (chamadas == BORDA_PRINCIPAL_HORIZONTAL) {
		return;
	}

	pagina.corpo[linha][coluna] = VAZIO;
	if (coluna != BORDA_PRINCIPAL_HORIZONTAL - 1) {
		_preencher_corpo(pagina, linha, ++coluna, ++chamadas);
	}
	else {
		_preencher_corpo(pagina, ++linha, 0, ++chamadas);
	}
}

void preencher_corpo(Corpo_principal &pagina, int linha = 0, int coluna = 0) {
	if (linha == BORDA_PRINCIPAL_VERTICAL) {
		return;
	}
	_preencher_corpo(pagina, linha, coluna);
	preencher_corpo(pagina, linha, coluna);
}

void _bordas_principal(Corpo_principal &pagina, int &auxiliar, int &passagens, int &linha, int &coluna, int chamadas = 0) {
	if (passagens == BORDA_PRINCIPAL_VERTICAL * 2 + BORDA_PRINCIPAL_HORIZONTAL * 2 - 3 || chamadas == 270) {
		return;
	}

	pagina.corpo[linha][coluna] = CERCA;

	if (linha == BORDA_PRINCIPAL_VERTICAL - 1 && coluna != 0) {
		_bordas_principal(pagina, auxiliar, ++passagens, linha, --coluna, ++chamadas);
	}
	else if (coluna == BORDA_PRINCIPAL_HORIZONTAL - 1) {
		_bordas_principal(pagina, auxiliar, ++passagens, ++linha, coluna, ++chamadas);
	}
	else if (coluna == 0 && linha == auxiliar) {
		_bordas_principal(pagina, --auxiliar, ++passagens, --linha, coluna, ++chamadas);
	}
	else {
		_bordas_principal(pagina, auxiliar, ++passagens, linha, ++coluna, ++chamadas);
	}
}

void bordas_principal(Corpo_principal &pagina, int auxiliar, int passagens = 0, int linha = 0, int coluna = 0) {
	if (passagens == BORDA_PRINCIPAL_VERTICAL * 2 + BORDA_PRINCIPAL_HORIZONTAL * 2 - 3) {
		return;
	}

	_bordas_principal(pagina, auxiliar, passagens, linha, coluna);
	bordas_principal(pagina, auxiliar, passagens, linha, coluna);
}

void _desenhar_pagina_inicial(Corpo_principal pagina, int &linha, int coluna, int chamadas = 0, int ZERO = 0) {
	if (chamadas == BORDA_PRINCIPAL_HORIZONTAL) {
		cout << endl;
		return;
	}

	cout << pagina.corpo[linha][coluna];

	if (coluna != BORDA_PRINCIPAL_HORIZONTAL - 1)
		_desenhar_pagina_inicial(pagina, linha, ++coluna, ++chamadas);
	else {
		_desenhar_pagina_inicial(pagina, ++linha, 0, ++chamadas);
	}
}

void desenhar_pagina_inicial(Corpo_principal pagina, int linha = 0, int coluna = 0) {
	if (linha == BORDA_PRINCIPAL_VERTICAL) {
		return;
	}
	_desenhar_pagina_inicial(pagina, linha, coluna);
	desenhar_pagina_inicial(pagina, linha, coluna);
}

void pagina_inicial_opcao() {
	int opcao;
	bool situacao = false;
	do{
		setCursorPosition_posicao(BORDA_PRINCIPAL_HORIZONTAL / 2 - CENTRALIZAR_ESCRITA_HORIZONTAL, BORDA_PRINCIPAL_VERTICAL / 2 - CENTRALIZAR_ESCRITA_VERTICAL);
		cout << "1 - Entrar" << endl;
		cout << "#" << setw(BORDA_PRINCIPAL_HORIZONTAL / 2 + PAGINA_INICIAL_SEGUNDA_OPCAO);
		cout << "2 - Criar Usuario" << endl;
		cout << "#" << setw(BORDA_PRINCIPAL_HORIZONTAL / 2 + PAGINA_INICIAL_TERCEIRA_OPCAO);
		cout << "3 - Fechar o Programa" << endl;
		opcao = _getch();
		converter_escolhas(opcao);
		if (opcao != 1 && opcao != 2 && opcao != 3) {
			situacao = true;
			cout << "#" << setw(BORDA_PRINCIPAL_HORIZONTAL / 2 + PAGINA_INICIAL_MENSAGEM_DE_ERRO);
			cout << "OPCAO INCORRETA, DIGITE NOVAMENTE";
		}
		else
			situacao = false;

	} while (situacao);
	limpar_mensagens_pagina_inicial_opcao();
}

void usuario_autenticacao() {

}

bool senha_verificar_igualdade(string senha1, string senha2, int tamanho_da_senha, int indice = 0) {
	if (indice == tamanho_da_senha)
		return false;

	if (senha1[indice] != senha2[indice]) {
		return true;
	}
	else
		return senha_verificar_igualdade(senha1, senha2, tamanho_da_senha, ++indice);
}

bool senha_chamar_verificar_igualdade(string *senha, string senha2) {
	int tamanho_da_senha;
	bool situacao;
	string senha1 = senha[0];

	tamanho_da_senha = senha1.length();
	situacao = senha_verificar_igualdade(senha1, senha2, tamanho_da_senha);
	return situacao;
}

void usuario_cadastro_escrever_opcoes() {
	chamar_CursorPosition("Nome de Usuario");
	cout << "Nome de Usuario: ";
	chamar_CursorPosition("Senha");
	cout << "Senha: ";
	chamar_CursorPosition("Confirmar Senha");
	cout << "Confirmar senha: ";
	chamar_CursorPosition("Nome Completo");
	cout << "Nome Completo: ";
	chamar_CursorPosition("Data de Nascimento");
	cout << "Data de Nascimento: ";
}

void idade_verificar(int *dia, int *mes, int *ano) {

}

void salvar_cadastro(Usuario &usuario, string *username, string *senha, int quantidade_de_usuarios) {
	usuario.nome_de_usuario[quantidade_de_usuarios - 1] = username[0];
	usuario.senha[quantidade_de_usuarios - 1] = senha[0];
}

void usuario_cadastro(Usuario &usuario, int &quantidade_de_usuarios) {
	string *username = new string[1];
	string *senha = new string[1];
	string *nome_completo = new string[1];
	int *data_de_nascimento_dia = new int[1];
	int *data_de_nascimento_mes = new int[1];
	int *data_de_nascimento_ano = new int[1];
	string senha1;
	string senha2;
	int tamanho_da_senha = 0;
	bool situacao;

	usuario_cadastro_escrever_opcoes();
	chamar_CursorPosition("Nome de Usuario Preenchimento");
	getline(cin, *username);
	do {
		chamar_CursorPosition("Senha Preenchimento");
		getline(cin, *senha);
		senha1 = senha[0];
		chamar_CursorPosition("Confirmar Senha Preenchimento");
		getline(cin, *senha);
		senha2 = senha[0];
		tamanho_da_senha = senha1.length();
		situacao = senha_verificar_igualdade(senha1, senha2, tamanho_da_senha);
		if (situacao) {
			senha_limpar_campo();
		}
	} while (situacao);
	chamar_CursorPosition("Nome Completo Preenchimento");
	getline(cin, *nome_completo);
	do {
		chamar_CursorPosition("Data de Nascimento Dia Preenchimento");
		getline(cin, *data_de_nascimento_dia);
		chamar_CursorPosition("Data de Nascimento Mes Preenchimento");
		getline(cin, *data_de_nascimento_mes);
		chamar_CursorPosition("Data de Nascimento Ano Preenchimento");
		getline(cin, *data_de_nascimento_ano);
		idade_verificar(data_de_nascimento_dia, data_de_nascimento_mes, data_de_nascimento_ano);
	} while (situacao);
	salvar_cadastro(usuario, username, senha, quantidade_de_usuarios);
	quantidade_de_usuarios++;
}

int main()
{
	Corpo_principal pagina;
	Usuario usuario;
	int auxiliar = BORDA_PRINCIPAL_VERTICAL - 1;
	int quantidade_de_usuarios = 1;
	usuario.nome_de_usuario = new string[quantidade_de_usuarios];
	usuario.nome = new string[quantidade_de_usuarios];
	usuario.senha = new string[quantidade_de_usuarios];
	usuario.genero = new string[quantidade_de_usuarios];
	usuario.data_nascimento = new string[quantidade_de_usuarios];
	
	preencher_corpo(pagina);
	bordas_principal(pagina, auxiliar);
	desenhar_pagina_inicial(pagina);
	pagina_inicial_opcao();
	usuario_cadastro(usuario, quantidade_de_usuarios);
	system("pause");
	return 0;
}

