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
const int MENSANGEM_GENERO_X = BORDA_PRINCIPAL_HORIZONTAL / 2 - CENTRALIZAR_ESCRITA_HORIZONTAL;
const int MENSANGEM_GENERO_Y = BORDA_PRINCIPAL_VERTICAL / 2 - CENTRALIZAR_ESCRITA_VERTICAL + 5;
const int MENSAGEM_DE_ERRO_X = BORDA_PRINCIPAL_HORIZONTAL / 2 - CENTRALIZAR_ESCRITA_HORIZONTAL;
const int MENSAGEM_DE_ERRO_Y = BORDA_PRINCIPAL_VERTICAL / 2 - CENTRALIZAR_ESCRITA_VERTICAL + 10;
const int MENSAGEM_USUARIO_CRIACO_SUCESSO_X = BORDA_PRINCIPAL_HORIZONTAL / 2 - CENTRALIZAR_ESCRITA_HORIZONTAL - 20;
const int MENSAGEM_USUARIO_CRIACO_SUCESSO_Y = BORDA_PRINCIPAL_VERTICAL / 2 - CENTRALIZAR_ESCRITA_VERTICAL + 10;
const int MENSAGEM_CRIACAO_DE_POST_X = BORDA_PRINCIPAL_HORIZONTAL / 2 - CENTRALIZAR_ESCRITA_HORIZONTAL;
const int MENSAGEM_CRIACAO_DE_POST_Y = BORDA_PRINCIPAL_VERTICAL / 2 - CENTRALIZAR_ESCRITA_VERTICAL;
const int CRIANDO_MENSAGEM_DO_POST_X = BORDA_PRINCIPAL_HORIZONTAL / 4;
const int CRIANDO_MENSAGEM_DO_POST_Y = BORDA_PRINCIPAL_VERTICAL / 2 - CENTRALIZAR_ESCRITA_VERTICAL + 2;

const char CERCA = '#';
const char VAZIO = '\0';


struct Corpo_principal {
	char corpo[BORDA_PRINCIPAL_VERTICAL][BORDA_PRINCIPAL_HORIZONTAL];
};

struct Corpo_pagina_de_post {
	char corpo[BORDA_PRINCIPAL_VERTICAL][BORDA_PRINCIPAL_HORIZONTAL];
};

struct Usuario {
	string *nome_de_usuario;
	string *nome;
	string *senha;
	string *genero;
	string *data_nascimento;
};

struct Posts {
	string *post;
};

void setCursorPosition_posicao(int x, int y)
{

	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cordenadas_cursor = { (SHORT)x , (SHORT)y };
	SetConsoleCursorPosition(hOut, cordenadas_cursor);
}

void limpar_mensagens(int x, int y) {
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
	else if (elemento == "Mensagem de Erro") {
		setCursorPosition_posicao(MENSAGEM_DE_ERRO_X, MENSAGEM_DE_ERRO_Y);
	}
	else if (elemento == "Genero") {
		setCursorPosition_posicao(MENSANGEM_GENERO_X, MENSANGEM_GENERO_Y);
	}
	else if (elemento == "Genero Preenchimento") {
		setCursorPosition_posicao(MENSANGEM_GENERO_X + somatorio, MENSANGEM_GENERO_Y);
	}
	else if (elemento == "Usuario Criado com Sucesso") {
		setCursorPosition_posicao(MENSAGEM_USUARIO_CRIACO_SUCESSO_X, MENSAGEM_USUARIO_CRIACO_SUCESSO_Y);
	}
	else if (elemento == "Digite o que esta pensando") {
		setCursorPosition_posicao(MENSAGEM_CRIACAO_DE_POST_X, MENSAGEM_CRIACAO_DE_POST_Y);
	}
	else if (elemento == "Criando Post") {
		setCursorPosition_posicao(CRIANDO_MENSAGEM_DO_POST_X, CRIANDO_MENSAGEM_DO_POST_Y);
	}

}

void senha_limpar_campo() {
	chamar_CursorPosition("Senha Preenchimento");
	cout << setw(40) << VAZIO;
	chamar_CursorPosition("Confirmar Senha Preenchimento");
	cout << setw(40) << VAZIO;
}

void data_de_nascimento_limpar_campo() {
	chamar_CursorPosition("Data de Nascimento Dia Preenchimento");
	cout << setw(40) << VAZIO;
}

void nome_de_usuario_limpar_campo() {
	chamar_CursorPosition("Nome de Usuario Preenchimento");
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

int pagina_inicial_opcao() {
	int opcao;
	bool situacao = false;
	do {
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
	return opcao;
}

bool senha_verificar_igualdade(string senha1, string senha2, int tamanho_da_senha, int indice = 0) {
	if (indice == tamanho_da_senha && tamanho_da_senha != 0)
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

void mensagens_de_erro(string elemento) {
	if (elemento == "Senha") {
		cout << "Senhas Incompativeis";
	}
	else if (elemento == "Data de Nascimento") {
		cout << "Nao e permitido menores de idade";
	}
	else if (elemento == "Nome Indisponivel") {
		cout << "Nome ja utulizado";
	}
	else if (elemento == "Nome nao Cadastrado") {
		cout << "Nome nao Cadastrado";
	}
	else if (elemento == "Senha Login") {
		cout << "Senha esta incorreta";
	}
	else if (elemento == "Nome nao Permitido") {
		cout << "Nome nao Permitido";
	}
}

void apagar_mensagen_erro() {
	chamar_CursorPosition("Mensagem de Erro");
	cout << setw(40) << VAZIO;
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
	chamar_CursorPosition("Genero");
	cout << "Genero: ";
}

bool nome_comparar(Usuario usuario, string nome_requerido, string nome_registrado, int indice = 0) {
	if (indice == nome_requerido.length())
		return true;
	if (nome_requerido[indice] != nome_registrado[indice])
		return false;
	else
		return nome_comparar(usuario, nome_requerido, nome_registrado, ++indice);
}

bool nome_verificar_disponibilidade(Usuario usuario, string *nome_ponteiro, int quantidade_de_usuarios) {
	string nome = nome_ponteiro[0];
	string nome_registrado;
	int nome_atual_tamanho = nome.length();
	int nome_registrado_tamanho = 0;
	int indice_quantidade_usuarios = 0;
	bool situacao = false;

	if (quantidade_de_usuarios > 0) {
		indice_quantidade_usuarios = quantidade_de_usuarios - 1;
	}

	for (int indice = 0; indice <= indice_quantidade_usuarios; indice++) {
		nome_registrado = usuario.nome_de_usuario[indice];
		nome_registrado_tamanho = nome_registrado.length();

		if (nome_atual_tamanho == nome_registrado_tamanho) {
			nome_comparar(usuario, nome, nome_registrado);
			if (situacao) {
				return true;
			}
		}
	}
	if (!situacao) {
		return false;
	}

}

bool idade_verificar_maior_de_idade(int *dia_ponteiro, int *mes_ponteiro, int *ano_ponteiro) {
	int dia = *dia_ponteiro;
	int mes = *mes_ponteiro;
	int ano = *ano_ponteiro;

	if (ano > 1999) {
		return false;
	}
	else
		return true;
}

void salvar_cadastro(Usuario &usuario, string *username, string *senha, string *nome_completo, string data_nascimento, string *genero, int quantidade_de_usuarios) {
	usuario.nome_de_usuario[quantidade_de_usuarios] = username[0];
	usuario.senha[quantidade_de_usuarios] = senha[0];
	usuario.nome[quantidade_de_usuarios] = nome_completo[0];
	usuario.data_nascimento[quantidade_de_usuarios] = data_nascimento;
	usuario.genero[quantidade_de_usuarios] = genero[0];
}

void usuario_cadastro(Usuario &usuario, int &quantidade_de_usuarios) {
	string *username = new string[1];
	string *senha = new string[1];
	string *nome_completo = new string[1];
	string *genero = new string[1];
	int *data_de_nascimento_dia = new int[1];
	int *data_de_nascimento_mes = new int[1];
	int *data_de_nascimento_ano = new int[1];
	string senha1;
	string senha2;
	string data_nascimento;
	int tamanho_da_senha = 0;
	bool situacao = false;
	bool erro = false;

	usuario_cadastro_escrever_opcoes();

	do {
		chamar_CursorPosition("Nome de Usuario Preenchimento");
		getline(cin, *username);

		if (erro) {
			apagar_mensagen_erro();
		}

		if (username[0].length() == 0) {
			chamar_CursorPosition("Mensagem de Erro");
			mensagens_de_erro("Nome nao Permitido");
			erro = true;
			situacao = true;
		}
		else
			erro = false;

		if (!erro) {
			situacao = nome_verificar_disponibilidade(usuario, username, quantidade_de_usuarios);
			if (situacao) {
				chamar_CursorPosition("Mensagem de Erro");
				mensagens_de_erro("Nome Indisponivel");
				nome_de_usuario_limpar_campo();
				erro = true;
			}
		}
	} while (situacao);

	if (erro) {
		apagar_mensagen_erro();
		erro = false;
	}

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
			chamar_CursorPosition("Mensagem de Erro");
			mensagens_de_erro("Senha");
			senha_limpar_campo();
			erro = true;
		}
	} while (situacao);

	if (erro) {
		apagar_mensagen_erro();
		erro = false;
	}
	chamar_CursorPosition("Nome Completo Preenchimento");
	getline(cin, *nome_completo);

	do {
		chamar_CursorPosition("Data de Nascimento Dia Preenchimento");
		cin >> *data_de_nascimento_dia;
		chamar_CursorPosition("Data de Nascimento Mes Preenchimento");
		cin >> *data_de_nascimento_mes;
		chamar_CursorPosition("Data de Nascimento Ano Preenchimento");
		cin >> *data_de_nascimento_ano;
		situacao = idade_verificar_maior_de_idade(data_de_nascimento_dia, data_de_nascimento_mes, data_de_nascimento_ano);
		if (!situacao) {
			chamar_CursorPosition("Mensagem de Erro");
			mensagens_de_erro("Data de Nascimento");
			data_de_nascimento_limpar_campo();
		}
	} while (!situacao);

	if (erro) {
		apagar_mensagen_erro();
		erro = false;
	}

	chamar_CursorPosition("Genero Preenchimento");
	getline(cin, *genero);

	data_nascimento = data_de_nascimento_dia[0], +" / " + data_de_nascimento_mes[0], +" / " + data_de_nascimento_ano[0];
	salvar_cadastro(usuario, username, senha, nome_completo, data_nascimento, genero, quantidade_de_usuarios);
	chamar_CursorPosition("Usuario Criado com Sucesso");
	cout << "Usuario Criado com sucesso, pressione qualquer tecla para voltar a pagina Inicial";
	_getch();

	quantidade_de_usuarios++;
}

bool nome_verificar_registro(Usuario usuario, string nome, int quantidade_de_usuarios, int &indice_da_senha) {
	string nome_registrado;
	int nome_atual_tamanho = nome.length();
	int nome_registrado_tamanho = 0;
	int indice_quantidade_usuarios = 0;
	bool situacao = false;

	if (quantidade_de_usuarios > 0) {
		indice_quantidade_usuarios = quantidade_de_usuarios - 1;
	}

	for (int indice = 0; indice <= indice_quantidade_usuarios; indice++) {
		nome_registrado = usuario.nome_de_usuario[indice];
		nome_registrado_tamanho = nome_registrado.length();

		if (nome_atual_tamanho == nome_registrado_tamanho) {
			situacao = nome_comparar(usuario, nome, nome_registrado);
			if (situacao) {
				indice_da_senha = indice;
				return true;
			}
		}
	}
	if (!situacao)
		return false;
}

bool senha_comparar_registro(Usuario usuario, string senha, int indice_senha) {
	string senha_registro = usuario.senha[indice_senha];
	int tamanho_senha = senha_registro.length();

	for (int indice = 0; indice < tamanho_senha; indice++) {
		if (senha[indice] != senha_registro[indice]) {
			return false;
		}
	}
	return true;
}

void usuario_login_screen_opcoes() {
	chamar_CursorPosition("Nome de Usuario");
	cout << "Nome de Usuario: ";
	chamar_CursorPosition("Senha");
	cout << "Senha: ";
}

void usuario_login(Usuario usuario, int quantidade_de_usuarios) {
	string nome_de_usuario;
	string senha;
	bool situacao;
	bool erro = false;
	int senha_indice = 0;
	do {
		do {
			chamar_CursorPosition("Nome de Usuario Preenchimento");
			getline(cin, nome_de_usuario);
			situacao = nome_verificar_registro(usuario, nome_de_usuario, quantidade_de_usuarios, senha_indice);
			if (!situacao) {
				chamar_CursorPosition("Mensagem de Erro");
				mensagens_de_erro("Nome nao Cadastrado");
				nome_de_usuario_limpar_campo();
				erro = true;
			}
		} while (!situacao);

		if (erro) {
			apagar_mensagen_erro();
			erro = false;
		}


		chamar_CursorPosition("Senha Preenchimento");
		getline(cin, senha);
		situacao = senha_comparar_registro(usuario, senha, senha_indice);
		if (!situacao) {
			chamar_CursorPosition("Mensagem de Erro");
			mensagens_de_erro("Senha Login");
			nome_de_usuario_limpar_campo();
			senha_limpar_campo();
			erro = true;
		}
	} while (!situacao);
}

void usuario_login_screen(Usuario usuario, int quantidade_de_usuarios) {
	usuario_login_screen_opcoes();
	usuario_login(usuario, quantidade_de_usuarios);
}

string converter_de_decimal_para_letra(int letra_decimal) {
	if (letra_decimal == 8) {
		return "\0";
	}
	else if (letra_decimal == 9) {
		return "\n";
	}
	else if (letra_decimal == 13) {
		return "CR";
	}
	else if (letra_decimal == 27) {
		return "ESC";
	}
	else if (letra_decimal == 32) {
		return " ";
	}
	else if (letra_decimal == 33) {
		return "!";
	}
	else if (letra_decimal == 34) {
		return "\"";
	}
	else if (letra_decimal == 35) {
		return "#";
	}
	else if (letra_decimal == 36) {
		return "$";
	}
	else if (letra_decimal == 37) {
		return "%";
	}
	else if (letra_decimal == 38) {
		return "&";
	}
	else if (letra_decimal == 39) {
		return "'";
	}
	else if (letra_decimal == 40) {
		return "(";
	}
	else if (letra_decimal == 41) {
		return ")";
	}
	else if (letra_decimal == 42) {
		return "*";
	}
	else if (letra_decimal == 43) {
		return "+";
	}
	else if (letra_decimal == 44) {
		return ",";
	}
	else if (letra_decimal == 45) {
		return "-";
	}
	else if (letra_decimal == 46) {
		return ".";
	}
	else if (letra_decimal == 47) {
		return "/";
	}
	else if (letra_decimal == 48) {
		return "0";
	}
	else if (letra_decimal == 49) {
		return "1";
	}
	else if (letra_decimal == 50) {
		return "2";
	}
	else if (letra_decimal == 51) {
		return "3";
	}
	else if (letra_decimal == 52) {
		return "4";
	}
	else if (letra_decimal == 53) {
		return "5";
	}
	else if (letra_decimal == 54) {
		return "6";
	}
	else if (letra_decimal == 55) {
		return "7";
	}
	else if (letra_decimal == 56) {
		return "8";
	}
	else if (letra_decimal == 57) {
		return "9";
	}
	else if (letra_decimal == 58) {
		return ":";
	}
	else if (letra_decimal == 59) {
		return ";";
	}
	else if (letra_decimal == 60) {
		return "<";
	}
	else if (letra_decimal == 61) {
		return "=";
	}
	else if (letra_decimal == 62) {
		return ">";
	}
	else if (letra_decimal == 63) {
		return "?";
	}
	else if (letra_decimal == 64) {
		return "@";
	}
	else if (letra_decimal == 65) {
		return "A";
	}
	else if (letra_decimal == 66) {
		return "B";
	}
	else if (letra_decimal == 67) {
		return "C";
	}
	else if (letra_decimal == 68) {
		return "D";
	}
	else if (letra_decimal == 69) {
		return "E";
	}
	else if (letra_decimal == 70) {
		return "F";
	}
	else if (letra_decimal == 71) {
		return "G";
	}
	else if (letra_decimal == 72) {
		return "H";
	}
	else if (letra_decimal == 73) {
		return "I";
	}
	else if (letra_decimal == 74) {
		return "J";
	}
	else if (letra_decimal == 75) {
		return "K";
	}
	else if (letra_decimal == 76) {
		return "L";
	}
	else if (letra_decimal == 77) {
		return "M";
	}
	else if (letra_decimal == 78) {
		return "N";
	}
	else if (letra_decimal == 79) {
		return "O";
	}
	else if (letra_decimal == 80) {
		return "P";
	}
	else if (letra_decimal == 81) {
		return "Q";
	}
	else if (letra_decimal == 82) {
		return "R";
	}
	else if (letra_decimal == 83) {
		return "S";
	}
	else if (letra_decimal == 84) {
		return "T";
	}
	else if (letra_decimal == 85) {
		return "U";
	}
	else if (letra_decimal == 86) {
		return "V";
	}
	else if (letra_decimal == 87) {
		return "W";
	}
	else if (letra_decimal == 88) {
		return "X";
	}
	else if (letra_decimal == 89) {
		return "Y";
	}
	else if (letra_decimal == 90) {
		return "Z";
	}
	else if (letra_decimal == 91) {
		return "[";
	}
	else if (letra_decimal == 92) {
		return "\\";
	}
	else if (letra_decimal == 93) {
		return "]";
	}
	else if (letra_decimal == 94) {
		return "^";
	}
	else if (letra_decimal == 95) {
		return "_";
	}
	else if (letra_decimal == 96) {
		return "'";
	}
	else if (letra_decimal == 97) {
		return "a";
	}
	else if (letra_decimal == 98) {
		return "b";
	}
	else if (letra_decimal == 99) {
		return "c";
	}
	else if (letra_decimal == 100) {
		return "d";
	}
	else if (letra_decimal == 101) {
		return "e";
	}
	else if (letra_decimal == 102) {
		return "f";
	}
	else if (letra_decimal == 103) {
		return "g";
	}
	else if (letra_decimal == 104) {
		return "h";
	}
	else if (letra_decimal == 105) {
		return "i";
	}
	else if (letra_decimal == 106) {
		return "j";
	}
	else if (letra_decimal == 107) {
		return "k";
	}
	else if (letra_decimal == 108) {
		return "l";
	}
	else if (letra_decimal == 109) {
		return "m";
	}
	else if (letra_decimal == 110) {
		return "n";
	}
	else if (letra_decimal == 111) {
		return "o";
	}
	else if (letra_decimal == 112) {
		return "p";
	}
	else if (letra_decimal == 113) {
		return "q";
	}
	else if (letra_decimal == 114) {
		return "r";
	}
	else if (letra_decimal == 115) {
		return "s";
	}
	else if (letra_decimal == 116) {
		return "t";
	}
	else if (letra_decimal == 117) {
		return "u";
	}
	else if (letra_decimal == 118) {
		return "v";
	}
	else if (letra_decimal == 119) {
		return "w";
	}
	else if (letra_decimal == 120) {
		return "x";
	}
	else if (letra_decimal == 121) {
		return "y";
	}
	else if (letra_decimal == 122) {
		return "z";
	}
	else if (letra_decimal == 123) {
		return "{";
	}
	else if (letra_decimal == 124) {
		return "|";
	}
	else if (letra_decimal == 125) {
		return "}";
	}
	else if (letra_decimal == 126) {
		return "~";
	}
}

void post_CursorPosition(int indice, int x_indice = 0) {
	setCursorPosition_posicao(CRIANDO_MENSAGEM_DO_POST_X + x_indice, CRIANDO_MENSAGEM_DO_POST_Y + indice);
}

void _criando_post(string &post, int &chamadas, int &indice, int indice_de_retorno = 0) {
	if (indice_de_retorno == 50 || chamadas == 280)
		return;

	string letra;

	int letra_decimal = 0;
	letra_decimal = _getch();
	letra = converter_de_decimal_para_letra(letra_decimal);
	if (letra[0] == 'C' && letra[1] == 'R') {
		chamadas = 280;
		return _criando_post(post, chamadas, indice, ++indice_de_retorno);
	}
	if (letra == "") {
		int auxiliar = post.length();
		auxiliar -= 2;
		post[chamadas - 1] = VAZIO;
		post_CursorPosition(indice, auxiliar);
	}
	cout << letra;

	if (indice_de_retorno == BORDA_PRINCIPAL_HORIZONTAL - 10) {
		++indice;
		indice_de_retorno = 0;
		post_CursorPosition(indice);
	}
	post += letra;
	_criando_post(post, ++chamadas, indice, ++indice_de_retorno);
}

void criando_post(string &post, int chamadas = 0, int indice = 0) {
	if (chamadas == 280)
		return;

	_criando_post(post, chamadas, indice);
	criando_post(post, chamadas, indice);
}

void criacao_post_pagina(Posts &post, int quantidade_de_posts) {
	string post_atual = " ";

	int indice_do_post = quantidade_de_posts;
	chamar_CursorPosition("Digite o que esta pensando");
	cout << "Digite o que esta pensando";
	chamar_CursorPosition("Criando Post");
	criando_post(post_atual);
}

int main()
{
	Corpo_principal pagina;
	Usuario usuario;
	Posts post;
	Corpo_pagina_de_post pagina_post_corpo;

	int auxiliar = BORDA_PRINCIPAL_VERTICAL - 1;
	int quantidade_de_usuarios = 0;
	int quantidade_de_posts = 0;
	int opcao = 0;
	usuario.nome_de_usuario = new string[quantidade_de_usuarios + 1];
	usuario.nome = new string[quantidade_de_usuarios + 1];
	usuario.senha = new string[quantidade_de_usuarios + 1];
	usuario.genero = new string[quantidade_de_usuarios + 1];
	usuario.data_nascimento = new string[quantidade_de_usuarios + 1];
	post.post = new string[quantidade_de_posts + 1];

	preencher_corpo(pagina);
	bordas_principal(pagina, auxiliar);

	do {
		desenhar_pagina_inicial(pagina);
		criacao_post_pagina(post, quantidade_de_posts);
		opcao = pagina_inicial_opcao();
		if (opcao == 1)
			usuario_login_screen(usuario, quantidade_de_usuarios);
		else if (opcao == 2)
			usuario_cadastro(usuario, quantidade_de_usuarios);
		setCursorPosition_posicao(0, 0);
	} while (opcao != 3);

	system("pause");
	return 0;
}

