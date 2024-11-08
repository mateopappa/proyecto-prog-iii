#include <iostream>
#include "ProcesamientoDeDatosDuranteLecturaArchivoCSV.cpp"


using namespace std;


// Función para mostrar todos los partidos de un equipo en una competición específica
void consultaResultadosEquipoCompeticion(const string& equipo, const string& competicion) {
    bool partidosEncontrados = false;
    cout << "Resultados de " << equipo << " en la competición " << competicion << ":\n";

    for (const auto& partido : analizador.partidosPorEquipo[equipo]) {
        if (partido.getCompeticion() == competicion) {
            partido.imprimirDetalles();
            partidosEncontrados = true;
        }
    }

    if (!partidosEncontrados) {
        cout << "No existen partidos para el equipo " << equipo << " en la competición " << competicion << ".\n";
    }
}

// Resto de funciones de consulta (ya definidas en versiones anteriores) aquí...
// b. Resultados de un equipo entre dos fechas
void consultaResultadosEntreFechas(const string& equipo, const string& fechaInicio, const string& fechaFin) {
    bool partidosEncontrados = false;

    for (const auto& partido : analizador.partidosPorEquipo[equipo]) {
        auto fechaPartido = partido.convertirFecha(partido.getFecha());
        if (fechaPartido >= partido.convertirFecha(fechaInicio) && fechaPartido <= partido.convertirFecha(fechaFin)) {
            cout << partido.getEquipoLocal() << " " << partido.getFecha() << " " << partido.getGolesLocal() << " a "
                 << partido.getGolesVisitante() << " con " << partido.getEquipoVisitante() << " en " << partido.getCompeticion() << endl;
            partidosEncontrados = true;
        }
    }

    if (!partidosEncontrados) {
        cout << "No existen partidos para el equipo " << equipo << " entre las fechas " << fechaInicio << " y " << fechaFin << ".\n";
    }
}

// c. Comparación de rendimiento general entre dos equipos
void comparacionRendimientoGeneral(const string& equipo1, const string& equipo2) {
    unordered_map<string, pair<int, int > > rendimientoEquipo1, rendimientoEquipo2;

    for (const auto& partido : analizador.partidosPorEquipo[equipo1]) {
        auto& goles = rendimientoEquipo1[partido.getCompeticion()];
        if (partido.getEquipoLocal() == equipo1) {
            goles.first += partido.getGolesLocal();
            goles.second += partido.getGolesVisitante();
        } else {
            goles.first += partido.getGolesVisitante();
            goles.second += partido.getGolesLocal();
        }
    }

    for (const auto& partido : analizador.partidosPorEquipo[equipo2]) {
        auto& goles = rendimientoEquipo2[partido.getCompeticion()];
        if (partido.getEquipoLocal() == equipo2) {
            goles.first += partido.getGolesLocal();
            goles.second += partido.getGolesVisitante();
        } else {
            goles.first += partido.getGolesVisitante();
            goles.second += partido.getGolesLocal();
        }
    }

    if (rendimientoEquipo1.empty() || rendimientoEquipo2.empty()) {
        cout << "No existen datos suficientes para comparar el rendimiento general entre " << equipo1 << " y " << equipo2 << ".\n";
        return;
    }

    cout << equipo1 << " en competiciones:\n";
    for (const auto& [competicion, goles] : rendimientoEquipo1) {
        cout << competicion << " - Goles a favor: " << goles.first << " Goles en contra: " << goles.second << endl;
    }

    cout << equipo2 << " en competiciones:\n";
    for (const auto& [competicion, goles] : rendimientoEquipo2) {
        cout << competicion << " - Goles a favor: " << goles.first << " Goles en contra: " << goles.second << endl;
    }
}

// d. Comparación de rendimiento entre dos equipos
void comparacionRendimientoParticular(const string& equipo1, const string& equipo2) {
    int empates = 0, victoriasEquipo1 = 0, victoriasEquipo2 = 0;
    bool partidosEncontrados = false;

    for (const auto& partido : analizador.partidosPorEquipo[equipo1]) {
        if ((partido.getEquipoLocal() == equipo1 && partido.getEquipoVisitante() == equipo2) ||
            (partido.getEquipoLocal() == equipo2 && partido.getEquipoVisitante() == equipo1)) {
            partidosEncontrados = true;
            if (partido.getGolesLocal() == partido.getGolesVisitante()) {
                empates++;
            } else if ((partido.getEquipoLocal() == equipo1 && partido.getGolesLocal() > partido.getGolesVisitante()) ||
                       (partido.getEquipoVisitante() == equipo1 && partido.getGolesVisitante() > partido.getGolesLocal())) {
                victoriasEquipo1++;
            } else {
                victoriasEquipo2++;
            }
        }
    }

    if (!partidosEncontrados) {
        cout << "No existen partidos entre " << equipo1 << " y " << equipo2 << ".\n";
        return;
    }

    cout << "Partidos jugados entre " << equipo1 << " y " << equipo2 << ":\n";
    cout << "Empates: " << empates << ", Victorias de " << equipo1 << ": " << victoriasEquipo1
         << ", Victorias de " << equipo2 << ": " << victoriasEquipo2 << endl;
}

// e. Filtrar equipos por umbral de goles promedio
void filtrarEquiposPorUmbral(int umbral, bool porEncima) {
    unordered_map<string, pair<int, int > > golesPorEquipo;
    bool equiposEncontrados = false;

    for (const auto& [equipo, partidos] : analizador.partidosPorEquipo) {
        for (const auto& partido : partidos) {
            golesPorEquipo[equipo].first += partido.getTotalGoles();
            golesPorEquipo[equipo].second++;
        }
    }

    cout << "Equipos con promedio de goles " << (porEncima ? "por encima" : "por debajo") << " de " << umbral << ":\n";
    for (const auto& [equipo, goles] : golesPorEquipo) {
        double promedio = static_cast<double>(goles.first) / goles.second;
        if ((porEncima && promedio >= umbral) || (!porEncima && promedio <= umbral)) {
            cout << equipo << " con " << promedio << " goles promedio por partido" << endl;
            equiposEncontrados = true;
        }
    }

    if (!equiposEncontrados) {
        cout << "No existen equipos con promedio de goles " << (porEncima ? "por encima" : "por debajo")
             << " del umbral de " << umbral << ".\n";
    }
}