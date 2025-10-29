# Класс CUser

## Описание
Класс `CUser` представляет базовую информацию о пользователе в системе. Он наследуется от `CSecLabeledObject` и содержит только необходимые атрибуты для хранения данных пользователя.

## Наследование
```
QObject
  └── CSecLabeledObject
        └── CUser
```

## Атрибуты

| Наименование | Тип данных | Примечание |
|--------------|------------|------------|
| `userId` | `qint64` | Первичный ключ |
| `username` | `QString` | Имя пользователя |
| `addDate` | `QDate` | Дата регистрации |
| `rights` | `qint64` | ID мандатной группы |

## Конструкторы

### `CUser(QObject *parent = nullptr)`
Создает пустого пользователя с нулевыми значениями.

### `CUser(qint64 userId, const QString &username, const QDate &addDate, qint64 rights, QObject *parent = nullptr)`
Создает пользователя с указанными параметрами.

**Параметры:**
- `userId` - уникальный идентификатор пользователя
- `username` - имя пользователя
- `addDate` - дата регистрации
- `rights` - ID мандатной группы
- `parent` - родительский объект Qt

## Методы

### Геттеры
- `qint64 getUserId() const` - получить ID пользователя
- `QString getUsername() const` - получить имя пользователя
- `QDate getAddDate() const` - получить дату регистрации
- `qint64 getRights() const` - получить ID мандатной группы

### Сеттеры
- `void setUserId(qint64 userId)` - установить ID пользователя
- `void setUsername(const QString &username)` - установить имя пользователя
- `void setAddDate(const QDate &addDate)` - установить дату регистрации
- `void setRights(qint64 rights)` - установить ID мандатной группы

### Утилитарные методы
- `bool isValid() const` - проверить валидность пользователя
- `QString toString() const` - получить строковое представление

## Сигналы

### `userDataChanged()`
Срабатывает при изменении любого атрибута пользователя.

## Валидация

Пользователь считается валидным, если:
- `userId > 0`
- `username` не пустой

## Пример использования

```cpp
#include "MRBAC/auth/CUser.h"
#include <QDate>

// Создание пользователя
CUser user(1, "john_doe", QDate::currentDate(), 100);

// Получение информации
qDebug() << "ID:" << user.getUserId();
qDebug() << "Username:" << user.getUsername();
qDebug() << "Add Date:" << user.getAddDate().toString("yyyy-MM-dd");
qDebug() << "Rights:" << user.getRights();

// Изменение атрибутов
user.setUsername("jane_doe");
user.setRights(200);

// Подключение к сигналу
QObject::connect(&user, &CUser::userDataChanged, []() {
    qDebug() << "Данные пользователя изменились!";
});
```

## Примечания

- Класс предназначен только для хранения данных пользователя
- Логика аутентификации и авторизации должна быть реализована в отдельных классах
- Все сеттеры автоматически эмитят сигнал `userDataChanged()` при изменении значений
- Наследование от `CSecLabeledObject` обеспечивает интеграцию с системой безопасности
