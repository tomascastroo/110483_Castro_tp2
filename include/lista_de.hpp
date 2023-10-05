#ifndef LISTA_DE_HPP
#define LISTA_DE_HPP

#include <exception>
#include <cstdlib>
#include "nodo_de.hpp"

class lista_exception : public std::exception {
    // Excepcion especifica y exclusivamente para errores dentro de la lista.
    // Usar de la forma "throw lista_exception();" cuando una precondicion no se cumpla.

    // Ejemplo:
    //     if (condicion_de_error()){
    //         throw lista_exception();
    //     }
};

template<typename T>
class lista_de {
private:
    nodo_de<T>* primer_nodo;
    nodo_de<T>* ultimo_nodo;
    nodo_de<T>* cursor;
    // Nota: pueden no utilizar el indice. Estado inicial / no válido = -1.
    int indice_cursor;
    size_t cantidad_datos;

    // Pre: El indice debe ser menor que la cantidad de datos.
    // Post: Devuelve un puntero al nodo asociado al indice deseado.
    nodo_de<T>* obtener_nodo(size_t indice);

public:
    // Constructor.
    lista_de();

    // Pre: -
    // Post: Agrega el dato al final de la lista.
    void alta(T dato);

    // Pre: La lista no puede estar vacia.
    // Post: Elimina el ultimo dato.
    // NOTA: Considerar que se puede dar de baja el nodo cursor.
    // En tal caso, reiniciarlo al estado inicial.
    T baja();

    // Pre: El indice debe ser menor o igual que la cantidad de datos.
    // Post: Agrega el dato antes del dato en la posicion indicada.
    // Si el indice es igual a la cantidad de datos, simplemente agrega al final.
    void alta(T dato, size_t indice);

    // Pre: El indice debe ser menor que la cantidad de datos.
    // Post: Elimina el dato en la posicion indicada.
    // Si el indice es igual a la cantidad de datos - 1, simplemente elimina el ultimo dato.
    // NOTA: Considerar que se puede dar de baja el nodo cursor.
    // En tal caso, reiniciarlo al estado inicial.
    T baja(size_t indice);

    // Pre: La lista no puede estar vacia.
    // Post: Devuelve el primer dato en la lista.
    T primero();

    // Pre: La lista no puede estar vacia.
    // Post: Devuelve el último dato en la lista.
    T ultimo();

    // Pre: El indice debe ser menor que la cantidad de datos.
    // Post: Devuelve el dato en la posicion deseada.
    T elemento(size_t indice);

    // Pre: -
    // Post: Devuelve true si se puede avanzar (esto es, que el cursor no sea nullptr).
    bool puede_avanzar();

    // Pre: Se debe poder avanzar.
    // Post: Devuelve el dato del cursor actual y luego lo mueve una posición en la dirección deseada.
    T avanzar(bool siguiente);

    // Pre: -
    // Post: Reinicia el cursor al principio o al final, según lo indicado.
    // Si la lista está vacia, se reinicia el cursor al estado inicial
    // (esto es, cursor == nullptr e indice_cursor == -1).
    void reiniciar_cursor(bool principio);

    // Pre: -
    // Post: Devuelve la cantidad de datos de la lista.
    size_t tamanio();

    // Pre: -
    // Post: Devuelve true si la lista esta vacia (es decir, si no hay datos).
    bool vacio();

    // El constructor de copia está deshabilitado.
    lista_de(const lista_de& l) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const lista_de& l) = delete;

    // Destructor.
    ~lista_de();
};

#endif