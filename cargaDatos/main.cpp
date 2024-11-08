#include <iostream>
#include <fstream>

// #include "ProcesamientoDeDatosDuranteLecturaArchivoCSV.cpp"
#include "consultasDinamicas.cpp"

int main() {
    // Archivo CSV con los partidos
    std::string archivoCSV = "../Base_Datos_COMA.csv";
    // cargar los partidos desde el archivo CSV
    analizador.cargarPartidosDesdeCSV(archivoCSV);
    analizador.prepararGolesYPromediosPorCompeticion(competicionesConMasGoles);

  
    int opcion;
    do {
        // Menú 
        cout << "\n========================================\n";
        cout << "            Menú Principal           \n";
        cout << "========================================\n";
        cout << "  1  Estadísticas Curiosas\n";
        cout << "  2  Gestión de Partidos\n";
        cout << "  3  Consultas Dinámicas\n";
        cout << "----------------------------------------\n";
        cout << "  0  Salir\n";
        cout << "========================================\n";
        cout << "Seleccione una opción: ";

        // contadorIf++;
        // Validación de entrada
        while (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Intente nuevamente.\nSeleccione una opción: ";
            // contadorIf++;
        }

        switch (opcion) {
            // contadorIf++;
            case 1:
                ProcesamientoDeDatosDuranteLecturaArchivoCSV();
                break;
            case 2:
                
                ModificacionDeDatosReprocesamiento();
                break;
            case 3:
                ConsultasDinámicas();
                break;
            case 0:
                cout << "\nGracias por usar el programa. ¡Hasta luego! 👋\n";
                break;
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcion != 0);

   



    return 0;
}
