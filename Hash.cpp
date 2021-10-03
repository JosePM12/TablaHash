#include <iostream>
#include <string>

using namespace std;

// Funcion para hacer la tabla HASH

int clave(string cadena)
{
    int maximo = cadena.length();
    int clave_dni = 0;
    for (int i = 0; i < maximo; i++)
    {
        clave_dni = clave_dni + int(cadena[i]) - int('0');
    }
    return clave_dni;
}

void Hash(string L[][2], int cant)
{

    for (int i = 0; i < cant; i++)
    {
    }
}

void mostrar(string L[][2], int cant)
{
    cout << "Indice\tDNI\t\tNombre\n";
    for (int i = 0; i < cant; i++)
    {
        cout << i << "\t" << L[i][0] << "\t" << L[i][1] << endl;
    }
}

int main()
{
    string L[][2] = {{"12345678", "Juan"},
                     {"96854326", "María"},
                     {"85215647", "Rosa"},
                     {"50247895", "Pablo"},
                     {"23659874", "Federico"},
                     {"86597545", "Guadalupe"},
                     {"23146385", "Benito"},
                     {"89756413", "Carolina"},
                     {"96445646", "Charlie"},
                     {"74520367", "Donald"}};
    int cant = sizeof(L) / sizeof(L[1]);
    mostrar(L, cant);
}