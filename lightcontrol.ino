// Initialize variables
const int pingPin = 13;
const int echoPin = 12;
const int ledPin = 9;

// Starting Serial Terminal
void setup() {
	Serial.begin(9600);
}


// In a loop, use echoPin to recieve the time duration of a pulse and set brightness of ledPin depending on distance in centimeters
void loop() {

	long duration, cm;

	pinMode(pingPin, OUTPUT);
	digitalWrite(pingPin, LOW);
	delayMicroseconds(100);
	digitalWrite(pingPin, HIGH);
	delayMicroseconds(100);
	digitalWrite(pingPin, LOW);

	pinMode(echoPin, INPUT);

	duration = pulseIn(echoPin, HIGH);

	cm = microsecondsToCentimeters(duration);

	// If distance is higher than 4 cm and unequal to 1368 or 1367 (to avoid problems with these values), set led brightness to cm-value
	if (cm < 5) {
		analogWrite(ledPin, 0);
	} else {
		if (cm != 1368 && cm != 1367) {
			analogWrite(ledPin, cm);
		}
	}

	delay(100);
}

// Calculate distance in centimeters from time duration in microseconds
long microsecondsToCentimeters(long microseconds) {
	return microseconds / 29 / 2;
}
