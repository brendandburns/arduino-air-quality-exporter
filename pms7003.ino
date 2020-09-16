#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PMS.h>
#include "Secret.h"
#include "metrics.h"

#define SAMPLES 10

PMS pms(Serial);
PMS::DATA data;

int* observations = new int[SAMPLES];
int ix = 0;

const char *server = SERVER;
const char *instance = INSTANCE;
int port = 9091;

metric_t metrics[] = {
    {
      name: "ae_pm1_0",
      help: "PM 1.0 Particles",
      type: "gauge",
    },
    {
      name: "ae_pm2_5",
      help: "PM 2.5 Particles",
      type: "gauge",
    },
    {
      name: "ae_pm10_0",
      help: "PM 10.0 Particles",
      type: "gauge",
    },
};
Metrics metrics_client(server, port, "sensor", instance, metrics, 3);

void setup()
{
  Serial.begin(9600);

  WiFi.begin(SSID, PASS);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  if (pms.read(data))
  {
    observations[ix] = data.PM_AE_UG_2_5;
    ix = (ix + 1) % SAMPLES;

    float sum = 0;
    for (int i = 0; i < SAMPLES; i++) {
      sum += observations[ix];
    }
    sum = sum / SAMPLES;

    Serial.print("Average PM2.5:");
    Serial.println(sum);
    Serial.println();

    float values[] = {data.PM_AE_UG_1_0, data.PM_AE_UG_2_5, data.PM_AE_UG_10_0};
    metrics_client.send(values);

    delay(60000);
  }
  // Do other stuff...
}
