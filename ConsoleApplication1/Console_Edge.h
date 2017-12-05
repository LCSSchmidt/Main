
#include <iostream>

using namespace std;

const int BORDA_PRINCIPAL_VERTICAL = 29;
const int BORDA_PRINCIPAL_HORIZONTAL = 119;
const char CERCA = '#';
const char VAZIO = '\0';

struct Pagina_inicial {
	char corpo[BORDA_PRINCIPAL_VERTICAL][BORDA_PRINCIPAL_HORIZONTAL];
};

void _preencher_corpo(Pagina_inicial &pagina, int &linha, int coluna, int chamadas = 0, int ZERO = 0) {
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

void preencher_corpo(Pagina_inicial &pagina, int linha = 0, int coluna = 0) {
	if (linha == BORDA_PRINCIPAL_VERTICAL) {
		return;
	}
	_preencher_corpo(pagina, linha, coluna);
	preencher_corpo(pagina, linha, coluna);
}

void _bordas_principal(Pagina_inicial &pagina, int &auxiliar, int &passagens, int &linha, int &coluna, int chamadas = 0) {
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

void bordas_principal(Pagina_inicial &pagina, int auxiliar, int passagens = 0, int linha = 0, int coluna = 0) {
	if (passagens == BORDA_PRINCIPAL_VERTICAL * 2 + BORDA_PRINCIPAL_HORIZONTAL * 2 - 3) {
		return;
	}

	_bordas_principal(pagina, auxiliar, passagens, linha, coluna);
	bordas_principal(pagina, auxiliar, passagens, linha, coluna);
}

void _desenhar_pagina_inicial(Pagina_inicial pagina, int &linha, int coluna, int chamadas = 0, int ZERO = 0) {
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

void desenhar_pagina_inicial(Pagina_inicial pagina, int linha = 0, int coluna = 0) {
	if (linha == BORDA_PRINCIPAL_VERTICAL) {
		return;
	}
	_desenhar_pagina_inicial(pagina, linha, coluna);
	desenhar_pagina_inicial(pagina, linha, coluna);
}
