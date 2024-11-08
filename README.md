[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/XeqyhYUe)
# Manual de Usuario

## Nombre del Programa: Sistema de Análisis de Partidos de Fútbol

### Introducción
Este programa permite analizar y procesar datos de partidos de fútbol desde un archivo CSV. Incluye funcionalidades para consultar estadísticas curiosas, gestionar partidos y realizar consultas dinámicas.

### Requisitos del Sistema
**Hardware:**
- Procesador de 2 GHz o superior.
- Al menos 4 GB de RAM.

**Software:**
- Sistema operativo: Windows, macOS o Linux.
- Compilador compatible con C++11 o superior (g++, Visual Studio, etc.).

### Guía de Uso

#### Menú Principal
Al iniciar el programa, verás el siguiente menú:


========================================
**Menú Principal**
1. Estadísticas Curiosas
2. Gestión de Partidos
3. Consultas Dinámicas
0. Salir

Seleccione una opción:

#### Opciones del Menú

**Estadísticas Curiosas:**
Al seleccionar esta opción, el programa ejecutará `ProcesamientoDeDatosDuranteLecturaArchivoCSV()` para mostrar un submenú con 7 opciones distintas interactivas más una opción para volver al menú principal.
1. Los primeros 5 partidos con mayor cantidad de goles.
2. Los goles totales a favor y en contra de cada equipo por competición.
3. Promedio de goles a favor y en contra de cada equipo por competición.
4. La cantidad total de derrotas y de triunfos de cada equipo por competición.
5. La fecha con más goles y la fecha con menos goles de cada equipo por competición.
6. La competición con más goles convertidos.
7. El equipo con más goles convertidos y el equipo con menos goles convertidos de todas las competiciones y por competición.
0. Volver al Menú Principal.

**Gestión de Partidos:**
Esta opción ejecuta `ModificacionDeDatosReprocesamiento()`, que te lleva a un submenú con 2 opciones y una opción para volver al menú principal.
1. Agregar un partido.
2. Modificar o eliminar un partido completo.
0. Volver al Menú Principal.

**Consultas Dinámicas:**
Al seleccionar esta opción, el programa llama a `ConsultasDinámicas()`, se abre un submenú de 5 opciones interactivas y una opción más para volver al menú principal donde puedes hacer consultas específicas sobre equipos, competiciones y fechas.
1. Todos los Resultados.
2. Resultados de un equipo entre dos fechas.
3. Comparación de rendimiento general.
4. Comparación de rendimiento particular.
5. Umbral.
0. Volver al Menú Principal.

**Salir:**
Al ingresar 0, el programa finaliza y muestra un mensaje de despedida.

### Formato de Entrada
En algunas opciones del menú, el usuario deberá ingresar el nombre de un equipo o bien el nombre de alguna competición. Es tarea del usuario, al menos hasta la próxima actualización, ingresarlos en el siguiente formato:

#### Competiciones
- Champions League
- Premier League
- LALIGA
- Bundesliga

#### Equipos
- FC Koln
- 1. FC Nurnberg
- 1. FSV Mainz 05
- AFC Bournemouth
- Ajax
- Anderlecht
- APOEL
- Arsenal FC
- Astana
- Aston Villa FC
- Athletic Club Bilbao
- Atletico Madrid
- Austria Wien
- Barcelona
- Basel
- BATE Borisov
- Bayer Leverkusen
- Bayern Munich
- Benfica
- Bor. Monchengladbach
- Borussia Dortmund
- Braga
- Burnley FC
- CA Osasuna
- Cardiff City FC
- Celtic
- Chelsea FC
- Cluj
- Crystal Palace FC
- CSKA Moskva
- Dinamo Zagreb
- Dynamo Kyiv
- Eintracht Braunschweig
- Eintracht Frankfurt
- Elche CF
- Equipo Local
- Everton FC
- FC Augsburg
- FC Ingolstadt 04
- FC Schalke 04
- Fortuna Dusseldorf
- Fulham FC
- Galatasaray
- Gent
- Getafe CF
- Granada CF
- Hamburger SV
- Hannover 96
- Hertha BSC
- Hull City AFC
- Juventus
- Kobenhavn
- Leicester City FC
- Levante UD
- Lille
- Liverpool FC
- Ludogorets
- Maccabi Tel Aviv
- Malaga CF
- Malmo
- Manchester City
- Manchester City FC
- Manchester United FC
- Maribor
- Milan
- Monaco
- Montpellier
- Napoli
- Newcastle United FC
- Nordsjælland
- Norwich City FC
- Olympiacos
- Olympique de Marseille
- Olympique Lyonnais
- Porto
- PSG
- PSV
- Queens Park Rangers FC
- Rayo Vallecano
- RC Celta Vigo
- RCD Espanyol
- RCD La Coruna
- RCD Mallorca
- Reading FC
- Real Betis
- Real Madrid
- Real Sociedad
- Real Valladolid CF
- Real Zaragoza
- Roma
- SC Freiburg
- SC Paderborn 07
- Sevilla FC
- Sevilla FC FC
- Shakhtar Donetsk
- Southampton FC
- Spartak Moskva
- Sporting de Portugal
- SpVgg Greuther Furth
- Steaua Bucuresti
- Stoke City FC
- Sunderland AFC
- SV Darmstadt 98
- Swansea City FC
- Tottenham Hotspur FC
- TSG 1899 Hoffenheim
- UD Almeria
- Valencia CF
- Valencia CF CF
- VfB Stuttgart
- Viktoria Plzen
- Villarreal CF
- Watford FC
- Werder Bremen
- West Bromwich Albion FC
- West Ham United FC
- Wigan Athletic FC
- Wolfsburg
- Zenit

Este manual cubre los aspectos esenciales para que los usuarios puedan utilizar el programa correctamente.
