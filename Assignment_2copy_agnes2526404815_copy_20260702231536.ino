//========================================
// Assignment 2 - Task 5
// Beeping Countdown
//========================================

// Segment pins (a,b,c,d,e,f,g)
int segmentPins[] = {2, 3, 4, 5, 6, 7, 9};

// Number of segments
int numSegments = 7;

// Passive buzzer
int buzzerPin = 8;

// Digit patterns (Common Cathode)
byte digits[10][7] = {
  {1,1,1,1,1,1,0}, //0
  {0,1,1,0,0,0,0}, //1
  {1,1,0,1,1,0,1}, //2
  {1,1,1,1,0,0,1}, //3
  {0,1,1,0,0,1,1}, //4
  {1,0,1,1,0,1,1}, //5
  {1,0,1,1,1,1,1}, //6
  {1,1,1,0,0,0,0}, //7
  {1,1,1,1,1,1,1}, //8
  {1,1,1,1,0,1,1}  //9
};

//--------------------------
// Function to display digit
//--------------------------
void showDigit(int number)
{
  for (int i = 0; i < numSegments; i++)
  {
    digitalWrite(segmentPins[i], digits[number][i]);
  }
}

void setup()
{
  Serial.begin(9600);

  pinMode(buzzerPin, OUTPUT);

  // Set all segment pins as OUTPUT
  for (int i = 0; i < numSegments; i++)
  {
    pinMode(segmentPins[i], OUTPUT);
  }

  Serial.println("=== Beeping Countdown Starting ===");

  int count = 9;

  while (count >= 1)
  {
    Serial.print("Counting: ");
    Serial.println(count);

    showDigit(count);

    // Short beep
    tone(buzzerPin, 1000, 200);

    delay(1000);

    count--;
  }

  // Show zero
  showDigit(0);

  // Long completion tone
  tone(buzzerPin, 1500, 1000);

  Serial.println("=== Countdown Complete ===");
}

void loop()
{
  // Empty as required
}

