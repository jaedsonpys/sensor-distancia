#define SENSOR_TRIG 2
#define SENSOR_ECHO 3

#define GREEN_LED 8
#define YELLOW_LED 9
#define RED_LED 10

int low = 112;
int medium = low + 112;
int high = low + 112 + 112;

void setup() {
    // setup sensor
    pinMode(SENSOR_TRIG, OUTPUT);
    pinMode(SENSOR_ECHO, INPUT);

    // setup leds
    pinMode(GREEN_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
}

void loop() {
    // read sensor distance
    digitalWrite(SENSOR_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(SENSOR_TRIG, LOW);

    int distance = pulseIn(SENSOR_ECHO, HIGH) / 58;
    
    if(distance <= low){
        digitalWrite(GREEN_LED, HIGH);
    } else {
        digitalWrite(GREEN_LED, LOW);
    }

    if(distance > low and distance <= medium){
        digitalWrite(YELLOW_LED, HIGH);
    } else {
        digitalWrite(YELLOW_LED, LOW);
    }

    if(distance > medium and distance <= high){
        digitalWrite(RED_LED, HIGH);
    } else {
        digitalWrite(RED_LED, LOW);
    }
}