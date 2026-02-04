#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Ajson.h"

JsonTypedef* json_init()
{
	JsonTypedef* json = (JsonTypedef*)malloc(sizeof(JsonTypedef));
	if (json == NULL) {
		return 1;
	}
	json->capacity = 1024;
	json->size = 0;
	json->buffer = (char*)malloc(json->capacity);
	if (json->buffer == NULL) {
		free(json);
		return NULL;
	}
	json->buffer[0] = '\0';
	return json;
}

void json_append(JsonTypedef* json, char* str)
{
	size_t len = strlen(str);

	if (json->size + len + 1 >= json->capacity) {
		size_t new_capacity = json->capacity * 2;
		char* new_buffer = (char*)realloc(json->buffer, new_capacity);
		if (!new_buffer) {
			return;
		}
		json->buffer = new_buffer;
		json->capacity = new_capacity;
	}
	strcat(json->buffer, str);
	json->size += len;
}

void json_begin_object(JsonTypedef* json)
{
	if (!json) {
		return;
	}
	json_append(json, "{");
}

void json_end_object(JsonTypedef* json)
{
	if (json->buffer[json->size - 1] == ',') {
		json->buffer[json->size - 1] = '\0';
		json->size--;
	}
	json_append(json, "\n}\n");
}

void json_save_file(JsonTypedef* json, char* filename)
{
	FILE* file = fopen(filename, "w");
	fprintf(file, "%s", json->buffer);
	fclose(file);
}

void json_free(JsonTypedef* json)
{
	if (json->buffer) {
		free(json->buffer);
	}
	free(json);
}

void json_write_string(JsonTypedef* json, const char* key, const char* value)
{
	char buffer[512];

	snprintf(buffer, sizeof(buffer), "\n\"%s\": \"%s\",", key, value);
	json_append(json, buffer);
}

void json_write_int(JsonTypedef* json, const char* key, int value)
{
	char buffer[256];

	snprintf(buffer, sizeof(buffer), "\n\"%s\": %d,", key, value);
	json_append(json, buffer);
}
