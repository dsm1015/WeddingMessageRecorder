#include <SD.h>
#include <SPI.h>

// Define pins
const int buttonPin = 2; 
const int micPin = A0; 

// Variables
bool isRecording = false;
String fileName = "recording";
int fileIndex = 0;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Setup button pin
  pinMode(buttonPin, INPUT);

  // Setup SD Card
  if (!SD.begin()) {
    Serial.println("SD Card initialization failed!");
    return;
  }

  // Additional setup if needed
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  
  // Start or stop recording based on button state
  if (buttonState == HIGH && !isRecording) {
    startRecording();
  } else if (buttonState == LOW && isRecording) {
    stopRecording();
  }

  // If recording, read data from microphone and write to file
  if (isRecording) {
    recordAudio();
  }

  delay(10); // Short delay for debouncing
}

void startRecording() {
  isRecording = true;
  fileName += String(fileIndex) + ".wav"; // Creating a new file name
  fileIndex++;

  // Code to start recording
  // Open file on SD card
  File file = SD.open(fileName, FILE_WRITE);
  if (file) {
    Serial.println("Recording started");
    // Additional setup if needed
  } else {
    Serial.println("Error opening file");
  }
}

void recordAudio() {
  // Read data from the microphone
  int micValue = analogRead(micPin);

  // Write the mic data to the SD card
  // This part depends on how you want to format your audio data
}

void stopRecording() {
  isRecording = false;

  // Code to stop recording
  // Close file on SD card
  File file = SD.open(fileName, FILE_WRITE);
  if (file) {
    file.close();
    Serial.println("Recording stopped");
  } else {
    Serial.println("Error closing file");
  }
}
