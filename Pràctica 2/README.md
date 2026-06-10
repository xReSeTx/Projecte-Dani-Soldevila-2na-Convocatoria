

Objectiu
Crear un sistema que vigili les condicions d'una sala de servidors, automatitzant alertes basades en llindars de temperatura i llum, i permetent la consulta de dades en temps real via Serial.

Descripció breu
L'ESP32 llegeix dos sensors analògics: un LDR (lluminositat) i un LM35 (temperatura). Si la temperatura supera els 25°C s'encén un LED d'alerta. Si el LDR detecta llum, s'envia un avís de possible intrusió. L'usuari pot consultar l'estat del sistema o apagar el LED manualment mitjançant ordres de text pel Monitor Sèrie.


Ordres disponibles
- **STATUS**: mostra la temperatura actual i el nivell de llum.
- **LED_OFF**: apaga manualment el LED d'alerta.

Gestió del projecte
Projecte GitHub tipus Kanban amb:
- To do
- Doing
- Done


En finalitzar una tasca: commit + `Closes #issue`.

Resultat esperat
El sistema monitora en temps real la temperatura i la lluminositat de la sala, activa alertes automàtiques quan es superen els llindars, i respon correctament a les ordres STATUS i LED_OFF des del Monitor Sèrie.
