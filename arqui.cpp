#include <iostream>
#include <string>
using namespace std;

void sumaBinaria(int A[], int M[], int n) {
    int acarreo = 0;
    for (int i = 0; i < n; i++) {
        int suma = A[i] + M[i] + acarreo;
        A[i] = suma % 2;
        acarreo = suma / 2;
    }
}

void restaBinaria(int A[], int M[], int n) {
    int complementoM[8], acarreo = 1;

    for (int i = 0; i < n; i++) {
        complementoM[i] = M[i] ^ 1;
    }
    for (int i = 0; i < n; i++) {
        int suma = complementoM[i] + acarreo;
        complementoM[i] = suma % 2;
        acarreo = suma / 2;
        if (acarreo == 0) break;
    }
    sumaBinaria(A, complementoM, n);
}

void realizarCorrimiento(int A[], int Q[], int& Q_1, int n) {
    int MSB_A = A[n - 1];
    Q_1 = Q[0];
    for (int i = 0; i < n - 1; i++) {
        Q[i] = Q[i + 1];
    }
    Q[n - 1] = A[0];
    for (int i = 0; i < n - 1; i++) {
        A[i] = A[i + 1];
    }
    A[n - 1] = MSB_A;
}

void mostrarEnBinario(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i];
    }
}

void convertirABinario(string bin, int arr[], int n) {
    int longitud = bin.length();
    for (int i = 0; i < n; i++) {
        if (i < longitud) {
            arr[i] = bin[longitud - 1 - i] - '0';
        }
        else {
            arr[i] = 0;
        }
    }
}

void ejecutarAlgoritmoBooth(int M[], int Q[], int n) {
    int A[8] = { 0 }, Q_1 = 0, contador = n;

    cout << "\nEstado inicial:\n";
    cout << "A: "; mostrarEnBinario(A, n); cout << "\n";
    cout << "Q: "; mostrarEnBinario(Q, n); cout << "\n";
    cout << "Q-1: " << Q_1 << "\n\n";

    while (contador > 0) {
        cout << "Iteracion " << n - contador + 1 << ":\n";

        if (Q[0] == 1 && Q_1 == 0) {
            restaBinaria(A, M, n);
            cout << "Operacion: Restar A = A - M\n";
        }
        else if (Q[0] == 0 && Q_1 == 1) {
            sumaBinaria(A, M, n);
            cout << "Operacion: Sumar A = A + M\n";
        }
        realizarCorrimiento(A, Q, Q_1, n);
        cout << "Despues del corrimiento:\n";
        cout << "A: "; mostrarEnBinario(A, n); cout << "\n";
        cout << "Q: "; mostrarEnBinario(Q, n); cout << "\n";
        cout << "Q-1: " << Q_1 << "\n\n";

        contador--;
    }

    cout << "Resultado final:\n";
    cout << "A: "; mostrarEnBinario(A, n); cout << "\n";
    cout << "Q: "; mostrarEnBinario(Q, n); cout << "\n";
}

int main() {
    int n;
    cout << "Ingrese el numero de bits: ";
    cin >> n;

    string binMultiplicando, binMultiplicador;

    cout << "Ingrese el primer numero en binario: ";
    cin >> binMultiplicando;

    cout << "Ingrese el segundo numero en binario: ";
    cin >> binMultiplicador;

    int M[8] = { 0 }, Q[8] = { 0 };
    convertirABinario(binMultiplicando, M, n);
    convertirABinario(binMultiplicador, Q, n);

    ejecutarAlgoritmoBooth(M, Q, n);

    return 0;
}
