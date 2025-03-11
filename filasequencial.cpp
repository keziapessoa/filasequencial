#include <iostream>

using namespace std;

class FilaSeq{

private:
    int inicio, fim, nElementos, tamMax;
    int *dados;

public:
    FilaSeq(int tamanho = 100){
        tamMax = tamanho;
        inicio = 0;
        fim = -1;
        nElementos = 0;
        dados = new int[tamMax]; // aloca a memória para os dados
    }

    ~FilaSeq(){
        delete[] dados; // libera a memória alocada
    }

    // VERIFICA SE A FILA ESTÁ VAZIA
    bool vazia(){
        return (nElementos == 0);
    }

    // VERIFICA SE A FILA ESTÁ CHEIA
    bool cheia(){
        return (nElementos == tamMax);
    }

    // OBTÉM O TAMANHO DA FILA
    int tamanho(){
        return nElementos;
    }

    // CONSULTA O ELEMENTO DO INÍCIO DA FILA
    int primeiro(){
        if(vazia())
            return -1; // RETORNA -1 SE A FILA ESTIVER VAZIA
        return dados[inicio];
    }

    // INSERE UM ELEMENTO NO FINAL DA FILA
    bool insere(int valor){
        if(cheia()){
            return false; // FILA CHEIA
        }

        fim = (fim + 1) % tamMax; // ATUALIZA A POSIÇÃO DO FIM
        dados[fim] = valor;
        nElementos++;
        return true;
    }

    // REMOVE O ELEMENTO DO INÍCIO DA FILA
    int remove(){
        if(vazia()){
            return -1; // FILA VAZIA
        }

        int valorRemovido = dados[inicio];
        inicio = (inicio + 1) % tamMax; // ATUALIZA A POSIÇÃO DO INÍCIO
        nElementos--;
        return valorRemovido;
    }

    void imprimirFila(){
        if(vazia()){
            cout << "A fila esta vazia!" << endl;
            return;
        }

        int i = inicio;
        for(int j=0; j<nElementos; j++){
            cout << dados[i] << " ";
            i = (i + 1) % tamMax;
        }

        cout << endl;
    }

};

void introducao(){
    cout << "----- FILA SEQUENCIAL -----" << endl << endl;
}

int main(void){
    FilaSeq fila;
    int n, valor;

    introducao();

    // VERIFICANDO SE A FILA ESTÁ VAZIA NO INÍCIO
    if(fila.vazia()){
        cout << "A fila esta vazia!" << endl << endl;
    }

    // INSERINDO ELEMENTOS NA FILA
    cout << "Quantos elementos desea inserir na fila? ";
    cin >> n;

    for(int i=0; i<n; i++){
        cout << "Digite o valor para o elemento " << i + 1 << ": ";
        cin >> valor;
        if(!fila.insere(valor)){
            cout << "A fila esta cheia. Nao foi possivel inserir o valor." << endl;
        }
    }

    // VERIFICANDO SE A FILA ESTÁ CHEIA
    if(fila.cheia()){
        cout << "\nA fila esta cheia!" << endl;
    }else{
        cout << "\nA fila nao esta cheia." << endl;
    }

    fila.imprimirFila();

    cout << "Tamanho da fila: " << fila.tamanho() << endl;
    cout << "Elemento no inicio da fila: " << fila.primeiro() << endl;

    cout << "Insira um novo elemento na fila: ";
    cin >> valor;
    if(!fila.insere(valor)){
        cout << "A fila esta cheia. Nao foi possivel inserir o valor." << endl;
    }else{
        cout << "Novo elemento insserido na fila." << endl;
    }

    cout << "Elementos da fila apos nova insercao: ";
    fila.imprimirFila();

    cout << "Removendo um elemento da fila..." << endl;
    fila.remove();

    cout << "Elementos da fila apos a remocao: ";
    fila.imprimirFila();

    return 0;
}
