// AuFs 1  4/7/2023
//cliente: andre
//Projeto: Restaurante super herois
const int inputPin = 2;    // SENSOR
const int ledPins[] = {3, 5, 6, 9, 10};  // LEDS
const int relayPin = 8;    // RELE

//BOLEANOS
bool inputState = false;    // Current state of the input
bool prevInputState = false;  // Previous state of the input

// Function prototypes
void activateRelay();
void turnOffLEDs();

void setup() {
  // Initialize GPIO pins
  pinMode(inputPin, INPUT);
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);  // Turn off the relay initially
}

void loop() {
  // Read the state of the input
  inputState = digitalRead(inputPin);

  // Check if the input state has changed
  if (inputState != prevInputState) {
    // If the input is HIGH, turn on the LEDs and activate the relay
    if (inputState == HIGH) {
      for (int i = 0; i < 5; i++) {
        analogWrite(ledPins[i], 75);
        delay (75);// Turn on all LEDs
      }
      activateRelay();
    }
    // If the input is LOW, turn off the LEDs and the relay
    else {
      turnOffLEDs();
      digitalWrite(relayPin, LOW);
    }
  }

  // Store the current input state as the previous state for the next iteration
  prevInputState = inputState;
}

void activateRelay() {
  digitalWrite(relayPin, HIGH);  // Activate the relay
  delay(1);  // Delay for 1 second
}

void turnOffLEDs() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], LOW);
    delay (50);// Turn off all LEDs
  }
}
