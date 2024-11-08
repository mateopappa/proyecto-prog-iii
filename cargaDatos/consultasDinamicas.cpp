using namespace std;
#include "consulta.cpp"
#include <regex>

bool validarFecha(const string& fecha) {
    // Verifica si la fecha cumple con el formato dd/mm/yyyy usando una expresión regular
    regex formatoFecha("\\d{2}/\\d{2}/\\d{4}");
    return regex_match(fecha, formatoFecha);
}

void ConsultasDinámicas() {
    int opcion;
    do {
        cout << "\n--- Menú de Consultas Dinamicas ---\n";
        cout << "1. Todos los Resultados\n";
        cout << "2. Resultados de un equipo entre dos fechas\n";
        cout << "3. Comparación de rendimiento general\n";
        cout << "4. Comparación de rendimiento particular\n";
        cout << "5. Umbral\n";
        cout << "0. Volver al Menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
    std::string equipo, competicion;

    std::cout << "Ingrese el nombre del equipo: ";
    std::cin.ignore();  // Limpiar cualquier salto de línea pendiente en el buffer
    std::getline(std::cin, equipo);
    while (equipo.empty()) {  // Validación para que no esté vacío
        std::cout << "Entrada inválida. Intente nuevamente.\nIngrese el nombre del equipo: ";
        std::getline(std::cin, equipo);
    }

    std::cout << "Ingrese el nombre de la competición: ";
    std::getline(std::cin, competicion);
    while (competicion.empty()) {  // Validación para que no esté vacío
        std::cout << "Entrada inválida. Intente nuevamente.\nIngrese el nombre de la competición: ";
        std::getline(std::cin, competicion);
    }

    consultaResultadosEquipoCompeticion(equipo, competicion);
    break;
}
          case 2: {
    std::string equipo, fechaInicio, fechaFin;

    std::cout << "Ingrese el nombre del equipo: ";
    std::cin.ignore();  // Limpiar el buffer de entrada
    std::getline(std::cin, equipo);
    while (equipo.empty()) {  // Validación para que no esté vacío
        std::cout << "Entrada inválida. Intente nuevamente.\nIngrese el nombre del equipo: ";
        std::getline(std::cin, equipo);
    }

    // Validación de la fecha de inicio
    std::cout << "Ingrese la fecha de inicio (dd/mm/yyyy): ";
    std::getline(std::cin, fechaInicio);
    while (fechaInicio.empty() || !validarFecha(fechaInicio)) {
        std::cout << "Error: La fecha debe tener el formato dd/mm/yyyy.\nIngrese la fecha de inicio: ";
        std::getline(std::cin, fechaInicio);
    }

    // Validación de la fecha de fin
    std::cout << "Ingrese la fecha de fin (dd/mm/yyyy): ";
    std::getline(std::cin, fechaFin);
    while (fechaFin.empty() || !validarFecha(fechaFin)) {
        std::cout << "Error: La fecha debe tener el formato dd/mm/yyyy.\nIngrese la fecha de fin: ";
        std::getline(std::cin, fechaFin);
    }

    consultaResultadosEntreFechas(equipo, fechaInicio, fechaFin);
    break;
}


     case 3: {
    std::string equipo1, equipo2;

    std::cout << "Ingrese el primer equipo: ";
    std::cin.ignore();
    std::getline(std::cin, equipo1);
    while (equipo1.empty()) {
        std::cout << "Entrada inválida. Intente nuevamente.\nIngrese el primer equipo: ";
        std::getline(std::cin, equipo1);
    }

    std::cout << "Ingrese el segundo equipo: ";
    std::getline(std::cin, equipo2);
    while (equipo2.empty()) {
        std::cout << "Entrada inválida. Intente nuevamente.\nIngrese el segundo equipo: ";
        std::getline(std::cin, equipo2);
    }

    comparacionRendimientoGeneral(equipo1, equipo2);
    break;
}
           case 4: {
    std::string equipo1, equipo2;

    std::cout << "Ingrese el primer equipo: ";
    std::cin.ignore();
    std::getline(std::cin, equipo1);
    while (equipo1.empty()) {
        std::cout << "Entrada inválida. Intente nuevamente.\nIngrese el primer equipo: ";
        std::getline(std::cin, equipo1);
    }

    std::cout << "Ingrese el segundo equipo: ";
    std::getline(std::cin, equipo2);
    while (equipo2.empty()) {
        std::cout << "Entrada inválida. Intente nuevamente.\nIngrese el segundo equipo: ";
        std::getline(std::cin, equipo2);
    }

    comparacionRendimientoParticular(equipo1, equipo2);
    break;
}

          case 5: {
    double umbral;
    bool sobre;

    std::cout << "Ingrese el umbral de goles: ";
    std::cin >> umbral;

    std::cout << "¿Desea ver los equipos con promedio por encima del umbral? (1 = Sí, 0 = No): ";
    std::cin >> sobre;
    while (std::cin.fail()) {  // Validación para que la entrada sea correcta
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada inválida. Intente nuevamente.\n¿Desea ver los equipos con promedio por encima del umbral? (1 = Sí, 0 = No): ";
        std::cin >> sobre;
    }

    filtrarEquiposPorUmbral(umbral, sobre);
    break;
}

            case 0:
                cout << "Regresando al Menú Principal...\n";
                break;
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcion != 0);
}