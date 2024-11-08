#ifndef PARTIDO_H
#define PARTIDO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <string>

class Partido {
private:
    std::string jornada;
    std::string fecha;
    std::string equipoLocal;
    std::string equipoVisitante;
    int golesLocal;
    int golesVisitante;
    std::string competicion;
    public:
    // Constructor
    Partido(const std::string& jornada, const std::string& fecha,
            const std::string& equipoLocal, int golesLocal, 
            int golesVisitante, const std::string& equipoVisitante, 
            const std::string& competicion)
        : jornada(jornada), fecha(fecha), equipoLocal(equipoLocal), 
          equipoVisitante(equipoVisitante), golesLocal(golesLocal), 
          golesVisitante(golesVisitante), competicion(competicion) {}



    // Getters
    std::string getJornada() const { return jornada; }
    std::string getFecha() const { return fecha; }
    std::string getEquipoLocal() const { return equipoLocal; }
    std::string getEquipoVisitante() const { return equipoVisitante; }
    int getGolesLocal() const { return golesLocal; }
    int getGolesVisitante() const { return golesVisitante; }
    std::string getCompeticion() const { return competicion; }

    // Total de goles en el partido
    int getTotalGoles() const { return golesLocal + golesVisitante; }
  

    // Sobrecarga de operadores para ordenamiento
    bool operator<(const Partido& otro) const {
        // Criterio de ordenamiento: 
        // 1. Total de goles (descendente)
        // 2. Fecha (más reciente primero)
        if (getTotalGoles() != otro.getTotalGoles())
            return getTotalGoles() > otro.getTotalGoles();
        
        if (fecha != otro.fecha)
            return convertirFecha(fecha) > convertirFecha(otro.fecha);
        
    }

    int convertirFecha(const std::string &input) const {
    int day, month, year;

    // Extrae directamente el día, mes y año
    if (std::sscanf(input.c_str(), "%d/%d/%d", &day, &month, &year) != 3) {
        std::cerr << "Error al convertir la fecha: " << input << std::endl;
        return -1; // Manejar error de forma adecuada
    }

    // Convertir a formato YYYYMMDD
    return 10000 * year + 100 * month + day;
}
    // Método para imprimir detalles del partido
    void imprimirDetalles() const {
        std::cout << jornada << " - " << fecha << ": "
                  << equipoLocal << " " << golesLocal << " - " 
                  << golesVisitante << " " << equipoVisitante 
                  << "---" <<competicion << std::endl;
    }
};

#endif // PARTIDO_H