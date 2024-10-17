#include <Adafruit_NeoPixel.h>

const int BAUD_RATE				= 9600; 

const int HUM_SENSOR_1 			= A1;
const int HUM_SENSOR_2 			= A2;
const int HUM_SENSOR_3 			= A3;

const int PUMP_1  				= 8;
const int PUMP_2  				= 9;
const int PUMP_3  				= 10;

const long PUMP_ACTIVE_TIME	    = 2000;
const long READING_INTERVAL     = 2000;

const long LOWER_HUM_VAL        = 0;
const long HIGHER_HUM_VAL       = 680;

const long PUMP1_TRIG_VAL       = 400;
const long PUMP2_TRIG_VAL       = 400;
const long PUMP3_TRIG_VAL       = 400;

const int LED_PIN				        = 3;
const int LED_COUNT             = 18;
const int BRIGHTNESS            = 255;

const long SCALE1_FIRST_ID  = 0;
const long SCALE1_LAST_ID   = 5;
const long SCALE2_FIRST_ID  = 6;
const long SCALE2_LAST_ID   = 11;
const long SCALE3_FIRST_ID  = 12;
const long SCALE3_LAST_ID   = 17;

long HUM_SENS_1_READINGS;
long HUM_SENS_2_READINGS;
long HUM_SENS_3_READINGS;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

uint32_t red    = strip.Color(255, 0,  0);
uint32_t green  = strip.Color(0, 255,  0);
uint32_t yellow = strip.Color(255, 255,0);
uint32_t off    = strip.Color(0, 0,0);

int ledScale1;
int ledScale2;
int ledScale3;


void setScale(){
 
  for(int n=0; n<LED_COUNT; n+=6) strip.setPixelColor(n, red);
  for(int n=1; n<LED_COUNT; n+=6) strip.setPixelColor(n, red);
  for(int n=2; n<LED_COUNT; n+=6) strip.setPixelColor(n, yellow);
  for(int n=3; n<LED_COUNT; n+=6) strip.setPixelColor(n, green);
  for(int n=4; n<LED_COUNT; n+=6) strip.setPixelColor(n, green);
  for(int n=5; n<LED_COUNT; n+=6) strip.setPixelColor(n, green);
  
  ledScale1 = map(HUM_SENS_1_READINGS, LOWER_HUM_VAL, HIGHER_HUM_VAL, SCALE1_FIRST_ID, SCALE1_LAST_ID);
  ledScale2 = map(HUM_SENS_2_READINGS, LOWER_HUM_VAL, HIGHER_HUM_VAL, SCALE2_FIRST_ID, SCALE2_LAST_ID);
  ledScale3 = map(HUM_SENS_3_READINGS, LOWER_HUM_VAL, HIGHER_HUM_VAL, SCALE3_FIRST_ID, SCALE3_LAST_ID);

  for(int n=ledScale1;n<=SCALE1_LAST_ID;n++) strip.setPixelColor(n, off);
  for(int n=ledScale2;n<=SCALE2_LAST_ID;n++) strip.setPixelColor(n, off);
  for(int n=ledScale3;n<=SCALE3_LAST_ID;n++) strip.setPixelColor(n, off);
  
  strip.show();
  
}


void readSensors(){
  HUM_SENS_1_READINGS = analogRead(HUM_SENSOR_1);
  HUM_SENS_2_READINGS = analogRead(HUM_SENSOR_2);
  HUM_SENS_3_READINGS = analogRead(HUM_SENSOR_3);
}

void activatePump(int pump){
  digitalWrite(pump,HIGH);
}

void pumpControl(){
 
  bool pump1 = false;
  bool pump2 = false;
  bool pump3 = false;
  
  HUM_SENS_1_READINGS <= PUMP1_TRIG_VAL ? pump1 = true : pump1 = false;
  HUM_SENS_2_READINGS <= PUMP2_TRIG_VAL ? pump2 = true : pump2 = false;
  HUM_SENS_3_READINGS <= PUMP3_TRIG_VAL ? pump3 = true : pump3 = false;
  
  if(pump1){
     activatePump(PUMP_1);
  }
  if(pump2){
     activatePump(PUMP_2);
  }
  if(pump3){
     activatePump(PUMP_3);
  }
  
  delay(PUMP_ACTIVE_TIME);
  digitalWrite(PUMP_1,LOW);
  digitalWrite(PUMP_2,LOW);
  digitalWrite(PUMP_3,LOW);
}


void setup()
{
  //Inicialização da porta série
  Serial.begin(BAUD_RATE);
  
  //Definição dos pinos do arduino
  pinMode(HUM_SENSOR_1, INPUT);
  pinMode(HUM_SENSOR_2, INPUT);
  pinMode(HUM_SENSOR_3, INPUT);
  
  pinMode(PUMP_1, OUTPUT);
  pinMode(PUMP_2, OUTPUT);
  pinMode(PUMP_3, OUTPUT);
  
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
}



void loop()
{
  readSensors();
  setScale();
  pumpControl();
  delay(READING_INTERVAL);
}