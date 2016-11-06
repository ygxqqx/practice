#include <stdio.h>
#include <stdlib.h>
#include <jansson.h>

// gcc json_parse_demo.c -omain -ljansson

void print_json(json_t *element);

void print_json_object(json_t *element) {
	printf("Object json size:%d\n", json_object_size(element));
	const char *key;
	json_t *value;
	json_object_foreach(element, key, value) {
		printf("%s : ", key);
		print_json(value);
	}
}
void print_json_array(json_t *element) {
	size_t size = json_array_size(element);
	int i;
	for (i=0; i<size; ++i) {
		print_json(json_array_get(element, i));
	}
}
void print_json_string(json_t *element) {
	printf("%s\n", json_string_value(element));
}
void print_json_integer(json_t *element) {
	printf("%d\n", json_integer_value(element));
}
void print_json_real(json_t *element) {
	printf("%f\n", json_real_value(element));
}
void print_json_true(json_t *element) {
	printf("JSON True\n");
}
void print_json_false(json_t *element) {
	printf("JSON False\n");
}
void print_json_null(json_t *element) {
	printf("JSON Null\n");
}

void print_json(json_t *element) {
    switch (json_typeof(element)) {
    case JSON_OBJECT:
        print_json_object(element);
        break;
    case JSON_ARRAY:
        print_json_array(element);
        break;
    case JSON_STRING:
        print_json_string(element);
        break;
    case JSON_INTEGER:
        print_json_integer(element);
        break;
    case JSON_REAL:
        print_json_real(element);
        break;
    case JSON_TRUE:
        print_json_true(element);
        break;
    case JSON_FALSE:
        print_json_false(element);
        break;
    case JSON_NULL:
        print_json_null(element);
        break;
    default:
        fprintf(stderr, "unrecognized JSON type %d\n", json_typeof(element));
    }
}


int main(int argc, char *argv[]) {

    json_t *root;
    json_error_t error;

    root = json_load_file("sftp-config.json", 0, &error);

    if (root) {
        print_json(root);
        json_decref(root);
    }
    return 0;
}
