#include <iostream>
#include <fstream>

using namespace std;
#include "mod_datos_proc.cpp"
// std::string toLowerCase(const std::string& str) {
//     std::string lowerStr = str;
//     std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
//     return lowerStr;
// }
bool esNombreEquipoValido(const std::string& nombre) {
    return !nombre.empty() && nombre.find_first_not_of(" \t\n\r") != std::string::npos;
}


void ProcesamientoDeDatosDuranteLecturaArchivoCSV() {
    int opcion;
    std::string equipo="";
    std::vector<std::string> top5Resultados;
    
    
    do {
        cout << "\n--- Menú de Gestión de Datos ---\n";
        cout << "1. Los primeros 5 partidos con mayor cantidad de goles\n";
        cout << "2. Los goles totales a favor y en contra de cada equipo por competición\n";
        cout << "3. Promedio de goles a favor y en contra de cada equipo por competición\n";
        cout << "4. La cantidad total de derrotas y de triunfos de cada equipo por competición\n";
        cout << "5. La fecha con más goles y la fecha con menos goles de cada equipo por competición\n";
        cout << "6. La competición con más goles convertidos\n";
        cout << "7. El equipo con más goles convertidos y el equipo con menos goles convertidos de todas las competiciones y por competición\n";
        cout << "0. Volver al Menú Principal\n";
        cout << "Seleccione una opción: ";


        while (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Intente nuevamente.\nSeleccione una opción: ";

        }

        switch (opcion) {

            case 1:
                analizador.Top5PartidosPorCompeticion(top5Resultados);
                for (const auto& resultado : top5Resultados) {
                    std::cout << resultado << std::endl;
                }
                break;

           case 2: {
    std::string equipo;
    std::cout << "\nIntroduce el equipo para ver sus goles por competición: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, equipo);
   // equipo = toLowerCase(equipo); // Convertir a minúsculas

    // Convertir el nombre del equipo a un formato estándar (opcional)
    // Eliminar espacios extras al inicio y final
    equipo.erase(0, equipo.find_first_not_of(" \t\n\r"));
    equipo.erase(equipo.find_last_not_of(" \t\n\r") + 1);

    if (!equipo.empty()|| cin.fail()) {

        analizador.golesPorEquipoYCompeticion(equipo);
    } else {

        std::cout << "Error: El nombre del equipo no puede estar vacío.\n";
    }
    
    std::cout << "\nPresione Enter para continuar...";
    std::cin.get();
    break;

}

     case 3: {
    std::string equipo; // Asegúrate de que esta variable esté definida
    std::cout << "Introduce el nombre del equipo para ver su promedio de goles por competición: ";

    // Limpiar el buffer antes de usar getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, equipo); // Usar getline para capturar el nombre completo
    // equipo = toLowerCase(equipo); // Convertir a minúsculas
    // Validación de la entrada
    while (equipo.empty()||cin.fail()) {

        std::cout << "Entrada inválida. Intente nuevamente.\nIntroduce el equipo: ";
        std::getline(std::cin, equipo);
    //   equipo = toLowerCase(equipo);
    }

    analizador.golesPromedioPorEquipoYCompeticion(equipo);
    break;
}

case 4: {
    std::string equipo; // Asegúrate de que esta variable esté definida
    std::cout << "Introduce el nombre del equipo para ver sus triunfos y derrotas: ";

    // Limpiar el buffer antes de usar getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, equipo); // Usar getline para capturar el nombre completo
   // equipo = toLowerCase(equipo);
    // Validación de la entrada
    while (equipo.empty()||cin.fail()) {
        
        std::cout << "Entrada inválida. Intente nuevamente.\nIntroduce el equipo: ";
        std::getline(std::cin, equipo);
      //  equipo = toLowerCase(equipo);
    }

    analizador.mostrarTriunfosYDerrotasPorEquipo(equipo);
    break;
}

case 5: {
    std::string equipo; // Asegúrate de que esta variable esté definida
    std::cout << "Introduce el nombre del equipo para ver sus goles por fecha: ";

    // Limpiar el buffer antes de usar getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, equipo); // Usar getline para capturar el nombre completo
    // equipo = toLowerCase(equipo);
    // Validación de la entrada
    while (equipo.empty()||cin.fail()) {

        std::cout << "Entrada inválida. Intente nuevamente.\nIntroduce el equipo: ";
        std::getline(std::cin, equipo);
      //  equipo = toLowerCase(equipo);
    }

    analizador.mostrarGolesPorFechaPorEquipo(equipo);
    break;
}



            case 6:
                if (!competicionesConMasGoles.empty()) {


                    std::cout << "\nCompetición con más goles: " << competicionesConMasGoles[0].first
                              << ", Total de goles: " << competicionesConMasGoles[0].second << std::endl;
                } else {


                    std::cout << "No hay datos disponibles para las competiciones con más goles.\n";
                }
                break;

            case 7:
                analizador.mostrarEquiposConMasYMenosGoles();
                break;

            case 0:
                std::cout << "Regresando al Menú Principal...\n";
                break;

            default:
                std::cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcion != 0);
}