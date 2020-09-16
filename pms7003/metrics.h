#ifndef __GAUGE_H__
#define __GAUGE_H__

#include <ESP8266WiFi.h>

typedef struct metric_t {
    const char *name;
    const char *help;
    const char *type;
} metric_t;

class Metrics {
    private:
        WiFiClient client;
        const char *host;
        int port;
        const char *job;
        const char *instance;
        
        const metric_t *metrics;
        size_t count;

    public:
        Metrics(const char* host, int port, const char* job, const char* instance, const metric_t metrics[], size_t count);

        void send(float data[]);
};

#endif