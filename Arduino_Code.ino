const int btnA = 2;
const int btnB = 3;
const int btnC = 4;
const int resultBtn = 5;

const int ledA = 8;
const int ledB = 9;
const int ledC = 10;

int votesA = 0;
int votesB = 0;
int votesC = 0;

void setup() {
  pinMode(btnA, INPUT_PULLUP);
  pinMode(btnB, INPUT_PULLUP);
  pinMode(btnC, INPUT_PULLUP);
  pinMode(resultBtn, INPUT_PULLUP);

  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  if (digitalRead(btnA) == LOW) {
    votesA++;
    digitalWrite(ledA, HIGH);
    delay(300);
    digitalWrite(ledA, LOW);
    while(digitalRead(btnA)==LOW);
  }

  if (digitalRead(btnB) == LOW) {
    votesB++;
    digitalWrite(ledB, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    while(digitalRead(btnB)==LOW);
  }

  if (digitalRead(btnC) == LOW) {
    votesC++;
    digitalWrite(ledC, HIGH);
    delay(300);
    digitalWrite(ledC, LOW);
    while(digitalRead(btnC)==LOW);
  }

  if (digitalRead(resultBtn) == LOW) {

    Serial.println("----- RESULT -----");

    Serial.print("Candidate A: ");
    Serial.println(votesA);

    Serial.print("Candidate B: ");
    Serial.println(votesB);

    Serial.print("Candidate C: ");
    Serial.println(votesC);

    if(votesA > votesB && votesA > votesC)
      Serial.println("Winner: Candidate A");

    else if(votesB > votesA && votesB > votesC)
      Serial.println("Winner: Candidate B");

    else if(votesC > votesA && votesC > votesB)
      Serial.println("Winner: Candidate C");

    else
      Serial.println("Result: Tie");

    Serial.println("------------------");

    delay(1000);
  }
}
