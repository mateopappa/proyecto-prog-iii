#ifndef ANALIZADOR_PARTIDOS_CPP
#define ANALIZADOR_PARTIDOS_CPP

#include "Partido.cpp"
#include <algorithm>

#include <limits>
#include <map>

std::vector<std::pair<std::string, int > > competicionesConMasGoles; // Vector para almacenar competiciones con más goles

class AnalizadorPartidos {
private:
    
    std::unordered_map<std::string, std::set<Partido> > partidosPorCompeticion;
    std::unordered_map<std::string, std::unordered_map<std::string, int > > golesAFavor;  // equipo -> competicion -> goles a favor
    std::unordered_map<std::string, std::unordered_map<std::string, int > > golesEnContra; // equipo -> competicion -> goles en contra

    std::unordered_map<std::string, std::unordered_map<std::string, double > > promedioGolesAFavor;  // competicion -> promedio de goles a favor
    std::unordered_map<std::string, std::unordered_map<std::string, double > > promedioGolesEnContra; // competicion -> promedio de goles en contra
    std::unordered_map<std::string, std::unordered_map<std::string, int > > partidosJugados; // equipo -> competicion -> total de partidos
    std::unordered_map<std::string, int> golesPorCompeticion; // competicion -> total de goles  
    std::unordered_map<std::string, std::unordered_map<std::string, int > > triunfos; // equipo -> competicion -> triunfos
    std::unordered_map<std::string, std::unordered_map<std::string, int > > derrotas; // equipo -> competicion -> derrotas
    std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_map<std::string, int > > > golesPorFecha; // equipo -> competicion -> (fecha -> goles)
    std::unordered_map<std::string, std::unordered_map<std::string, int > > golesPorEquipoPorCompeticion; // competición -> (equipo -> goles)


public:
std::unordered_map<std::string, std::set<Partido> > partidosPorEquipo;
  
    // Cargar partidos desde CSV
    void cargarPartidosDesdeCSV(const std::string& archivoCSV) {
    std::ifstream archivo(archivoCSV);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << archivoCSV << std::endl;
        return;
    }

    std::string linea;
    // Saltar cabecera
    std::getline(archivo, linea);

    while (std::getline(archivo, linea)) {
        size_t ultima_coma = linea.find_last_of(',');
        if (ultima_coma != std::string::npos) {
            std::string resto_linea = linea.substr(0, ultima_coma);
            std::string competicion = linea.substr(ultima_coma + 1);
            competicion.erase(0, competicion.find_first_not_of(" \t\n\r\f\v"));
            competicion.erase(competicion.find_last_not_of(" \t\n\r\f\v") + 1);
            
            std::istringstream ss(resto_linea);
            std::string jornada, fecha, equipoLocal, equipoVisitante;
            std::string golesLocalStr, golesVisitanteStr;
            int golesLocal, golesVisitante;
            
            std::getline(ss, jornada, ',');
            std::getline(ss, fecha, ',');
            std::getline(ss, equipoLocal, ',');
            std::getline(ss, golesLocalStr, ',');
            std::getline(ss, golesVisitanteStr, ',');
            std::getline(ss, equipoVisitante, ',');

            golesLocal = std::stoi(golesLocalStr);
            golesVisitante = std::stoi(golesVisitanteStr);

            Partido partido(jornada, fecha, equipoLocal, golesLocal, 
                          golesVisitante, equipoVisitante, competicion);

            partidosPorEquipo[equipoLocal].insert(partido);
            partidosPorEquipo[equipoVisitante].insert(partido);
            partidosPorCompeticion[competicion].insert(partido);

             if (golesLocal > golesVisitante) {
                triunfos[equipoLocal][competicion]++;
                derrotas[equipoVisitante][competicion]++;
            } else if (golesLocal < golesVisitante) {
                triunfos[equipoVisitante][competicion]++;
                derrotas[equipoLocal][competicion]++;
            }

            // Contar goles por fecha
            golesPorFecha[equipoLocal][competicion][fecha] += golesLocal;
            golesPorFecha[equipoVisitante][competicion][fecha] += golesVisitante;
            // Contar goles de equipo por competición
            golesPorEquipoPorCompeticion[competicion][equipoLocal] += golesLocal; // Actualizar goles del equipo local
            golesPorEquipoPorCompeticion[competicion][equipoVisitante] += golesVisitante; // Actualizar goles del equipo visitante
        }
    }
    }


    /*
     @brief Prepara los datos de goles por equipo y competición, como asi los promedios
     @param competicionesConMasGoles Vector donde se almacenarán las competiciones con más goles.
        @return void
        @note   Este método debe ser llamado después de cargar los partidos desde el archivo CSV para preparar los datos previo a la 
        consulta de goles por equipo y competición.
    
    */
    void prepararGolesYPromediosPorCompeticion(std::vector<std::pair<std::string, int > >& competicionesConMasGoles) {
    competicionesConMasGoles.clear();  // Limpiar el vector de competiciones con más goles
    golesPorCompeticion.clear();       // Limpiar el mapa de goles por competición para recalcular

    // Recorrer cada competición y sus partidos
    for (const auto& entry : partidosPorCompeticion) {
        const std::string& competicion = entry.first;
        const std::set<Partido>& partidos = entry.second;

        int totalGolesCompeticion = 0;  // Variable para acumular goles de la competición actual

        // Calcular goles en cada partido de la competición
        for (const auto& partido : partidos) {
            int golesLocal = partido.getGolesLocal();
            int golesVisitante = partido.getGolesVisitante();

            // Goles a favor y en contra para cada equipo en esta competición
            golesAFavor[partido.getEquipoLocal()][competicion] += golesLocal;
            golesEnContra[partido.getEquipoLocal()][competicion] += golesVisitante;
            golesAFavor[partido.getEquipoVisitante()][competicion] += golesVisitante;
            golesEnContra[partido.getEquipoVisitante()][competicion] += golesLocal;

            // Incrementar partidos jugados por equipo en esta competición
            partidosJugados[partido.getEquipoLocal()][competicion]++;
            partidosJugados[partido.getEquipoVisitante()][competicion]++;

            // Sumar al total de goles de la competición actual
            totalGolesCompeticion += golesLocal + golesVisitante;
        }

        // Guardar el total de goles de la competición en el mapa
        golesPorCompeticion[competicion] = totalGolesCompeticion;

        // // Para depuración: mostrar los goles acumulados para esta competición
        // std::cout << "Competición: " << competicion << ", Goles acumulados: " << totalGolesCompeticion << std::endl;
    }

    // Determinar la competición con la mayor cantidad de goles
    int maxGoles = 0;
    std::string competicionConMasGoles;

    for (const auto& entry : golesPorCompeticion) {
        if (entry.second > maxGoles) {
            maxGoles = entry.second;
            competicionConMasGoles = entry.first;
        }
    }

    // Almacenar el resultado en el vector si se encontró una competición con goles
    if (!competicionConMasGoles.empty()) {
        competicionesConMasGoles.emplace_back(competicionConMasGoles, maxGoles);
        // std::cout << "Competición con más goles: " << competicionConMasGoles << ", Total de goles: " << maxGoles << std::endl;
    }
}

// Goles por equipo y competición
   void golesPorEquipoYCompeticion(const std::string& equipo) {
    std::cout << "\nGoles de " << equipo << " por competición:\n";
    std::cout << "----------------------------------------\n";
    
    if (golesAFavor.find(equipo) == golesAFavor.end()) {
        std::cout << "No se encontraron estadísticas para el equipo: " << equipo << "\n";
        return;
    }

    for (const auto& comp : golesAFavor[equipo]) {
        std::cout << "Competición: " << comp.first << "\n"
                 << "  - Goles a favor: " << comp.second << "\n"
                 << "  - Goles en contra: " << golesEnContra[equipo][comp.first] << "\n";
    }
}



// Promedio de goles por equipo y competición(muy parecida a la anterior pero solo imprime promedio)
void golesPromedioPorEquipoYCompeticion(const std::string& equipo) {
 

    std::cout << "Analizando partidos para el equipo: " << equipo << std::endl;

    // Verificar si el equipo tiene partidos
    if (partidosPorEquipo.find(equipo) == partidosPorEquipo.end()) {
        std::cout << "No se encontraron partidos para este equipo." << std::endl;
        return;
    }

    

    // Imprimir resultados
    std::cout << "\nPromedio de goles de " << equipo << " por competición:\n";
    if (golesAFavor.empty()) {
        std::cout << "No hay estadísticas disponibles." << std::endl;
    }

    for (const auto& comp : golesAFavor[equipo]) {
        std::cout << "Competición: '" << comp.first << "'"  
                  << ", Promedio goles a favor: " << promedioGolesAFavor[equipo][comp.first]
                  << ", Promedio goles en contra: " << promedioGolesEnContra[equipo][comp.first] << "\n";
    }
}


    // Método para imprimir partidos de un equipo
    void imprimirPartidosEquipo(const std::string& equipo) {
        std::cout << "Partidos de " << equipo << ":\n";
        for (const auto& partido : partidosPorEquipo[equipo]) {
            partido.imprimirDetalles();
        }
    }
    // Método para imprimir partidos de una competición
    // void imprimirPartidosCompeticion(const std::string& competicion) {
    //     std::cout << "Partidos de " << competicion << ":\n";
    //     for (const auto& partido : partidosPorCompeticion[competicion]) {
    //         partido.imprimirDetalles();
    //     }
    // }   VER SI ES NECESARIO


/**
 * @brief Calcula los 5 partidos con más goles de cada competición y los guarda en un vector.
 *
 * Esta función recorre todos los partidos de cada competición y selecciona los primeros 5
 * partidos con más goles. Los detalles de estos partidos se almacenan en el vector proporcionado
 * por referencia, para luego ser mostrados en pantalla a voluntad del lector
 *
 * @param resultados Un vector donde se almacenarán los resultados de los partidos encontrados.
 *           Cada elemento del vector corresponde a una línea de texto con los detalles
 *
 * @note Esta función asume que el set de partidos por competición está ordenado por el total
 *       de goles. Si hay menos de 5 partidos en una competición, se almacenarán solo los disponibles.
 *  PUNTO 5.i
 * 
 *
 * @example
 * std::vector<std::string> resultados;
 * Top5PartidosPorCompeticion(resultados);
 * 
 */
    void Top5PartidosPorCompeticion(std::vector<std::string>& resultados) {
        resultados.clear();
    for (const auto& entry : partidosPorCompeticion) {
        const std::string& competicion = entry.first;
        const std::set<Partido>& partidos = entry.second;
        resultados.push_back("Top 5 partidos con más goles en la competición " + competicion + ":");

        

        // Iterar sobre los primeros 5 partidos del set
        int count = 0;
        for (const auto& partido : partidos) {
            if (count >= 5) break;

            int totalGoles = partido.getGolesLocal() + partido.getGolesVisitante();
           std::ostringstream partidoDetalles;  // Usamos un ostringstream para construir la cadena
            partidoDetalles << "Partido: " << partido.getEquipoLocal() << " " << partido.getGolesLocal() 
                            << " - " << partido.getGolesVisitante() << " " << partido.getEquipoVisitante()
                            << ", Total de goles: " << totalGoles;
            
            resultados.push_back(partidoDetalles.str());
            count++;
        }

        resultados.push_back(""); // Para un salto de línea entre competiciones
    }
}
    
    void mostrarTriunfosYDerrotasPorEquipo(const std::string& equipo) {
        std::cout << "Estadísticas de " << equipo << ":\n";
        
        if (triunfos.count(equipo) == 0) {
            std::cout << "No se encontraron estadísticas para el equipo: " << equipo << std::endl;
            return;
        }

        for (const auto& comp : triunfos[equipo]) {
            std::cout << "Competición: '" << comp.first 
                      << "', Triunfos: " << comp.second 
                      << ", Derrotas: " << derrotas[equipo][comp.first] << "\n";
        }
    }
    void mostrarGolesPorFechaPorEquipo(const std::string& equipo) {
        std::cout << "Goles por fecha de " << equipo << ":\n";

        if (golesPorFecha.count(equipo) == 0) {
            std::cout << "No se encontraron estadísticas para el equipo: " << equipo << std::endl;
            return;
        }

        for (const auto& comp : golesPorFecha[equipo]) {
            std::cout << "Competición: '" << comp.first << "'\n";

            std::string fechaMasGoles;
            std::string fechaMenosGoles;
            int maxGoles = std::numeric_limits<int>::min();
            int minGoles = std::numeric_limits<int>::max();

            for (const auto& fechaGoles : comp.second) {
                if (fechaGoles.second > maxGoles) {
                    maxGoles = fechaGoles.second;
                    fechaMasGoles = fechaGoles.first;
                }
                if (fechaGoles.second < minGoles) {
                    minGoles = fechaGoles.second;
                    fechaMenosGoles = fechaGoles.first;
                }
            }

            std::cout << "  Fecha con más goles: " << fechaMasGoles << " (" << maxGoles << " goles)\n";
            std::cout << "  Fecha con menos goles: " << fechaMenosGoles << " (" << minGoles << " goles)\n";
        }
    }
    void mostrarEquiposConMasYMenosGoles() {
        std::cout << "Equipos con más y menos goles por competición:\n";

        for (const auto& competicion : golesPorEquipoPorCompeticion) {
            const std::string& nombreCompeticion = competicion.first;
            const auto& equiposGoles = competicion.second;

            std::string equipoMasGoles;
            std::string equipoMenosGoles;
            int maxGoles = std::numeric_limits<int>::min();
            int minGoles = std::numeric_limits<int>::max();

            for (const auto& equipoGoles : equiposGoles) {
                const std::string& equipo = equipoGoles.first;
                int goles = equipoGoles.second;

                if (goles > maxGoles) {
                    maxGoles = goles;
                    equipoMasGoles = equipo;
                }
                if (goles < minGoles) {
                    minGoles = goles;
                    equipoMenosGoles = equipo;
                }
            }

            std::cout << "Competición: " << nombreCompeticion 
                      << ", Equipo con más goles: " << equipoMasGoles << " (" << maxGoles << " goles)" 
                      << ", Equipo con menos goles: " << equipoMenosGoles << " (" << minGoles << " goles)\n";
        }
    }

   bool eliminarPartido(const std::string& equipoLocal, const std::string& equipoVisitante, const std::string& competicion, const std::string& fecha) {
    // Crear una instancia de Partido con los datos para buscar
    Partido partidoEliminar("", fecha, equipoLocal, 0, 0, equipoVisitante, competicion);
    bool eliminado = false;


    // Buscar y eliminar el partido en el mapa partidosPorEquipo para equipoLocal y equipoVisitante
    auto itEquipoLocal = partidosPorEquipo.find(equipoLocal);
    if (itEquipoLocal != partidosPorEquipo.end()) {
        itEquipoLocal->second.erase(partidoEliminar);
        eliminado = true;
    }

    auto itEquipoVisitante = partidosPorEquipo.find(equipoVisitante);
    if (itEquipoVisitante != partidosPorEquipo.end()) {
        itEquipoVisitante->second.erase(partidoEliminar);
        eliminado = true;
    }

    // Buscar y eliminar el partido en el mapa partidosPorCompeticion
    auto itCompeticion = partidosPorCompeticion.find(competicion);
    if (itCompeticion != partidosPorCompeticion.end()) {
        itCompeticion->second.erase(partidoEliminar);
        eliminado = true;
    }

    // Actualizar las estadísticas de goles
    golesAFavor[equipoLocal][competicion] -= partidoEliminar.getGolesLocal();
    golesEnContra[equipoVisitante][competicion] -= partidoEliminar.getGolesLocal();
    golesAFavor[equipoVisitante][competicion] -= partidoEliminar.getGolesVisitante();
    golesEnContra[equipoLocal][competicion] -= partidoEliminar.getGolesVisitante();

    // Actualizar los promedios de goles
    promedioGolesAFavor[competicion][equipoLocal] -= partidoEliminar.getGolesLocal();
    promedioGolesEnContra[competicion][equipoVisitante] -= partidoEliminar.getGolesLocal();
    promedioGolesAFavor[competicion][equipoVisitante] -= partidoEliminar.getGolesVisitante();
    promedioGolesEnContra[competicion][equipoLocal] -= partidoEliminar.getGolesVisitante();

    // Actualizar el total de partidos jugados
    partidosJugados[equipoLocal][competicion]--;
    partidosJugados[equipoVisitante][competicion]--;

    // Actualizar el total de goles por competición
    golesPorCompeticion[competicion] -= (partidoEliminar.getGolesLocal() + partidoEliminar.getGolesVisitante());

    // Actualizar los triunfos y derrotas
    if (partidoEliminar.getGolesLocal() > partidoEliminar.getGolesVisitante()) {
        triunfos[equipoLocal][competicion]--;
        derrotas[equipoVisitante][competicion]--;
    } else if (partidoEliminar.getGolesLocal() < partidoEliminar.getGolesVisitante()) {
        triunfos[equipoVisitante][competicion]--;
        derrotas[equipoLocal][competicion]--;
    }

    // Actualizar los goles por fecha
    golesPorFecha[equipoLocal][competicion][fecha] -= partidoEliminar.getGolesLocal();
    golesPorFecha[equipoVisitante][competicion][fecha] -= partidoEliminar.getGolesVisitante();

    // Actualizar los goles por equipo y competición
    golesPorEquipoPorCompeticion[competicion][equipoLocal] -= partidoEliminar.getGolesLocal();
    golesPorEquipoPorCompeticion[competicion][equipoVisitante] -= partidoEliminar.getGolesVisitante();

    // Actualizar los promedios de goles
    promedioGolesAFavor[competicion][equipoLocal] = 
        static_cast<double>(golesAFavor[equipoLocal][competicion]) / partidosJugados[equipoLocal][competicion];
    promedioGolesEnContra[competicion][equipoVisitante] = 
        static_cast<double>(golesEnContra[equipoVisitante][competicion]) / partidosJugados[equipoVisitante][competicion];
        return eliminado;
}

// estas dos para el menu


std::vector<Partido> obtenerPartidosPorCompeticion(const std::string& competicion) {
    std::vector<Partido> partidosFiltrados;

    auto it = partidosPorCompeticion.find(competicion);
    if (it != partidosPorCompeticion.end()) {
        // Acceder a los partidos correspondientes a la competición
        for (const auto& partido : it->second) {
            partidosFiltrados.push_back(partido);
        }
    }

    return partidosFiltrados;
}

std::vector<Partido> obtenerPartidosPorEquipo(const std::string& equipo) {
    std::vector<Partido> partidosFiltrados;

    auto it = partidosPorEquipo.find(equipo);
    if (it != partidosPorEquipo.end()) {
        // Acceder a los partidos correspondientes al equipo
        for (const auto& partido : it->second) {
            partidosFiltrados.push_back(partido);
        }
    }

    return partidosFiltrados;
}

void agregarPartido(const std::string& jornada, const std::string& fecha, 
                                        const std::string& equipoLocal, const std::string& equipoVisitante,
                                        int golesLocal, int golesVisitante, const std::string& competicion) {
    // Crear una instancia temporal del partido a agregar
    Partido nuevoPartido(jornada, fecha, equipoLocal, golesLocal, golesVisitante, equipoVisitante, competicion);

    // Verificar si ya existe un partido similar en `partidosPorCompeticion`
    if (partidosPorCompeticion[competicion].find(nuevoPartido) != partidosPorCompeticion[competicion].end()) {
        std::cout << "El partido entre " << equipoLocal << " y " << equipoVisitante 
                  << " en " << competicion << " ya existe y no se agregará nuevamente.\n";
        return; // Salir si el partido ya existe
    }

    // Insertar en el mapa de partidos por equipo
    partidosPorEquipo[equipoLocal].insert(nuevoPartido);
    partidosPorEquipo[equipoVisitante].insert(nuevoPartido);

    // Insertar en el mapa de partidos por competición
    partidosPorCompeticion[competicion].insert(nuevoPartido);

    // Actualizar el conteo de goles a favor y en contra para cada equipo en la competición
    golesAFavor[equipoLocal][competicion] += golesLocal;
    golesEnContra[equipoLocal][competicion] += golesVisitante;
    golesAFavor[equipoVisitante][competicion] += golesVisitante;
    golesEnContra[equipoVisitante][competicion] += golesLocal;
    // Actualizar partidos jugados
    partidosJugados[equipoLocal][competicion]++;
    partidosJugados[equipoVisitante][competicion]++;

    // Actualizar los promedios de goles
    promedioGolesAFavor[competicion][equipoLocal] = 
        static_cast<double>(golesAFavor[equipoLocal][competicion]) / partidosJugados[equipoLocal][competicion];
    promedioGolesEnContra[competicion][equipoVisitante] = 
        static_cast<double>(golesEnContra[equipoVisitante][competicion]) / partidosJugados[equipoVisitante][competicion];

    

    // Actualizar los totales de goles por competición
    golesPorCompeticion[competicion] += golesLocal + golesVisitante;

    // Actualizar triunfos y derrotas
    if (golesLocal > golesVisitante) {
        triunfos[equipoLocal][competicion]++;
        derrotas[equipoVisitante][competicion]++;
    } else if (golesVisitante > golesLocal) {
        triunfos[equipoVisitante][competicion]++;
        derrotas[equipoLocal][competicion]++;
    }

    // Actualizar los goles por fecha
    golesPorFecha[equipoLocal][competicion][fecha] += golesLocal;
    golesPorFecha[equipoVisitante][competicion][fecha] += golesVisitante;

    // Actualizar goles por equipo y competición
    golesPorEquipoPorCompeticion[competicion][equipoLocal] += golesLocal;
    golesPorEquipoPorCompeticion[competicion][equipoVisitante] += golesVisitante;

    // Calcular promedios de goles
    // Asegurarse de que los partidos jugados no sean cero antes de calcular el promedio
    if (partidosJugados[equipoLocal][competicion] > 0) {
        promedioGolesAFavor[competicion][equipoLocal] = 
            static_cast<double>(golesAFavor[equipoLocal][competicion]) / partidosJugados[equipoLocal][competicion];
    }
    if (partidosJugados[equipoVisitante][competicion] > 0) {
        promedioGolesEnContra[competicion][equipoVisitante] = 
            static_cast<double>(golesEnContra[equipoVisitante][competicion]) / partidosJugados[equipoVisitante][competicion];
    }
}

void modificarPartido(const std::string& jornada, const std::string& fecha, 
                                          const std::string& equipoLocal, const std::string& equipoVisitante,
                                          int golesLocal, int golesVisitante, const std::string& competicion,
                                          const std::string& nuevaJornada, const std::string& nuevaFecha,
                                          const std::string& nuevoEquipoLocal, const std::string& nuevoEquipoVisitante,
                                          int nuevosGolesLocal, int nuevosGolesVisitante, const std::string& nuevaCompeticion) {
    // Crear una instancia del partido original para eliminarlo
    Partido partidoOriginal(jornada, fecha, equipoLocal, golesLocal, golesVisitante, equipoVisitante, competicion);

    // Intentar eliminar el partido original

    // eliminarPartido(const std::string& equipoLocal, const std::string& equipoVisitante, const std::string& competicion, const std::string& fecha) {
    bool eliminado = eliminarPartido(equipoLocal, equipoVisitante, competicion, fecha);
    if (!eliminado) {
        std::cout << "No se encontró el partido para modificar.\n";
        return; // Salir si el partido no existe
    }

    // Agregar el partido con los datos modificados
    agregarPartido(nuevaJornada, nuevaFecha, nuevoEquipoLocal, nuevoEquipoVisitante, nuevosGolesLocal, nuevosGolesVisitante, nuevaCompeticion);

    std::cout << "Partido modificado exitosamente.\n";
}



};



#endif // ANALIZADOR_PARTIDOS_CPP
