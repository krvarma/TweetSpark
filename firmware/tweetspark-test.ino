// This #include statement was automatically added by the Spark IDE.
#include "DHT.h"

// This #include statement was automatically added by the Spark IDE.
#include "DHT.h"

#define DHTPIN D4
#define DHTTYPE DHT22  

#define DELAY_BETWEEN_PUBLISH   1500
#define DELAY_PUBLISH           15000

DHT dht(DHTPIN, DHTTYPE);

int temperature = 0;
int humidity = 0;
char szValue[12];

int getDHTTemperature(String args){
    float temp = dht.readTemperature();

    return (int)temp;
}

int getDHTHumidity(String args){
    float humidity = dht.readHumidity();
    
    return (int)humidity;
}

void setup() {
     dht.begin();
     
     Spark.function("gett", getDHTTemperature);
     Spark.function("geth", getDHTHumidity);
     
     Spark.variable("dhtt", &temperature, INT);
     Spark.variable("dhth", &humidity, INT);
}

void loop() {
    temperature = getDHTTemperature(NULL);
    
    sprintf(szValue, "%d", temperature);
    
    Spark.publish("dht-temperature", szValue);
    
    delay(DELAY_BETWEEN_PUBLISH);
    
    humidity = getDHTHumidity(NULL);
    
    sprintf(szValue, "%d", humidity);
    
    Spark.publish("dht-humidity", szValue);
    
    delay(DELAY_PUBLISH);
}