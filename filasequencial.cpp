#include <iostream>

using namespace std;

class FilaSeq {
private:
    int inicio, fim, nElementos, tamMax;
    int *dados;

public:
    FilaSeq(int tamanho = 100) {
        tamMax = tamanho;
        inicio = 0;
        fim = -1;
        nElementos = 0;
        dados = new int[tamMax];
    }

    ~FilaSeq() {
        delete[] dados;
    }

    bool vazia() {
        return nElementos == 0;
    }

    bool cheia() {
        return nElementos == tamMax;
    }

    int tamanho() {
        return nElementos;
    }

    int primeiro() {
        return vazia() ? -1 : dados[inicio];
    }

    bool insere(int valor) {
        if (cheia()) return false;
        fim = (fim + 1) % tamMax;
        dados[fim] = valor;
        nElementos++;
        return true;
    }

    int remove() {
        if (vazia()) return -1;
        int valorRemovido = dados[inicio];
        inicio = (inicio + 1) % tamMax;
        nElementos--;
        return valorRemovido;
    }

    void imprimirFila() {
        if (vazia()) {
            cout << "A fila esta vazia!" << endl;
            return;
        }
        int i = inicio;
        for (int j = 0; j < nElementos; j++) {
            cout << dados[i] << " ";
            i = (i + 1) % tamMax;
        }
        cout << endl;
    }
};

void introducao() {
    cout << "----- FILA SEQUENCIAL -----\n\n";
}

int main() {
    FilaSeq fila;
    int n, valor;

    introducao();

    if (fila.vazia()) {
        cout << "A fila esta vazia!\n\n";
    }

    cout << "Quantos elementos deseja inserir na fila? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Digite o valor para o elemento " << i + 1 << ": ";
        cin >> valor;
        if (!fila.insere(valor)) {
            cout << "A fila esta cheia. Nao foi possivel inserir o valor." << endl;
        }
    }

    cout << (fila.cheia() ? "\nA fila esta cheia!\n" : "\nA fila nao esta cheia.\n");

    fila.imprimirFila();

    cout << "Tamanho da fila: " << fila.tamanho() << endl;
    cout << "Elemento no inicio da fila: " << fila.primeiro() << endl;

    cout << "Insira um novo elemento na fila: ";
    cin >> valor;
    if (!fila.insere(valor)) {
        cout << "A fila esta cheia. Nao foi possivel inserir o valor." << endl;
    } else {
        cout << "Novo elemento inserido na fila." << endl;
    }

    cout << "Elementos da fila apos nova insercao: ";
    fila.imprimirFila();

    cout << "Removendo um elemento da fila..." << endl;
    fila.remove();

    cout << "Elementos da fila apos a remocao: ";
    fila.imprimirFila();

    return 0;
}
