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
    string Copia[cant*2];
    int cont=0;
    for(int i=0;i<cant;i++){
        for(int j=0;j<2;j++){
            Copia[cont]=L[i][j];
            cont+=1;
        }
    }
    for (int i = 0; i < cant; i++)
    {
        L[i][0]="";
        L[i][1]="";
    }

    for(int i=0;i<cant*2;i+=2){
        int codigo = clave(Copia[i]);
        int indice = codigo % cant;
        while(true){
            indice = indice % cant;
            if(L[indice][0]==""){
                L[indice][0]=Copia[i];
                L[indice][1]=Copia[i+1];
                break;
            }
            else{
                indice+=1;
            }
        }

    }


    
}

void menu(string L[][2],int cant){
    cout<<"\nMenu\n";
    cout<<"1. Consultar DNI\n2. Eliminar DNI\n3. Modificar DNI\n4. Salir\n";
    int valor;
    cin>>valor;
    string dni;
    int clave_dni;
    int max;
    int opc=1;
    
    if(valor == 4){
        cout<<"Adios\n";
    }

    else{
        cout<<"Ingrese su DNI: ";
        switch (valor)
        {
        case 1:
            cin>>ws;
            getline(cin,dni);
            cout<<dni<<endl;
            clave_dni = clave(dni);
            max = clave_dni;
            clave_dni%=cant;
            while(dni != L[clave_dni][0]){
                clave_dni++;
                clave_dni%=cant;
                if(clave_dni==max)
                {
                    break;
                    opc = -1;
                }
            }
            if(opc == 1){
                cout<<"La persona que tiene el dni "<<dni<<" es: "<<L[clave_dni][1]<<endl;
            }
            else{
                cout<<"No se encontro el dni\n";
            }
            break;
        
    

            default:
                cout<<"Ingrese otro valor";
                break;
        }
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
    int cant = sizeof(L) / sizeof(L[0]);
    mostrar(L, cant);
    Hash(L,cant);
    cout<<"\n\n\n";
    mostrar(L,cant);
    menu(L,cant);
}
