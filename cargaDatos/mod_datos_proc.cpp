#include <iostream>
#include <fstream>
#include "analizadorPartidos.cpp"
using namespace std;
AnalizadorPartidos analizador; 


// std::string toLowerCase(const std::string& str) {
//     std::string lowerStr = str;
//     std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
//     return lowerStr;
// }


void ModificacionDeDatosReprocesamiento() {

    int opcion;
    string jornada, fecha, equipoLocal, equipoVisitante, competicion;
                int golesLocal, golesVisitante;
                
    do {
        

        cout << "\n--- Menú de modificacion de datos ---\n";
        cout << "1. Agregar un partido\n";
        cout << "2. Modificar o eliminar un partido completo\n";
        cout << "0. Volver al Menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        

            case 1:
                cout << "Ingrese los datos del partido a agregar:\n";
                // Recolección de datos para AgregarPartido
                
                // Validación de Jornada
                cout << "Jornada: ";
                cin >> jornada;
                while (cin.fail()) {
        

                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Entrada inválida. Intente nuevamente.\nJornada: ";
                    cin >> jornada;
                }

                // Validación de Fecha
                cout << "Fecha: ";
                cin >> fecha;
                while (cin.fail()) {
        

                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Entrada inválida. Intente nuevamente.\nFecha: ";
                    cin >> fecha;
                }

                // Validación de Equipo Local
                cout << "Equipo Local: ";
                cin >> equipoLocal;
                while (cin.fail()) {
        

                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Entrada inválida. Intente nuevamente.\nEquipo Local: ";
                    cin >> equipoLocal;
                }

                // Validación de Goles Local
                cout << "Goles Local: ";
                cin >> golesLocal;
                while (cin.fail() || golesLocal < 0) {
        

                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Entrada inválida. Intente nuevamente.\nGoles Local (debe ser un número no negativo): ";
                    cin >> golesLocal;
                }

                // Validación de Equipo Visitante
                cout << "Equipo Visitante: ";
                cin >> equipoVisitante;
                while (cin.fail()) {
        

                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Entrada inválida. Intente nuevamente.\nEquipo Visitante: ";
                    cin >> equipoVisitante;
                }

                // Validación de Goles Visitante
                cout << "Goles Visitante: ";
                cin >> golesVisitante;
                while (cin.fail() || golesVisitante < 0) {
        

                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Entrada inválida. Intente nuevamente.\nGoles Visitante (debe ser un número no negativo): ";
                    cin >> golesVisitante;
                }

                // Validación de Competición
                cout << "Competición: ";
                cin >> competicion;
                while (cin.fail()) {
        

                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Entrada inválida. Intente nuevamente.\nCompetición: ";
                    cin >> competicion;
                }
                
                
                analizador.agregarPartido(jornada, fecha, equipoLocal, equipoVisitante,  golesLocal, golesVisitante,competicion);
                cout << "Partido agregado correctamente.\n";
                break;
           
            case 2:
                cout << "Seleccione el criterio para buscar el partido a eliminar o modificar:\n";
                cout << "1. Por equipo\n";
                cout << "2. Por competición\n";
                int subOpcion;
                cin>>subOpcion;
                int opcionEliminarOModificar;
               while (cin.fail() || (subOpcion != 1 && subOpcion != 2)) {
        

                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Entrada inválida. Seleccione 1 para 'Por equipo' o 2 para 'Por competición': ";
                    cin >> subOpcion;
                }

                if (subOpcion == 1) {
        

                    string equipo;
                    cout << "Ingrese el nombre del equipo: ";
                    cin.ignore(); // Ignorar el salto de línea pendiente
                    getline(cin, equipo);
                    while(cin.fail()||equipo.empty()){
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Entrada inválida. Intente nuevamente.\nIngrese el nombre del equipo: ";
                        cin >> equipo;
                    } // Permitir el ingreso de nombres con espacios
                    // Obtener partidos del equipo
                    vector<Partido> partidos = analizador.obtenerPartidosPorEquipo(equipo);
                    
                  // Listar partidos
            std::cout << "Partidos encontrados:\n";
            for (size_t i = 0; i < partidos.size(); ++i) {
            std::cout << i + 1 << ". " << partidos[i].getFecha() << " - "
              << partidos[i].getEquipoLocal() << " (" << partidos[i].getGolesLocal() << ") vs " 
              << partidos[i].getEquipoVisitante() << " (" << partidos[i].getGolesVisitante() << ")\n";
}

                    cout << "Seleccione el número del partido a eliminar o modificar : ";
                    int partidoSeleccionado;
                    cin >> partidoSeleccionado;

                    // Validación del índice
                    if (partidoSeleccionado < 1 || partidoSeleccionado > partidos.size()|| cin.fail()) {
                        cout << "Número de partido inválido.\n";
                    } else {
                        cout << "Seleccione la acción a realizar:\n";
                        cout << "1. Modificar\n";
                        cout << "2. Eliminar\n";
                        cin >> opcionEliminarOModificar;
                        while (cin.fail() || (opcionEliminarOModificar != 1 && opcionEliminarOModificar != 2)) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Entrada inválida. Seleccione 1 para 'Modificar' o 2 para 'Eliminar': ";
                            cin >> opcionEliminarOModificar;
                        }   
                        if (opcionEliminarOModificar == 1) {
                            // Modificar el partido seleccionado
                            cout << "Ingrese los nuevos datos del partido:\n";
                            // Recolección de datos para AgregarPartido

                            // Validación de Jornada
                            cout << "Jornada: ";
                            cin >> jornada;
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Entrada inválida. Intente nuevamente.\nJornada: ";
                                cin >> jornada;
                            }

                            // Validación de Fecha
                            cout << "Fecha: ";
                            cin >> fecha;
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Entrada inválida. Intente nuevamente.\nFecha: ";
                                cin >> fecha;
                            }

                            // Validación de Equipo Local
                            cout << "Equipo Local: ";
                            cin >> equipoLocal;
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Entrada inválida. Intente nuevamente.\nEquipo Local: ";
                                cin >> equipoLocal;
                            }

                            // Validación de Goles Local
                            cout << "Goles Local: ";
                            cin >> golesLocal;
                            while (cin.fail() || golesLocal < 0) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Entrada inválida. Intente nuevamente.\nGoles Local (debe ser un número no negativo): ";
                                cin >> golesLocal;
                            }

                            // Validación de Equipo Visitante
                            cout << "Equipo Visitante: ";
                            cin >> equipoVisitante;
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Entrada inválida. Intente nuevamente.\nEquipo Visitante: ";
                                cin >> equipoVisitante;
                            }

                            // Validación de Goles Visitante
                            cout << "Goles Visitante: ";
                            cin >> golesVisitante;
                            while (cin.fail() || golesVisitante < 0) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Entrada inválida. Intente nuevamente.\nGoles Visitante (debe ser un número no negativo): ";
                                cin >> golesVisitante;
                            }
                            cout<<"Competición: ";
                            cin>>competicion;
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Entrada inválida. Intente nuevamente.\nCompetición: ";
                                cin >> competicion;
                            }

                            /*const std::string& jornada, const std::string& fecha, 
                                          const std::string& equipoLocal, const std::string& equipoVisitante,
                                          int golesLocal, int golesVisitante, const std::string& competicion,
                                          const std::string& nuevaJornada, const std::string& nuevaFecha,
                                          const std::string& nuevoEquipoLocal, const std::string& nuevoEquipoVisitante,
                                          int nuevosGolesLocal, int nuevosGolesVisitante, const std::string& nuevaCompeticion */
                        analizador.modificarPartido(partidos[partidoSeleccionado - 1].getJornada(),partidos[partidoSeleccionado - 1].getFecha(),partidos[partidoSeleccionado - 1].getEquipoLocal() ,partidos[partidoSeleccionado-1].getEquipoVisitante(),partidos[partidoSeleccionado - 1].getGolesLocal(),partidos[partidoSeleccionado - 1].getGolesVisitante(),partidos[partidoSeleccionado-1].getCompeticion(), jornada, fecha, equipoLocal, equipoVisitante,  golesLocal, golesVisitante,competicion);
                        cout << "Partido modificado exitosamente.\n"; 
                        } else if (opcionEliminarOModificar == 2) {
                           // Eliminar el partido seleccionado
                        analizador.eliminarPartido(partidos[partidoSeleccionado - 1].getEquipoLocal(), partidos[partidoSeleccionado-1].getEquipoVisitante(),partidos[partidoSeleccionado-1].getCompeticion(), partidos[partidoSeleccionado-1].getFecha() ); // -1 para ajustar indice
                        cout << "Partido eliminado exitosamente.\n";
                        }  
                        
                    }
                    
                } else if (subOpcion == 2) {
                    string competicion;
                    cout << "Ingrese el nombre de la competición: ";
                    cin.ignore(); // Ignorar el salto de línea pendiente
                    getline(cin, competicion);
                    while(cin.fail()||competicion.empty()){
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Entrada inválida. Intente nuevamente.\nIngrese el nombre de la competición: ";
                        cin >> competicion;
                    } 
                    // Obtener partidos de la competición
                    vector<Partido> partidos = analizador.obtenerPartidosPorCompeticion(competicion);
                    
                    // Listar partidos
                std::cout << "Partidos encontrados:\n";
                for (size_t i = 0; i < partidos.size(); ++i) {
                std::cout << i + 1 << ". " << partidos[i].getFecha() << " - "
              << partidos[i].getEquipoLocal() << " (" << partidos[i].getGolesLocal() << ") vs " 
              << partidos[i].getEquipoVisitante() << " (" << partidos[i].getGolesVisitante() << ")\n";
}
                    cout << "Seleccione el número del partido a eliminar o modificar : ";
                    int partidoSeleccionado;
                    cin >> partidoSeleccionado;


                    // Validación del índice
                    if (partidoSeleccionado < 1 || partidoSeleccionado > partidos.size()|| cin.fail()) {
                        cout << "Número de partido inválido.\n";
                    } else {
                        cout << "Seleccione la acción a realizar:\n";
                        cout << "1. Modificar\n";
                        cout << "2. Eliminar\n";
                        cin >> opcionEliminarOModificar;
                        while (cin.fail() || (opcionEliminarOModificar != 1 && opcionEliminarOModificar != 2)) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Entrada inválida. Seleccione 1 para 'Modificar' o 2 para 'Eliminar': ";
                            cin >> opcionEliminarOModificar;
                        }   
                        if (opcionEliminarOModificar == 1) {
                            // Modificar el partido seleccionado
                            cout << "Ingrese los nuevos datos del partido:\n";
                            // Recolección de datos para AgregarPartido

                            // Validación de Jornada
                            cout << "Jornada: ";
                            cin >> jornada;
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Entrada inválida. Intente nuevamente.\nJornada: ";
                                cin >> jornada;
                            }

                            // Validación de Fecha
                            cout << "Fecha: ";
                            cin >> fecha;
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Entrada inválida. Intente nuevamente.\nFecha: ";
                                cin >> fecha;
                            }

                            // Validación de Equipo Local
                            cout << "Equipo Local: ";
                            cin >> equipoLocal;
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Entrada inválida. Intente nuevamente.\nEquipo Local: ";
                                cin >> equipoLocal;
                            }

                            // Validación de Goles Local
                            cout << "Goles Local: ";
                            cin >> golesLocal;
                            while (cin.fail() || golesLocal < 0) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Entrada inválida. Intente nuevamente.\nGoles Local (debe ser un número no negativo): ";
                                cin >> golesLocal;
                            }

                            // Validación de Equipo Visitante
                            cout << "Equipo Visitante: ";
                            cin >> equipoVisitante;
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Entrada inválida. Intente nuevamente.\nEquipo Visitante: ";
                                cin >> equipoVisitante;
                            }

                            // Validación de Goles Visitante
                            cout << "Goles Visitante: ";
                            cin >> golesVisitante;
                            while (cin.fail() || golesVisitante < 0) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Entrada inválida. Intente nuevamente.\nGoles Visitante (debe ser un número no negativo): ";
                                cin >> golesVisitante;
                            }
                            cout<<"Competición: ";
                            cin>>competicion;
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Entrada inválida. Intente nuevamente.\nCompetición: ";
                                cin >> competicion;
                            }

                            /*const std::string& jornada, const std::string& fecha, 
                                          const std::string& equipoLocal, const std::string& equipoVisitante,
                                          int golesLocal, int golesVisitante, const std::string& competicion,
                                          const std::string& nuevaJornada, const std::string& nuevaFecha,
                                          const std::string& nuevoEquipoLocal, const std::string& nuevoEquipoVisitante,
                                          int nuevosGolesLocal, int nuevosGolesVisitante, const std::string& nuevaCompeticion */
                        analizador.modificarPartido(partidos[partidoSeleccionado - 1].getJornada(),partidos[partidoSeleccionado - 1].getFecha(),partidos[partidoSeleccionado - 1].getEquipoLocal() ,partidos[partidoSeleccionado-1].getEquipoVisitante(),partidos[partidoSeleccionado - 1].getGolesLocal(),partidos[partidoSeleccionado - 1].getGolesVisitante(),partidos[partidoSeleccionado-1].getCompeticion(), jornada, fecha, equipoLocal, equipoVisitante,  golesLocal, golesVisitante,competicion);
                        cout << "Partido modificado exitosamente.\n"; 
                        } else if (opcionEliminarOModificar == 2) {
                           // Eliminar el partido seleccionado
                        analizador.eliminarPartido(partidos[partidoSeleccionado - 1].getEquipoLocal(), partidos[partidoSeleccionado-1].getEquipoVisitante(),partidos[partidoSeleccionado-1].getCompeticion(), partidos[partidoSeleccionado-1].getFecha() ); // -1 para ajustar indice
                        cout << "Partido eliminado exitosamente.\n";
                        }  
                        
                    
                    }
                }
                break;
            case 0:
                cout << "Regresando al Menú Principal...\n";
                break;
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcion != 0);
}