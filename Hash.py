
def Orden(L):
    # Pasamos los dni a una tupla
    tupla = []
    for i in range(len(L)):
        tupla += [L[i][0], L[i][1]]
    tupla = tuple(tupla)
    for i in range(len(L)):
        L[i][0] = ""
        L[i][1] = ""

    # tupla = ('1213141','asf','321321312','fddsf',...)

    lista = []
    for i in range(0, len(tupla), 2):
        dni = list(tupla[i])
        clave = 0
        for j in dni:
            clave += int(j)
        indice = clave % len(L)
        # Se empieza con Juan entonces el indice sera = 6
        lista += [tupla[i]]
        while True:
            indice = indice % len(L)
            if L[indice][0] == "":
                L[indice][0] = tupla[i]
                L[indice][1] = tupla[i+1]
                break
            else:
                indice += 1


def table(L):
    print("ÍNDICE\t  DNI\t\tNOMBRE")
    for i in range(len(L)):
        print(i, "\t", L[i][0], "\t", L[i][1])


def Menu(L):
    valor = 0
    while(valor != 4):
        print("\nMenú\n")
        print("1. Consultar por el DNI")
        print("2. Cambiar registro con DNI")
        print("3. Eliminar DNI")
        print("4. Salir")
        valor = int(input("Escriba la opcion: "))
        if valor == 4:
            break
        consulta = input("Ingrese el DNI: ")
        clave = 0
        for i in list(consulta):
            clave += int(i)
        clave = clave % len(L)
        maximo = clave
        if valor == 1:
            if consulta == L[clave][0]:
                indice = clave
            else:
                while consulta != L[clave % len(L)][0]:
                    clave += 1
                    if(clave == maximo + len(L)):
                        clave = -1
                        break
                indice = clave
            if indice == -1:
                print("No se encontro ese DNI, lo sentimos")
            else:
                print("La persona con ese DNI es: ", L[indice][1])
        elif valor == 2:
            if consulta == L[clave][0]:
                indice = clave
            else:
                while consulta != L[clave % len(L)][0]:
                    clave += 1
                    if(clave == maximo + len(L)):
                        clave = -1
                        break
                indice = clave
            if indice == -1:
                print("No se encontro ese DNI, lo sentimos")
            else:
                Nuevo_DNI = input("Escriba su nuevo DNI: ")
                Nuevo_Nombre = input("Escriba su nuevo nombre: ")
                L[indice][0], L[indice][1] = Nuevo_DNI, Nuevo_Nombre
                Orden(L)
                table(L)
        elif valor == 3:
            if consulta == L[clave][0]:
                indice = clave
            else:
                while consulta != L[clave % len(L)][0]:
                    clave += 1
                    if(clave == maximo + len(L)):
                        clave = -1
                        break
                indice = clave
            if indice == -1:
                print("No se encontro ese DNI, lo sentimos")
            else:
                L.remove(L[indice])
                Orden(L)
                table(L)
        print("\n")
        # Si se trabajara con n elementos


def Lista_DefinidaporUser():
    lista = []
    cant = int(input("Cantidad de personas: "))
    for i in range(cant):
        DNI = input("Ingrese su numero de DNI: ")
        Nombre = input("Ingrese su nombre: ")
        lista.append([DNI, Nombre])
    return lista


L = [['12345678', 'Juan'], ['96854326', 'María'],
     ['85215647', 'Rosa'], ['50247895', 'Pablo'], ['23659874', 'Federico'], ['86597545', 'Guadalupe'], ['23146385', 'Benito'], ['89756413', 'Carolina'], ['96445646', 'Charlie'], ['74520367', 'Donald']]

# Ordenarlo por HASH
Orden(L)
# Mostrarlo
table(L)
# MENU
print("\n")
Menu(L)

# Definidas por el usuario
print("\n\n Lista Definida por el Usuario\n")
lista_def = Lista_DefinidaporUser()
Orden(lista_def)
table(lista_def)
Menu(lista_def)
