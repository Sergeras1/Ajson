# Ajson — Легковесная библиотека для генерации JSON на языке C

Ajson — это простая и эффективная библиотека для поэтапного формирования JSON-файлов на языке программирования C. Библиотека предоставляет минималистичный API для создания структурированных JSON-объектов и их сохранения.

## Возможности

- Инициализация и управление контекстом JSON
- Построение объектов с вложенной структурой
- Добавление полей с типами:
  - Строка (`string`)
  - Целое число (`int`)
- Сохранение результата в файл
- Освобождение ресурсов

## API

### Основные функции

```c
/* Инициализирует новый JSON-объект и возвращает указатель на него */
JsonTypedef* json_init();

/* Начинает новый JSON-объект (ставит открывающую фигурную скобку) */
void json_begin_object(JsonTypedef* json);

/* Завершает текущий JSON-объект (ставит закрывающую фигурную скобку) */
void json_end_object(JsonTypedef* json);

/* Добавляет строковое поле ключ-значение в текущий объект */
void json_write_string(JsonTypedef* json, const char* key, const char* value);

/* Добавляет целочисленное поле ключ-значение в текущий объект */
void json_write_int(JsonTypedef* json, const char* key, int value);

/* Сохраняет сформированный JSON в указанный файл */
void json_save_file(JsonTypedef* json, const char* filename);

/* Освобождает память, занятую JSON-объектом */
void json_free(JsonTypedef* json);
```

## Пример использования

```c
#include "ajson.h"

int main(void) {
    /* Инициализация JSON-объекта */
    JsonTypedef* json = json_init();
    
    /* Начало основного объекта */
    json_begin_object(json);
    
    /* Добавление полей */
    json_write_string(json, "name", "Sergey");
    json_write_int(json, "age", 21);
    json_write_string(json, "city", "Moscow");
    
    /* Завершение объекта */
    json_end_object(json);
    
    /* Сохранение в файл */
    json_save_file(json, "user_profile.json");
    
    /* Освобождение ресурсов */
    json_free(json);
    
    return 0;
}
```

Результат (user_profile.json):
```json
{
    "name": "Alex",
    "age": 25,
    "city": "Moscow"
}
```

## Сборка и подключение

1. Скопируйте файлы библиотеки в ваш проект
2. Подключите заголовочный файл:
   ```c
   #include "ajson.h"
   ```
3. Добавьте файлы библиотеки в процесс компиляции

## Требования

- Компилятор C (C99 или новее)
- Стандартная библиотека C

---

*Проект находится в активной разработке. API может изменяться в будущих версиях.*
