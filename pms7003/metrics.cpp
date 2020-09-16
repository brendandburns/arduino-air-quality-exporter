#include  "metrics.h"

Metrics::Metrics(const char* host, int port, const char* job, const char* instance, const metric_t metrics[], size_t count) :
    host(host), port(port), job(job), instance(instance), metrics(metrics), count(count) {
}

void Metrics::send(float data[]) {
    this->client.connect(this->host, this->port);
    char buffer[1024];
    // TODO: instantiate in constructor.
    String url = String("/metrics/job/") + this->job + "/instance/" + this->instance;
    String msg("");
    for (int i = 0; i < this->count; i++) {
        const metric_t &metric = this->metrics[i];
        sprintf(buffer, 
                "# HELP %s %s\n# TYPE %s %s\n%s{} %g\n",
                metric.name, metric.help, metric.name, metric.type, metric.name, data[i]);
        msg += buffer;
    }

    int content_length = msg.length();
    this->client.print(
      "POST " + url + " HTTP/1.1\r\n" +
      "Host: " + this->host + "\r\n" +
      "Connection: close\r\n" +
      "Content-Length: " + String(content_length) + "\r\n" +
      "\r\n" +
      msg);
    this->client.flush();
    // String result = client.readString();
    // Serial.println(result);
    this->client.stop();
}