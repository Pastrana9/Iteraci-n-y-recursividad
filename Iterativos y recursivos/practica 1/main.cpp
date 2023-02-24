// Practica 1 
// Manuel Pastrana y Carlos Bauluz

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int menu ();
int solicitarNumero();
int restoDivisionEntera(int dividendo, int divisor);
int sumarDivisores(int numero, int divisor) ;
void mostrarVector(vector<int> const& v);
int totalVecesITER(vector<int> const& v, int numero);
int totalVecesREC(vector<int> vec, int num, int pos);
vector<int> solicitarDatosVector();

int main()
{
    const int OPCIONES{5};
    
    int opcion,dividendo,divisor,temp,resto;
    int numero,suma;
    int total;
    int num,veces;
    vector <int> v;
    vector <int> vec;

    do {
         opcion = menu();

         switch (opcion) {

         //ejercicio 1
         //-----------------------------------------------------------------------------------------------
         case 1:

             dividendo = solicitarNumero();
             divisor = solicitarNumero();
             if (dividendo < divisor) {
                 temp = dividendo;
                 dividendo = divisor;
                 divisor = temp;
             }
             resto = restoDivisionEntera(dividendo, divisor);
             std::cout << "\tEl resto de la división de " << dividendo << " y " << divisor << " es " << resto << std::endl;

            break;
         
         //ejercicio 2
         //-----------------------------------------------------------------------------------------------
         case 2:
             numero = solicitarNumero();
             cout << "\tLos divisores del número " << numero << " son: ";
             suma = sumarDivisores(numero,1);
             cout << endl << "\tLa suma de los divisores es: " << suma << endl;
            break;

         //ejercicio 3
         //-----------------------------------------------------------------------------------------------
         case 3:
             v = solicitarDatosVector();
             numero = solicitarNumero();
             mostrarVector(v);
             total = totalVecesITER(v, numero);
             cout << "\tEl número " << numero << " se encuentra " << total << " veces." << endl;

            cout << "\n\n\n";

            break;

         //ejercicio 4
         //-----------------------------------------------------------------------------------------------
         case 4:
             vec = solicitarDatosVector();
             num = solicitarNumero();
             veces = totalVecesREC(vec, num, 0);
               mostrarVector(vec);
               cout << "\tEl número " << num << " aparece " << veces << " veces." << endl;

            cout << "\n\n\n";

            break;

         case 5: cout << "\n\n\tGracias y hasta pronto";
                  break;
         default: cout << "\n\n\tLa opción no es valida. Por favor, vuelva a seleccionar otra opción" << endl << endl;
        }

    } while (opcion != OPCIONES);


    cout << "\n\n\t";
    return 0;
}

//funcion menu
//--------------------------------------------------------------------------------------------------------
int menu ()
{   const int OPCIONES{5};
    int miOpcion;

    do {
        cout << "\n   --------------------------------------------------------------------------------------";
        cout << "\n   |  1  | Calcular el resto de la división entera de dos números de forma recursiva    |";
        cout << "\n   |-----|------------------------------------------------------------------------------|";
        cout << "\n   |  2  | Calcular la suma de los divisores de un número de forma recursiva.           |";
        cout << "\n   |-----|------------------------------------------------------------------------------|";
        cout << "\n   |  3  | Determinar cuántas veces está un valor en un vector de forma iterativa       |";
        cout << "\n   |-----|------------------------------------------------------------------------------|";
        cout << "\n   |  4  | Determinar cuántas veces está un valor en un vector de forma recursiva.      |";
        cout << "\n   |-----|------------------------------------------------------------------------------|";
        cout << "\n   |  5  | Salir del Programa.                                                          |";
        cout << "\n   --------------------------------------------------------------------------------------";
        cout << "\n\n\tSelecciona una opción: ";
        cin >> miOpcion;
        cin.ignore();

        if (miOpcion < 1 || miOpcion > OPCIONES)
            cout << "\n\n\tLa opcion no es valida. Por favor, vuelva a seleccionar otra opcion" << endl << endl;

    } while (miOpcion < 1 || miOpcion > OPCIONES);

    return miOpcion;
}

//funciones ejercicios
//--------------------------------------------------------------------------------------------------------
int solicitarNumero() {
    int numero;
    std::cout << "\tIntroduce un número entero positivo: ";
    std::cin >> numero;
    while (numero <= 0) {
        std::cout << "\tEl número introducido no es válido. Introduce un número entero positivo: ";
        std::cin >> numero;
    }
    return numero;
}

int restoDivisionEntera(int dividendo, int divisor) {
    if (dividendo < divisor) {
        return dividendo;
    }
    return restoDivisionEntera(dividendo - divisor, divisor);
}

int sumarDivisores(int numero, int divisor = 1) {
    if (divisor > numero) {
        return 0;
}
    if (numero % divisor == 0) {
        cout << divisor << " ";
        return divisor + sumarDivisores(numero, divisor + 1);
}
    return sumarDivisores(numero, divisor + 1);
}

vector<int> solicitarDatosVector() {
    int tam;
        cout << "\tIntroduce la cantidad de números que desea que contenga el vector: ";
        cin >> tam;
vector<int> v(tam);
        cout << "\tIntroduce los números deseados: ";
for (int i = 0; i < tam; i++) {
        cin >> v[i];
    }
return v;
}

void mostrarVector(vector<int> const& v) {
        cout << "\tNumeros contenidos en el vector: ";
for (unsigned int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}
cout << endl;
}

int totalVecesITER(vector<int> const& v, int numero) {
int total = 0;
    
for (unsigned int i = 0; i < v.size(); i++) {
    if (v[i] == numero) {
total++;
    }
}
return total;
}

int totalVecesREC(vector<int> vec, int num, int pos) {
  if (pos == vec.size()) return 0;
  if (vec[pos] == num) return 1 + totalVecesREC(vec, num, pos + 1);
  return totalVecesREC(vec, num, pos + 1);
}
