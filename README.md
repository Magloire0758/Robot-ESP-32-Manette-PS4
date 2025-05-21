# Robot-ESP-32-Manette-PS4
# 🚀 Robot ESP32 contrôlé avec une manette PS4 🎮

Ce projet consiste à piloter un robot à l'aide d'une carte **ESP32** connectée à une manette **PlayStation 4 (PS4)** en Bluetooth. Il s'agit d'un projet de robotique combinant **IoT**, **contrôle sans fil** et **programmation embarquée**.

## 🛠️ Matériel utilisé

- ESP32 DevKit v1
- Manette PS4 (Bluetooth)
- Moteurs DC ou servomoteurs (selon la version du robot)
- Pont en H (L298N ou autre)
- Batterie Li-ion 7.4V ou powerbank
- Châssis de robot à 4 roues
- Câbles Dupont, breadboard (optionnel)

## 📦 Librairies Arduino utilisées

- `PS4Controller.h` : pour connecter la manette PS4 via Bluetooth


## 🔧 Installation

1. Ouvre l’IDE Arduino.
2. Sélectionne la carte : `ESP32 Dev Module` (via **Outils > Type de carte**).
3. Installe les librairies nécessaires via le **Gestionnaire de bibliothèques**.
4. Clone ce dépôt ou copie le code dans ton IDE.
5. Connecte l'ESP32 au port USB et téléverse le programme.

## 🔗 Connexion Bluetooth avec PS4

- La première fois, appuie simultanément sur `Share` + `PS` jusqu'à ce que la LED clignote rapidement.
- L’ESP32 va automatiquement détecter et appairer la manette si l’adresse MAC est connue.
- Une fois connecté, la LED de la manette reste allumée.

## 🎮 Contrôles

| Bouton PS4 | Action sur le robot |
|------------|---------------------|
| Joystick gauche | Avancer / Reculer |
| Joystick droit  | Tourner gauche / droite |
| Croix / Rond    | Autres fonctions (ex. Freiner, Augmenter la vitesse) 
