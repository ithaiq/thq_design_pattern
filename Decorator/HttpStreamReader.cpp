//
// Created by Mac on 2023/7/28.
//

#include "HttpStreamReader.h"
#include <curl/curl.h>

static size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp) {
    size_t len = size * nmemb;
    auto *hs = (HttpStreamReader *) userp;
    auto *buf = (uint8_t *) buffer;
    for (int i = 0; i < len; i++) {
        hs->cache.push_back(buf[i]);
    }
    return len;
}

int HttpStreamReader::open(const string &url) {
    auto curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    return 0;
}

int HttpStreamReader::close() {
    return 0;
}

int HttpStreamReader::read(uint8_t *buf, int wantLen) {
    int cache_len = cache.size() - pos;
    int len = min(cache_len, wantLen);
    if (len <= 0) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        buf[i] = cache[pos + i];
    }
    pos += len;
    return len;
}
