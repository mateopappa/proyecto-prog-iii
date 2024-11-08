// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <unordered_map>
// #include <set>
// #include <string>
// #include "Partido.cpp"


// // Alias para un conjunto de partidos ordenado por fecha
// using ArbolPartidos = std::set<Partido>;

// // Mapa hash para almacenar partidos por equipo
// std::unordered_map<std::string, ArbolPartidos> partidosPorEquipo;


// // Función para cargar partidos desde un archivo CSV
// void cargarPartidosDesdeCSV(const std::string& archivo_csv) {
//     std::ifstream archivo(archivo_csv);
//     std::string linea;

//     if (!archivo.is_open()) {
//         std::cerr << "Error al abrir el archivo.\n";
//         return;
//     }

//     // Leer cada línea del archivo CSV
//     while (std::getline(archivo, linea)) {
//         std::istringstream s(linea);
//         Partido partido;
//         std::string campo;

//         // Leer y asignar cada campo
//         std::getline(s, campo, ',');
//         partido.jornada = std::stoi(campo);

//         std::getline(s, partido.equipo_local, ',');
//         std::getline(s, partido.equipo_visitante, ',');

//         std::getline(s, campo, ',');
//         partido.goles_local = std::stoi(campo);

//         std::getline(s, campo, ',');
//         partido.goles_visitante = std::stoi(campo);

//         std::getline(s, campo, ',');
//         partido.fecha = convertirFecha(campo); // Convertir la fecha a entero YYYYMMDD

//         std::getline(s, partido.competicion, ',');

//         // Insertar el partido para el equipo local y visitante
//         partidosPorEquipo[partido.equipo_local].insert(partido);
//         partidosPorEquipo[partido.equipo_visitante].insert(partido);

//     }

//     archivo.close();
// }