#include <Keypad.h>

// Définition de la taille du clavier
const byte ROWS = 4; 
const byte COLS = 3;

// Définition des touches
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

// Connexions des lignes et colonnes sur l'Arduino
byte rowPins[ROWS] = {9, 8, 7, 6}; // Lignes connectées aux broches 9,8,7,6
byte colPins[COLS] = {5, 4, 3};    // Colonnes connectées aux broches 5,4,3

// Création de l'objet Keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();

  if (key) { // Si une touche est appuyée
    Serial.println(key); // Affiche la touche dans le moniteur série
  }
}