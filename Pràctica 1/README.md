
Pràctica 1 – Comunicació Serial USB amb ESP32 Objectiu


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


Enviament de la resposta al Monitor Sèrie.

Ordres disponibles

ON: encén el LED.

OFF: apaga el LED.

Gestió del projecte


Resultat esperat

El LED es controla correctament des del Monitor Sèrie, les ordres funcionen amb qualsevol combinació de majúscules i minúscules, i l’ESP32 mostra missatges confirmant cada acció.
