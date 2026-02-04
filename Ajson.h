#pragma once

typedef struct {
	char* buffer;
	size_t size;
	size_t capacity;
}JsonTypedef;

JsonTypedef* json_init();
void json_append(JsonTypedef* json, const char* str);
void json_begin_object(JsonTypedef* json);
void json_end_object(JsonTypedef* json);
void json_save_file(JsonTypedef* json, const char* filename);
void json_free(JsonTypedef* json);
void json_write_string(JsonTypedef* json, const char* key, const char* value);
void json_write_int(JsonTypedef* json, const char* key, int value);

