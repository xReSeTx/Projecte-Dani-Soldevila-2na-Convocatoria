Aquest projecte és només per a visualització acadèmica. No es permet l’ús, còpia, modificació ni distribució sense autorització expressa.

Pràctica 1 – Comunicació Serial USB amb ESP32 Objectiu

Aprendre a comunicar un ordinador amb un ESP32 mitjançant el port sèrie USB i controlar un LED amb ordres de text.

Descripció breu

L’ESP32 es comunica amb el Monitor Sèrie de l’ordinador utilitzant l’objecte Serial. L’usuari escriu ordres (ON o OFF) i l’ESP32 encén o apaga un LED i respon amb un missatge pel port sèrie. Les ordres ignoren majúscules i minúscules.

Funcionament

Inicialització del port sèrie USB a 115200 baud.

Enviament d’un missatge inicial indicant que el sistema està llest.

Lectura contínua de dades enviades des del Monitor Sèrie.

Processament de la línia rebuda.

Control del LED segons l’ordre:

ON → LED encès

OFF → LED apagat

Altres → ordre desconeguda (Comparació de cadenes ignorants majúscules/minúscules)

Enviament de la resposta al Monitor Sèrie.

Ordres disponibles

ON: encén el LED.

OFF: apaga el LED.

Gestió del projecte

Projecte GitHub tipus Kanban amb:

To do

Doing

Done

Cada tasca és un Issue etiquetat amb practica1.

En finalitzar una tasca: commit + Closes #issue.

Resultat esperat

El LED es controla correctament des del Monitor Sèrie, les ordres funcionen amb qualsevol combinació de majúscules i minúscules, i l’ESP32 mostra missatges confirmant cada acció.
