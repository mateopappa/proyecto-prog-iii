#include <ctime>

#include <fstream>
// #include "ProcesamientoDeDatosDuranteLecturaArchivoCSV.cpp"
#include "consultasDinamicas.cpp"
// void ModificaciónDeDatosReprocesamiento() {
//     int opcion;
//     std::string jornada, fecha, equipoLocal, equipoVisitante, competicion;
//                 int golesLocal, golesVisitante;
                
//     do {
//         std::cout << "\n--- Menú de modificacion de datos ---\n";
//         std::cout << "1. Agregar un partido\n";
//         std::cout << "2. Modificar o eliminar un partido completo\n";
//         std::cout << "0. Volver al Menú Principal\n";
//         std::cout << "Seleccione una opción: ";
//         std::cin >> opcion;

//         switch (opcion) {
//             case 1:
//                 std::cout << "Ingrese los datos del partido a agregar:\n";
//                 // Recolección de datos para AgregarPartido
                
//                 // Validación de Jornada
//                 std::cout << "Jornada: ";
//                 std::cin >> jornada;
//                 while (std::cin.fail()) {
//                     std::cin.clear();
//                     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                     std::cout << "Entrada inválida. Intente nuevamente.\nJornada: ";
//                     std::cin >> jornada;
//                 }

//                 // Validación de Fecha
//                 std::cout << "Fecha: ";
//                 std::cin >> fecha;
//                 while (std::cin.fail()) {
//                     std::cin.clear();
//                     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                     std::cout << "Entrada inválida. Intente nuevamente.\nFecha: ";
//                     std::cin >> fecha;
//                 }

//                 // Validación de Equipo Local
//                 std::cout << "Equipo Local: ";
//                 std::cin >> equipoLocal;
//                 while (std::cin.fail()) {
//                     std::cin.clear();
//                     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                     std::cout << "Entrada inválida. Intente nuevamente.\nEquipo Local: ";
//                     std::cin >> equipoLocal;
//                 }

//                 // Validación de Goles Local
//                 std::cout << "Goles Local: ";
//                 std::cin >> golesLocal;
//                 while (std::cin.fail() || golesLocal < 0) {
//                     std::cin.clear();
//                     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                     std::cout << "Entrada inválida. Intente nuevamente.\nGoles Local (debe ser un número no negativo): ";
//                     std::cin >> golesLocal;
//                 }

//                 // Validación de Equipo Visitante
//                 std::cout << "Equipo Visitante: ";
//                 std::cin >> equipoVisitante;
//                 while (std::cin.fail()) {
//                     std::cin.clear();
//                     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                     std::cout << "Entrada inválida. Intente nuevamente.\nEquipo Visitante: ";
//                     std::cin >> equipoVisitante;
//                 }

//                 // Validación de Goles Visitante
//                 std::cout << "Goles Visitante: ";
//                 std::cin >> golesVisitante;
//                 while (std::cin.fail() || golesVisitante < 0) {
//                     std::cin.clear();
//                     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                     std::cout << "Entrada inválida. Intente nuevamente.\nGoles Visitante (debe ser un número no negativo): ";
//                     std::cin >> golesVisitante;
//                 }

//                 // Validación de Competición
//                 std::cout << "Competición: ";
//                 std::cin >> competicion;
//                 while (std::cin.fail()) {
//                     std::cin.clear();
//                     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                     std::cout << "Entrada inválida. Intente nuevamente.\nCompetición: ";
//                     std::cin >> competicion;
//                 }
                
                
//                 analizador.agregarPartido(jornada, fecha, equipoLocal, equipoVisitante,  golesLocal, golesVisitante,competicion);
//                 std::cout << "Partido agregado correctamente.\n";
//                 break;
           
//             case 2:
//                 std::cout << "Seleccione el criterio para buscar el partido a eliminar o modificar:\n";
//                 std::cout << "1. Por equipo\n";
//                 std::cout << "2. Por competición\n";
//                 int subOpcion;
//                 std::cin>>subOpcion;
//                 int opcionEliminarOModificar;
//                while (std::cin.fail() || (subOpcion != 1 && subOpcion != 2)) {
//                     std::cin.clear();
//                     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                     std::cout << "Entrada inválida. Seleccione 1 para 'Por equipo' o 2 para 'Por competición': ";
//                     std::cin >> subOpcion;
//                 }

//                 if (subOpcion == 1) {
//                     std::string equipo;
//                     std::cout << "Ingrese el nombre del equipo: ";
//                     std::cin.ignore(); // Ignorar el salto de línea pendiente
//                     getline(std::cin, equipo); // Permitir el ingreso de nombres con espacios
//                     // Obtener partidos del equipo
//                     std::vector<Partido> partidos = analizador.obtenerPartidosPorEquipo(equipo);
                    
//                     // Listar partidos
//                 std::cout << "Partidos encontrados:\n";
//                 for (size_t i = 0; i < partidos.size(); ++i) {
//                  std::cout << i + 1 << ". " << partidos[i].getFecha() << " - "
//                 << partidos[i].getEquipoLocal() << " (" << partidos[i].getGolesLocal() << ") vs " 
//                 << partidos[i].getEquipoVisitante() << " (" << partidos[i].getGolesVisitante() << ")" << std::endl;
//                  }

//                     std::cout << "Seleccione el número del partido a eliminar o modificar : ";
//                     int partidoSeleccionado;
//                     std::cin >> partidoSeleccionado;

//                     // Validación del índice
//                     if (partidoSeleccionado < 1 || partidoSeleccionado > partidos.size()|| std::cin.fail()) {
//                         std::cout << "Número de partido inválido.\n";
//                     } else {
//                         std::cout << "Seleccione la acción a realizar:\n";
//                         std::cout << "1. Modificar\n";
//                         std::cout << "2. Eliminar\n";
//                         std::cin >> opcionEliminarOModificar;
//                         while (std::cin.fail() || (opcionEliminarOModificar != 1 && opcionEliminarOModificar != 2)) {
//                             std::cin.clear();
//                             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                             std::cout << "Entrada inválida. Seleccione 1 para 'Modificar' o 2 para 'Eliminar': ";
//                             std::cin >> opcionEliminarOModificar;
//                         }   
//                         if (opcionEliminarOModificar == 1) {
//                             // Modificar el partido seleccionado
//                             std::cout << "Ingrese los nuevos datos del partido:\n";
//                             // Recolección de datos para AgregarPartido

//                             // Validación de Jornada
//                             std::cout << "Jornada: ";
//                             std::cin >> jornada;
//                             while (std::cin.fail()) {
//                                 std::cin.clear();
//                                 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                                 std::cout << "Entrada inválida. Intente nuevamente.\nJornada: ";
//                                 std::cin >> jornada;
//                             }

//                             // Validación de Fecha
//                             std::cout << "Fecha: ";
//                             std::cin >> fecha;
//                             while (std::cin.fail()) {
//                                 std::cin.clear();
//                                 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                                 std::cout << "Entrada inválida. Intente nuevamente.\nFecha: ";
//                                 std::cin >> fecha;
//                             }

//                             // Validación de Equipo Local
//                             std::cout << "Equipo Local: ";
//                             std::cin >> equipoLocal;
//                             while (std::cin.fail()) {
//                                 std::cin.clear();
//                                 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                                 std::cout << "Entrada inválida. Intente nuevamente.\nEquipo Local: ";
//                                 std::cin >> equipoLocal;
//                             }

//                             // Validación de Goles Local
//                             std::cout << "Goles Local: ";
//                             std::cin >> golesLocal;
//                             while (std::cin.fail() || golesLocal < 0) {
//                                 std::cin.clear();
//                                 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                                 std::cout << "Entrada inválida. Intente nuevamente.\nGoles Local (debe ser un número no negativo): ";
//                                 std::cin >> golesLocal;
//                             }

//                             // Validación de Equipo Visitante
//                             std::cout << "Equipo Visitante: ";
//                             std::cin >> equipoVisitante;
//                             while (std::cin.fail()) {
//                                 std::cin.clear();
//                                 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                                 std::cout << "Entrada inválida. Intente nuevamente.\nEquipo Visitante: ";
//                                 std::cin >> equipoVisitante;
//                             }

//                             // Validación de Goles Visitante
//                             std::cout << "Goles Visitante: ";
//                             std::cin >> golesVisitante;
//                             while (std::cin.fail() || golesVisitante < 0) {
//                                 std::cin.clear();
//                                 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                                 std::cout << "Entrada inválida. Intente nuevamente.\nGoles Visitante (debe ser un número no negativo): ";
//                                 std::cin >> golesVisitante;
//                             }
//                             std::cout<<"Competición: ";
//                             std::cin>>competicion;
//                             while (std::cin.fail()) {
//                                 std::cin.clear();
//                                 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                                 std::cout << "Entrada inválida. Intente nuevamente.\nCompetición: ";
//                                 std::cin >> competicion;
//                             }

//                             /*const std::string& jornada, const std::string& fecha, 
//                                           const std::string& equipoLocal, const std::string& equipoVisitante,
//                                           int golesLocal, int golesVisitante, const std::string& competicion,
//                                           const std::string& nuevaJornada, const std::string& nuevaFecha,
//                                           const std::string& nuevoEquipoLocal, const std::string& nuevoEquipoVisitante,
//                                           int nuevosGolesLocal, int nuevosGolesVisitante, const std::string& nuevaCompeticion */
//                         analizador.modificarPartido(partidos[partidoSeleccionado - 1].getJornada(),partidos[partidoSeleccionado - 1].getFecha(),partidos[partidoSeleccionado - 1].getEquipoLocal() ,partidos[partidoSeleccionado-1].getEquipoVisitante(),partidos[partidoSeleccionado - 1].getGolesLocal(),partidos[partidoSeleccionado - 1].getGolesVisitante(),partidos[partidoSeleccionado-1].getCompeticion(), jornada, fecha, equipoLocal, equipoVisitante,  golesLocal, golesVisitante,competicion);
//                         std::cout << "Partido modificado exitosamente.\n"; 
//                         } else if (opcionEliminarOModificar == 2) {
//                            // Eliminar el partido seleccionado
//                         analizador.eliminarPartido(partidos[partidoSeleccionado - 1].getEquipoLocal(), partidos[partidoSeleccionado-1].getEquipoVisitante(),partidos[partidoSeleccionado-1].getCompeticion(), partidos[partidoSeleccionado-1].getFecha() ); // -1 para ajustar indice
//                         std::cout << "Partido eliminado exitosamente.\n";
//                         }  
                        
//                     }
                    
//                 } else if (subOpcion == 2) {
//                     std::string competicion;
//                     std::cout << "Ingrese el nombre de la competición: ";
//                     std::cin.ignore(); // Ignorar el salto de línea pendiente
//                     getline(std::cin, competicion); // Permitir el ingreso de nombres con espacios
//                     // Obtener partidos de la competición
//                     std::vector<Partido> partidos = analizador.obtenerPartidosPorCompeticion(competicion);
                    
//                     // Listar partidos
//                     std::cout << "Partidos encontrados:\n";
//                     for (size_t i = 0; i < partidos.size(); ++i) {
//                         std::cout << i + 1 << ". " << partidos[i].getFecha() << " - "
//                              << partidos[i].getEquipoLocal() << " vs " 
//                              << partidos[i].getEquipoVisitante() << std::endl;
//                     }

//                     std::cout << "Seleccione el número del partido a eliminar o modificar : ";
//                     int partidoSeleccionado;
//                     std::cin >> partidoSeleccionado;


//                     // Validación del índice
//                     if (partidoSeleccionado < 1 || partidoSeleccionado > partidos.size()|| std::cin.fail()) {
//                         std::cout << "Número de partido inválido.\n";
//                     } else {
//                         std::cout << "Seleccione la acción a realizar:\n";
//                         std::cout << "1. Modificar\n";
//                         std::cout << "2. Eliminar\n";
//                         std::cin >> opcionEliminarOModificar;
//                         while (std::cin.fail() || (opcionEliminarOModificar != 1 && opcionEliminarOModificar != 2)) {
//                             std::cin.clear();
//                             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                             std::cout << "Entrada inválida. Seleccione 1 para 'Modificar' o 2 para 'Eliminar': ";
//                             std::cin >> opcionEliminarOModificar;
//                         }   
//                         if (opcionEliminarOModificar == 1) {
//                             // Modificar el partido seleccionado
//                             std::cout << "Ingrese los nuevos datos del partido:\n";
//                             // Recolección de datos para AgregarPartido

//                             // Validación de Jornada
//                             std::cout << "Jornada: ";
//                             std::cin >> jornada;
//                             while (std::cin.fail()) {
//                                 std::cin.clear();
//                                 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                                 std::cout << "Entrada inválida. Intente nuevamente.\nJornada: ";
//                                 std::cin >> jornada;
//                             }

//                             // Validación de Fecha
//                             std::cout << "Fecha: ";
//                             std::cin >> fecha;
//                             while (std::cin.fail()) {
//                                 std::cin.clear();
//                                 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                                 std::cout << "Entrada inválida. Intente nuevamente.\nFecha: ";
//                                 std::cin >> fecha;
//                             }

//                             // Validación de Equipo Local
//                             std::cout << "Equipo Local: ";
//                             std::cin >> equipoLocal;
//                             while (std::cin.fail()) {
//                                 std::cin.clear();
//                                 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                                 std::cout << "Entrada inválida. Intente nuevamente.\nEquipo Local: ";
//                                 std::cin >> equipoLocal;
//                             }

//                             // Validación de Goles Local
//                             std::cout << "Goles Local: ";
//                             std::cin >> golesLocal;
//                             while (std::cin.fail() || golesLocal < 0) {
//                                 std::cin.clear();
//                                 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                                 std::cout << "Entrada inválida. Intente nuevamente.\nGoles Local (debe ser un número no negativo): ";
//                                 std::cin >> golesLocal;
//                             }

//                             // Validación de Equipo Visitante
//                             std::cout << "Equipo Visitante: ";
//                             std::cin >> equipoVisitante;
//                             while (std::cin.fail()) {
//                                 std::cin.clear();
//                                 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                                 std::cout << "Entrada inválida. Intente nuevamente.\nEquipo Visitante: ";
//                                 std::cin >> equipoVisitante;
//                             }

//                             // Validación de Goles Visitante
//                             std::cout << "Goles Visitante: ";
//                             std::cin >> golesVisitante;
//                             while (std::cin.fail() || golesVisitante < 0) {
//                                 std::cin.clear();
//                                 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                                 std::cout << "Entrada inválida. Intente nuevamente.\nGoles Visitante (debe ser un número no negativo): ";
//                                 std::cin >> golesVisitante;
//                             }
//                             std::cout<<"Competición: ";
//                             std::cin>>competicion;
//                             while (std::cin.fail()) {
//                                 std::cin.clear();
//                                 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                                 std::cout << "Entrada inválida. Intente nuevamente.\nCompetición: ";
//                                 std::cin >> competicion;
//                             }
//                         analizador.modificarPartido(partidos[partidoSeleccionado - 1].getJornada(),partidos[partidoSeleccionado - 1].getFecha(),partidos[partidoSeleccionado - 1].getEquipoLocal() ,partidos[partidoSeleccionado-1].getEquipoVisitante(),partidos[partidoSeleccionado - 1].getGolesLocal(),partidos[partidoSeleccionado - 1].getGolesVisitante(),partidos[partidoSeleccionado-1].getCompeticion(), jornada, fecha, equipoLocal, equipoVisitante,  golesLocal, golesVisitante,competicion);
//                         std::cout << "Partido modificado exitosamente.\n"; 
//                         } else if (opcionEliminarOModificar == 2) {
//                            // Eliminar el partido seleccionado
//                         analizador.eliminarPartido(partidos[partidoSeleccionado - 1].getEquipoLocal(), partidos[partidoSeleccionado-1].getEquipoVisitante(),partidos[partidoSeleccionado-1].getCompeticion(), partidos[partidoSeleccionado-1].getFecha() ); // -1 para ajustar indice
//                         std::cout << "Partido eliminado exitosamente.\n";
//                         }  
                        
                    
//                     }
//                 }
//                 break;
//             case 0:
//                 std::cout << "Regresando al Menú Principal...\n";
//                 break;
//             default:
//                 std::cout << "Opción no válida. Intente nuevamente.\n";
//         }
//     } while (opcion != 0);
// }

// void ProcesamientoDeDatosDuranteLecturaArchivoCSV() {
//     int opcion;
//     AnalizadorPartidos analizador;
//     std::string equipo;
//     std::vector<std::string> top5Resultados;
    
//     do {
//         std::cout << "\n--- Menú de Gestión de Datos ---\n";
//         std::cout << "1. Los primeros 5 partidos con mayor cantidad de goles\n";
//         std::cout << "2. Los goles totales a favor y en contra de cada equipo por competición\n";
//         std::cout << "3. Promedio de goles a favor y en contra de cada equipo por competición\n";
//         std::cout << "4. La cantidad total de derrotas y de triunfos de cada equipo por competición\n";
//         std::cout << "5. La fecha con más goles y la fecha con menos goles de cada equipo por competición\n";
//         std::cout << "6. La competición con más goles convertidos\n";
//         std::cout << "7. El equipo con más goles convertidos y el equipo con menos goles convertidos de todas las competiciones y por competición\n";
//         std::cout << "0. Volver al Menú Principal\n";
//         std::cout << "Seleccione una opción: ";
//         std::cin >> opcion;

//         while (!(std::cin >> opcion)) {
//             std::cin.clear();
//             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//             std::cout << "Entrada inválida. Intente nuevamente.\nSeleccione una opción: ";
//         }

//         switch (opcion) {
//             case 1:
//                 analizador.Top5PartidosPorCompeticion(top5Resultados);
//                 for (const auto& resultado : top5Resultados) {
//                     std::cout << resultado << std::endl;
//                 }
//                 break;

//             case 2:
//                 std::cout << "Introduce el equipo para ver sus goles por competicion: ";
//                 while (!(std::cin >> equipo)) {
//                     std::cin.clear();
//                     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                     std::cout << "Entrada inválida. Intente nuevamente.\nIntroduce el equipo: ";
//                 }
//                 analizador.golesPorEquipoYCompeticion(equipo);
//                 break;

//             case 3:
//                 std::cout << "Introduce el nombre del equipo para ver su promedio de goles por competición: ";
//                 while (!(std::cin >> equipo)) {
//                     std::cin.clear();
//                     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                     std::cout << "Entrada inválida. Intente nuevamente.\nIntroduce el equipo: ";
//                 }
//                 analizador.golesPromedioPorEquipoYCompeticion(equipo);
//                 break;

//             case 4:
//                 std::cout << "Introduce el nombre del equipo para ver sus triunfos y derrotas: ";
//                 while (!(std::cin >> equipo)) {
//                     std::cin.clear();
//                     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                     std::cout << "Entrada inválida. Intente nuevamente.\nIntroduce el equipo: ";
//                 }
//                 analizador.mostrarTriunfosYDerrotasPorEquipo(equipo);
//                 break;

//             case 5:
//                 std::cout << "Introduce el nombre del equipo para ver sus goles por fecha: ";
//                 while (!(std::cin >> equipo)) {
//                     std::cin.clear();
//                     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                     std::cout << "Entrada inválida. Intente nuevamente.\nIntroduce el equipo: ";
//                 }
//                 analizador.mostrarGolesPorFechaPorEquipo(equipo);
//                 break;

//             case 6:
//                 if (!competicionesConMasGoles.empty()) {
//                     std::cout << "\nCompetición con más goles: " << competicionesConMasGoles[0].first
//                               << ", Total de goles: " << competicionesConMasGoles[0].second << std::endl;
//                 } else {
//                     std::cout << "No hay datos disponibles para las competiciones con más goles.\n";
//                 }
//                 break;

//             case 7:
//                 analizador.mostrarEquiposConMasYMenosGoles();
//                 break;

//             case 0:
//                 std::cout << "Regresando al Menú Principal...\n";
//                 break;

//             default:
//                 std::cout << "Opción no válida. Intente nuevamente.\n";
//         }
//     } while (opcion != 0);
// }


int main() {
    clock_t begin;

    std::cout << "Comenzando a medir Tiempo\n" << std::endl;

    begin = clock();
    // Cargar partidos desde un archivo CSV
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

        // Validación de entrada
        while (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Intente nuevamente.\nSeleccione una opción: ";
        }

        switch (opcion) {
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





    clock_t end = clock();

    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;

    std::cout << "Tardo en segundos" << elapsed_secs << "\n" << std::endl;
    return 0;
}
